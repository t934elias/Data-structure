// implement the BT Node

#include<iostream>
using namespace std;
#include "BTNode.h"
//preorder traversal
template<typename T>
void preOrder(BTNode<T>* node) {
	//base case
	if (node == nullptr)
		return;
	//operation
	cout << node->getData() << " ";
	//recursive calls
	//move left
	preOrder(node->getLeft());
	//move right
	preOrder(node->getRight());
}
//inOrder traversal
template<typename T>
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
template<typename T>
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
template<typename T>
int countNodes(BTNode<T>* node) {
	//base case
	if (node == nullptr)
		return 0;
	return 1 + countNodes(node->getLeft()) + countNodes(node->getRight());
}
int main() {
	//create a BT
	//  16
   // 43  5

	BTNode<int> root(16, new BTNode<int>(43), new BTNode<int>(5));
	preOrder(&root);//16 43 5
	cout << endl;
	inOrder(&root); //43 16 5
	cout << endl;
	postOrder(&root); //43 5 16
	cout << "\nNumber of nodes:" << countNodes(&root); //3
	return 0;
}