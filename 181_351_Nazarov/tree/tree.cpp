#include "pch.h"
#include <iostream>

struct Node {
	int value;
	Node *son, *bro;
};

class Tree {
	Node *root;
	Node *x_ptr, *y_ptr;
public:
	void NewTree();
	void DelTree(Node *d);
	Tree() { NewTree(); }
	~Tree() { DelTree(root); }
	void InsertRoot(int val);
	void AddLevel(int val);
	void AddNext(int val);
	void PrintTree(Node *r);
	Node *getRoot() { return root; }
};

void Tree::NewTree()
{
	x_ptr = y_ptr = root = NULL;
}
void Tree::InsertRoot(int val)
{
	root = new(Node);
	x_ptr = y_ptr = root;
	root->value = val;
	x_ptr->bro = y_ptr->son = NULL;
}
void Tree::AddLevel(int val)
{
	y_ptr->son = new(Node);
	y_ptr = x_ptr = y_ptr->son;
	y_ptr->value = val;
	y_ptr->bro = y_ptr->son = NULL;

}
void Tree::AddNext(int val)
{
	x_ptr->bro = new(Node);
	x_ptr = x_ptr->bro;
	x_ptr->value = val;
	x_ptr->bro = x_ptr->son = NULL;
}
void Tree::PrintTree(Node *leaf)
{
	if (!leaf)
		return;
	std::cout << leaf->value << '\t';
	PrintTree(leaf->bro);
	if (leaf->son == NULL && leaf->bro == NULL || leaf->son != NULL && leaf->bro == NULL)
		std::cout << "\n\n";
	PrintTree(leaf->son);
}
void Tree::DelTree(Node *leaf)
{
	if (leaf != 0)
	{
		DelTree(leaf->bro);
		DelTree(leaf->son);
		free(leaf);
	}
}
int main()
{
	int r_val, l_val;
	char ch;
	std::cout << "Let's build a tree.\n\nPlease, enter a root value: ";
	std::cin >> r_val;
	Tree db;
	db.InsertRoot(r_val);
	std::cout << "\nAdd one more level (value): ";
	std::cin >> l_val;
	db.AddLevel(l_val);
	std::cout << "\nNow you have a tree.\n\nHere's what you can do:\n"
					"(1) add a new value on the current level (N)\n"
					"(2) add a value on a new level (L)\n(3) print the tree (P)\n"
					"(4) Quit (Q)\n";
	while ((ch = getchar()) != EOF) {
		std::cout << "\n> ";
		switch (ch) {
		case 'N':
			std::cout << "Value: ";
			std::cin >> l_val;
			db.AddNext(l_val);
			break;
		case 'L':
			std::cout << "Value: ";
			std::cin >> l_val;
			db.AddLevel(l_val);
			break;
		case 'P':
			std::cout << "This is what you've got:\n\n";
			db.PrintTree(db.getRoot());
			break;
		case 'Q':
			exit(0);
		}
	}
	return 0;
}