#pragma once
#include "BTNode.h"
template <typename T>
class BST {
private:
	BTNode<T>* root;
	//helper functions
	//add the traversal functions -- helper function
	void preOrder(BTNode<T>* node) {
		if (node == nullptr)
			return;
		cout << node->getData() << " ";
		preOrder(node->getLeft());
		preOrder(node->getRight());
	}
	//find max element recursively
	BTNode<T>* findMax(BTNode<T>* node) {
		//base case
		if (node->getRight() == nullptr)
			return node;
		return findMax(node->getRight());
	}
	//find minimum element recursively
	BTNode<T>* findMin(BTNode<T>* node) { //O(logn) - iterative / recursive
		//base case
		if (node == nullptr)
			return nullptr;
		if (node->getLeft() == nullptr)
			return node;
		return findMin(node->getLeft());
	}
	//inOrder traversal
	
	void inOrder(BTNode<T>* node) {
		//base case
		if (node == nullptr)
			return;
		//move left
		inOrder(node->getLeft());
		//operation
		cout << node->getData() << " ";
		//move right
		inOrder(node->getRight());
	}
	//postOrder traversal	
	void postOrder(BTNode<T>* node) {
		//base case
		if (node == nullptr)
			return;
		//move left
		postOrder(node->getLeft());
		//move right
		postOrder(node->getRight());
		//operation
		cout << node->getData() << " ";
	}
	int countNodes(BTNode<T>* node) {
		//base case
		if (node == nullptr)
			return 0;
		return 1 + countNodes(node->getLeft()) + countNodes(node->getRight());
	}
public:
	//constructor
	BST(BTNode<T>* r = nullptr) {
		root = r;
	}
	~BST() {
		//clear();
	}
	//add a preORder
	void preOrder() {
		//check if empty
		if (empty())
			cout << "BST is empty\n";
		else {
			cout << "BST Elements in preorder traversal:";
			preOrder(root);
			cout << "\n";
		}
	}	
	//add a inOrder
	void inOrder() {
		//check if empty
		if (empty())
			cout << "BST is empty\n";
		else {
			cout << "BST Elements in inorder traversal:";
			inOrder(root);
			cout << "\n";
		}
	}	
	void postOrder() {
		//check if empty
		if (empty())
			cout << "BST is empty\n";
		else {
			cout << "BST Elements in postorder traversal:";
			postOrder(root);
			cout << "\n";
		}
	}
	//count nodes
	int countNodes() {
		return countNodes(root);
	}

	BTNode<T>* findMax() {
		if (empty()) {
			cout << "BST is empty\n";
			return nullptr;
		}
	 return	findMax(root);
	}	
	BTNode<T>* findMin() {
		if (empty()) {
			cout << "BST is empty\n";
			return nullptr;
		}
	 return	findMin(root);
	}
	bool empty() {
		return root == nullptr;
	}
	//insert - returns true if successfully inserted, false if element exists
	// iterative solution
	bool insert(const T& val) {
		//or create the node initially
		//BTNode<T>* n = new BTNode<T>(val);
		if (empty()) {
			root = new BTNode<T>(val); //n
			return true;
		}
		BTNode<T>* cur = root,*parent = nullptr;
		while (cur != nullptr) {
			parent = cur;
			if (cur->getData() == val)
				return false; //already in the tree
			if (cur->getData() < val)
				//move right
				cur = cur->getRight();
			else cur = cur->getLeft();
		}// we got the location at parent
		//check if the element should be placed to left or right
		if (parent->getData() < val)
			parent->setRight(new BTNode<T>(val)); //setRight(n)
		else parent->setLeft(new BTNode<T>(val)); //setLeft(n)
		return true;
	}
	//recursive insertion
	BTNode<T>* insert(const T& val, BTNode<T>* node) {
		if (node == nullptr)
			node= new BTNode<T>(val);
		if (node->getData() > val)
			node->setLeft(insert(val, node->getLeft()));
		if (node->getData() < val)
			node->setRight(insert(val, node->getRight()));
		return node;
	}
	// search - recursive function O(logn)
	BTNode<T>* search(const T& val, BTNode<T>* node) {
		if (node == nullptr) //base case
			return nullptr; //not found if tree has nodes
		//base case: found
		if (node->getData() == val)
			return node;
		//if val is < the node's value --> search left
		if (node->getData() > val)
			return search(val, node->getLeft());
		//in case vall > node's value
		return search(val, node->getRight());
	}
	//clear - O(n) we have to delete all nodes.
	void clear(BTNode<T>* node) {
		if (node == nullptr)
			return;
		clear(node->getLeft());
		clear(node->getRight());
		delete node;
	}
	void clear() {
		clear(root);
	}
	//get root
	BTNode<T>* getRoot() {
		return root;
	}
	//remove
	BTNode<T>* remove(const T& x, BTNode<T>* t) { //returns the  root of updated tree		
		if (t == nullptr)
			return nullptr;
		BTNode<E>* temp;
		if (x < t->getData()())
			t->setLeft(remove(x, t->getLeft()));
		else if (x > t->getData())
			t->setRight(remove(x, t->getRight()));
		else if (t->getLeft() && t->getRight())
		{
			temp = findMin(t->getRight());
			t->setData(temp->getData());
			t->setRight(remove(t->getData(), t->getRight()));
		}
		else
		{
			temp = t;
			if (t->getLeft() == nullptr)
				t = t->getRight();
			else if (t->getRight() == nullptr)
				t = t->getLeft();
			delete temp;
		}
		return t;
	}

};
