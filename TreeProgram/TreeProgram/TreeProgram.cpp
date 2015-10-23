// TreeProgram.cpp : Defines the entry point for the console application.
// Mike - The tree is mirrored across the Y axis, from the start position. Exactly. So I decided to only store one half of the tree
//Once I'm done, I'll duplicate the left side and reverse all the elements.

#include "stdafx.h"
#include <iostream>
#include <sstream>

using namespace std;


//Initial Class Defines////////////////////////////////////
class Node;
class TreeNode;
class EmptyNode;

class Node {
public:
	virtual void createTree(int level) = 0;
	virtual void reverseTree() = 0;
	virtual void print() = 0;
	virtual void setValue(int val) = 0;
};

class TreeNode : Node{
public:
	Node* left;
	Node* right;
	int value;
	void createTree(int level);
	void reverseTree();
	void print();
	void setValue(int val);
	TreeNode();
	~TreeNode();
};

class EmptyNode : Node {
public:
	void createTree(int level);
	void reverseTree();
	void print();
	void setValue(int val);
	EmptyNode();
	~EmptyNode();
};


//TREE NODE FUNCTIONS//////////////////////////////////////////////
TreeNode::TreeNode() {
	value = 1;
}

//delete the left and right elements, then delete itself
TreeNode::~TreeNode() {
	left->~Node();
	right->~Node();
	delete(this);
}


void TreeNode::createTree(int level) {
	//if level is less than (just in case) or equal to 1, we're done. Create two empty nodes
	if (level <= 1) {
		left = (Node*) new EmptyNode();
		right = (Node*) new EmptyNode();
	}
	//Otherwise, create two nodes for your left and right. Assign them the correct numbers.
	//(which I still need to do, leftVal and rightVal are placeholders for now)
	//Call createNode() on them with one lower level
	//because we just created this level
	else {
		int leftVal = 0;
		int rightVal = 0;

		left = new TreeNode();
		left->setValue(value + leftVal);
		left->createTree(level - 1);

		right = new TreeNode();
		right->setValue(value + rightVal);
		right->createTree(level - 1);
	}
}

//Swap your left and right branches, and then have your children do the same
void TreeNode::reverseTree() {
	Node* n = left;
	left = right;
	right = n;
	left->reverseTree();
	right->reverseTree();
}

//mutator for value
void TreeNode::setValue(int val) {
	value = val;
}

//output your value, then your left node's value, then your right node's value
//uses parenthesis to symbolize a node
void TreeNode::print() {
	//convert the int to a string
	ostringstream oss;
	oss << value;

	cout << "(" + oss.str() + " ";
	left->print();
	right->print();
	cout << ")";
}

//EMPTY NODE FUNCTIONS/////////////////////////////////
//Has no information, so these functions do basically nothing
EmptyNode::EmptyNode() {

}

EmptyNode::~EmptyNode() {
	delete(this);
}

void EmptyNode::createTree(int level) {
	return;
}

void EmptyNode::reverseTree() {
	return;
}

void EmptyNode::print() {
	return;
}

void EmptyNode::setValue(int val) {

}



//MAIN/////////////////////////////////////////////////////
int main()
{
	//Take the user's input for tree levels
	cout << "How many levels for this tree?";
	int levels = 0;
	string input;
	cin >> input;
	levels = atoi(input.c_str());

	//Create the node (if level is 0, then we want an empty one)
	Node* n;
	if (levels == 0)
		n = (Node*) new EmptyNode();
	else 
		n = (Node*) new TreeNode();

	//Create the tree, then print it
	n->createTree(levels);
	n->print();

	//Just for me so the window doesn't exit automatically
	cout << "\n" << "Press any key, then enter to quit";
	cin >> input;
    return 0;
}

