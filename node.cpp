#include "node.h"

// constructor
Node::Node(int value) {
	data = value;
	left = NULL;
	right = NULL;
}

// destructor
Node::~Node() {
	if (left != NULL) {
		delete left;
		left = NULL;
	}

	if (right != NULL) {
		delete right;
		right = NULL;
	}
}
// use infix to print out
void Node::print() const {
	if (left != NULL) {
		left->print();
	}
	
	cout << data << " ";
	
	if (right != NULL) {
		right->print();
	}
	
	return;
}

// uses prefix to print out visually
void Node::visual() const {
	// print current data
	cout << "[Address] " << this << " [Data] " << data;
	// print left child
	if (left != NULL) {
		cout << " [Left Child] " << left << " " << left->data;
	}
	// print right child
	if (right != NULL) {
		cout << " [Right Child] " << right << " " << right->data;
	}
	
	cout << endl;
	
	// repeat for rest of tree
	if (left != NULL) {
		left->visual();
	}
	
	if (right != NULL) {
		right->visual();
	}
	
	return;
}

// method to insert values into tree
void Node::insert(int value) {

	// if the value is smaller it is left
	if (value < data) {
		
		// if get to the end, make a new node
		if (left == NULL) {
			left = new Node(value);
		} else {
			left->insert(value);
		}
	} else {
		
		if (right == NULL) {
			right = new Node(value);
		} else {
			right->insert(value);
		}
	}
	
	return;
}

Node* Node::remove(int value) {
	
	// first search through tree for where you need to delete
	// go through left side and call recursively
	if (value < data) {
		if (left == NULL) {
			return this;
		}
		
		left = left->remove(value);
		return this;
	}
	
	// go through right side and call itself
	if (value > data) {
		if (right == NULL) {
			return this;
		}
		
		right = right->remove(value);
		return this;
	}
	
	// now we are equal so 3 cases
	
	// no children just delete
	if (left == NULL && right == NULL) {
		delete this;
		return NULL;
	}
	
	// one child case deletion
	if (left == NULL || right == NULL) {
		
		// if the child is on the left then switch and delete
		if (left != NULL) {
			Node* temp = left;
			left = NULL; // so we don't delete it through recursive destructor
			delete this;
			return temp;
		}
		
		// if child on the right switch and delete
		if (right != NULL) {
			Node* temp = right;
			right = NULL; // so we don't delete it through recursive destructor
			delete this;
			return temp;
		}
	}
	
	// two children, go one to the left and all the way down right (going right and then all the way left also works)
	left = left->removeRightmostChild(this);
	
	return this;
}

// this will take in the node that is being deleted and 
Node* Node::removeRightmostChild(Node* node) {
	
	if (right != NULL) {
		right = right->removeRightmostChild(node);
		return this;
	}
	
	// we are now at the rightmost child
	
	node->data = data;
	// remove data - this remove will always be a 0 or 1 child case as we are on far right
	return remove(data);
}