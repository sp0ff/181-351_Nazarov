#include "pch.h"
#include <iostream>
#include <windows.h>
#include <openssl/conf.h> // OpenSSL config
#include <openssl/evp.h> // crypto functions
#include <openssl/err.h> // errors
#include <openssl/aes.h> // AES implementation
#include <fstream>

#pragma comment(lib,"libcrypto.lib")

int main()
// message --> crypt --> decrypt
{
	std::ifstream plaintext_f;
	std::ofstream ciphertext_f;
	plaintext_f.open("message.txt", std::fstream::in | std::fstream::binary);
	ciphertext_f.open("crypt.txt", std::fstream::out | std::fstream::binary);
	unsigned char *key = (unsigned char *)"0123456789";
	unsigned char *iv = (unsigned char *)"0123456789012345";
	char in_buf[256] = { 0 };
	char out_buf[256] = { 0 };
	int len = 0;
	EVP_CIPHER_CTX *ctx;
	ctx = EVP_CIPHER_CTX_new();
	EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
	plaintext_f.read(in_buf, 256); // reading to buffer
	// encryption cycle:
	while (plaintext_f.gcount() > 0)
	{
		EVP_EncryptUpdate(ctx, (unsigned char *)out_buf, &len,
			(unsigned char *)in_buf, plaintext_f.gcount()); // encrypting...
		ciphertext_f.write((const char *)out_buf, len);
		plaintext_f.read(in_buf, 256);
	}
	EVP_EncryptFinal_ex(ctx, (unsigned char *)out_buf, &len); // finalizing func
	EVP_CIPHER_CTX_free(ctx);
	ciphertext_f.write((const char*)out_buf, len); // write the final block to file
	plaintext_f.close();
	ciphertext_f.close();
	memset(in_buf, 0, 256);
	memset(out_buf, 0, 256);

	std::ifstream crypt_f;
	std::ofstream decrypt_f;
	crypt_f.open("crypt.txt", std::fstream::in | std::fstream::binary);
	decrypt_f.open("decrypt.txt", std::fstream::out | std::fstream::binary);
	ctx = EVP_CIPHER_CTX_new();
	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
	crypt_f.read(in_buf, 256);
	// decryption cycle
	while (crypt_f.gcount() > 0)
	{
		EVP_DecryptUpdate(ctx, (unsigned char *)out_buf, &len,
			(unsigned char *)in_buf, crypt_f.gcount());
		decrypt_f.write((const char *)out_buf, len);
		crypt_f.read(in_buf, 256);
	}
	EVP_DecryptFinal_ex(ctx, (unsigned char *)out_buf, &len);
	decrypt_f.write((const char *)out_buf, len);
	decrypt_f.close();
	crypt_f.close();

	system("pause");
	return 0;
}