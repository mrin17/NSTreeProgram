// TreeProgram.cpp : Defines the entry point for the console application.
// Mike - The tree is mirrored across the Y axis, from the start position. Exactly. So I decided to only store one half of the tree
//Once I'm done, I'll duplicate the left side and reverse all the elements.

#include "stdafx.h"
#include <iostream>
#include <sstream>

using namespace std;

class Node;
class TreeNode;
class EmptyNode;

class Node {
public:
	virtual void createTree(int level) = 0;
	virtual void reverseTree() = 0;
	virtual void print() = 0;
};

class TreeNode : Node{
public:
	Node* left;
	Node* right;
	int value;
	void createTree(int level);
	void reverseTree();
	void print();
	TreeNode();
	~TreeNode();
};

class EmptyNode : Node {
public:
	void createTree(int level);
	void reverseTree();
	void print();
	EmptyNode();
	~EmptyNode();
};


//TREE NODE FUNCTIONS//////////////////////////////////////////////
TreeNode::TreeNode() {
	value = 1;
}

TreeNode::~TreeNode() {
	left->~Node();
	right->~Node();
	delete(this);
}

void TreeNode::createTree(int level) {
	if (level <= 1) {
		left = (Node*) new EmptyNode();
		right = (Node*) new EmptyNode();
	}
	else {
		left = new TreeNode();
		left->createTree(level - 1);
		right = new TreeNode();
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

void TreeNode::print() {
	ostringstream oss;
	oss << value;
	cout << "" + oss.str() + " (";
	left->print();
	cout << ") (";
	right->print();
	cout << ")";
}

//EMPTY NODE FUNCTIONS/////////////////////////////////
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




int main()
{
    return 0;
}

