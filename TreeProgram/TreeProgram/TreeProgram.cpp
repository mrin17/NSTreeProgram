// TreeProgram.cpp : Defines the entry point for the console application.
// Mike - The tree is mirrored across the Y axis, from the start position. Exactly. So I decided to only store one half of the tree
//Once I'm done, I'll duplicate the left side and reverse all the elements.

#include "stdafx.h"

class Node;
class EmptyNode;

class Node {
public: 
	Node* left;
	Node* right;
	int value;
	void createTree(int level);
	void reverseTree();
	Node();
	~Node();
};

class EmptyNode : Node {
public:
	void createTree(int level);
	void reverseTree();
	EmptyNode();
	~EmptyNode();
};



Node::Node() {
	value = 1;
}

Node::~Node() {
	left->~Node();
	right->~Node();
	delete(this);
}

void Node::createTree(int level) {
	if (level <= 1) {
		left = (Node*) new EmptyNode();
		right = (Node*) new EmptyNode();
	}
	else {
		left = new Node();
		left->createTree(level - 1);
		right = new Node();
		right->createTree(level - 1);
	}
}

//Swap your left and right branches, and then have your children do the same
void Node::reverseTree() {
	Node* n = left;
	left = right;
	right = n;
	left->reverseTree();
	right->reverseTree();
}


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




int main()
{
    return 0;
}

