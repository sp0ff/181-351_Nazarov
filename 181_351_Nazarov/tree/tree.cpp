#include "pch.h"
#include <iostream>

struct Node {
	int value; // data to be stored
	Node *son, *bro; // pointers to neigbor and lower level
};

class Tree {
	Node *root; // first element of a tree
	Node *x_ptr, *y_ptr; // x points to the last element on the current level
						 // y points to the first element of the current level
public:
	void NewTree(); // function for the constructor (sets all the pointers equal to NULL)
	void DelTree(Node *d); // function for the destructor (recursively deletes the tree
	Tree() { NewTree(); } // constructor
	~Tree() { DelTree(root); } // destructor
	void InsertRoot(int val); // inserts the first value	
	void AddLevel(int val); // adds new level (y axis)
	void AddNext(int val); // adds new element to the current level (x axis)
	void PrintTree(Node *r); // recursively prints the tree
	Node *getRoot() { return root; } // returns root pointer
};
void Tree::NewTree()
{
	x_ptr = y_ptr = root = NULL;
}
void Tree::InsertRoot(int val)
{
	root = new(Node); // now root points to smth
	x_ptr = y_ptr = root; // and other pointers do
	root->value = val; // insert a value
	x_ptr->bro = y_ptr->son = NULL; // set all other pointers NULL
}
void Tree::AddLevel(int val)
{
	y_ptr->son = new(Node); // now an element has a son
	y_ptr = x_ptr = y_ptr->son; // a new level is created
	y_ptr->value = val;
	y_ptr->bro = y_ptr->son = NULL;

}
void Tree::AddNext(int val)
{
	x_ptr->bro = new(Node); // now an element has a bro
	x_ptr = x_ptr->bro;
	x_ptr->value = val;
	x_ptr->bro = x_ptr->son = NULL;
}

void Tree::PrintTree(Node *leaf)
{
	if (!leaf)
		return;
	std::cout << leaf->value << "\t";
	PrintTree(leaf->bro);
	if (leaf->son == NULL && leaf->bro == NULL || // if last on the level
		leaf->son != NULL && leaf->bro == NULL)
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
	int r_val, l_val; // vars for values
	char ch;		// for the interpreter
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