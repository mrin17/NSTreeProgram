// TreeProgram.cpp : Defines the entry point for the console application.
// Mike - The tree is mirrored across the Y axis, from the start position. Exactly. So I decided to only store one half of the tree
//Once I'm done, I'll duplicate the left side and reverse all the elements.
//When a node creates children, it links the left and right. I call these partners
//I know this does not count everything, but there is a good reason for that.
//The resulting diagram looks like this, in ASCII art
//          1
//         / \
//        /   \
//       /     \
//      /       \
//     1---------1
//    / \       / \
//   1---2     2---1
//Nodes also keep track of if they are left or right children, because this matters
//If a Node is a left child, its leftmost neighbor has its value (unless it is a 1, in which case it has no leftmost neighbor)
//If a Node is a left child, its rightmost neighbor has the linked Node's value.
//If a Node is a right child, its leftmost neighbor has the linked Node's value.
//If a Node is a right child, its rightmost neighbor has its value (unless it is a 1, in which case it has no rightmost neighbor)

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
	virtual void setLRstring(string s) = 0;
	virtual void setPartner(Node* p) = 0;
};

class TreeNode : Node{
public:
	Node* left;
	Node* right;
	Node* partner;
	int value;
	string lr;
	void createTree(int level);
	void reverseTree();
	void print();
	void setValue(int val);
	void setLRstring(string s);
	void setPartner(Node* p);
	TreeNode();
	~TreeNode();
};

class EmptyNode : Node {
public:
	void createTree(int level);
	void reverseTree();
	void print();
	void setValue(int val);
	void setLRstring(string s);
	void setPartner(Node* p);
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
	//Call createNode(level - 1) on them
	//because we just created this level
	else {
		int leftVal = 0;
		int rightVal = 0;

		left = new TreeNode();
		left->setValue(value + leftVal);
		left->setLRstring("L");

		right = new TreeNode();
		right->setValue(value + rightVal);
		right->setLRstring("R");

		//set partners when they are created
		left->setPartner(right);
		right->setPartner(left);

		left->createTree(level - 1);
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

//mutator for lr
void TreeNode::setLRstring(string s) {
	lr = s;
}

//mutator for partner
void TreeNode::setPartner(Node* p) {
	partner = p;
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
	return;
}

void EmptyNode::setLRstring(string s) {
	return;
}

void EmptyNode::setPartner(Node* p) {
	return;
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

