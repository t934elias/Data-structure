#pragma once
template <typename T>
class Stack { //interface // abstract parent class
public:
	//defining operations
	virtual void push(const T& ) = 0;
	virtual const T& pop() = 0;
	virtual bool empty() = 0;
	virtual int size() = 0;
	virtual const  T& top() = 0;
	virtual void clear() = 0;
};
#include<iostream>
using namespace std;
template <typename T>
class ArrayStack : public Stack<T> {//createing a child class of Stack
private:
	int sz, max;
	T* list;
public:
	ArrayStack(const int& n = 20) {//default max capacity is 20
		max = n;
		sz = -1; //sz represents the position of the top element
		list = new T[max];
	}
	~ArrayStack() {
		clear();
	}
	//override
	void push(const T& val) {//O(1)
		sz++;
		if (sz == max)
			cout << "Stack is full\n";
		else {
			list[sz] = val;
			cout << val << " is added\n";
		}
	}
	const T& pop() {//O(1)
		if (empty()) {
			cout << "Stack is already empty\n";
			exit(-1);
		}
		sz--;//changed the position of the top --> logical deletion
		return list[sz + 1]; //gives the old top
	}
	const T& top() {//O(1)
		if (empty()) {
			cout << "Stack is already empty\n";
			exit(-1);
		}
		return list[sz];
	}
	bool empty() {//O(1)
		return sz == -1;
	}
	int size() {
		return sz + 1;
	}
	void clear() {
		//remove the dynamic array created
		delete[] list;
		sz = -1;
	}

};
#include "Node.h"
template <typename T>
class LinkedStack : public Stack<T> {
private:
	int sz;
	Node<T>* tp;
public:
	LinkedStack(Node<T>* n = nullptr) {
		tp = n;
		if (n != nullptr)
			sz = 1;
		else 
			sz = 0;//keep track of nb of elements
	}
	~LinkedStack() {
		clear();
	}
	void push(const T& val) {//O(1)
		//Node<T>* n = new Node(val);
		//n->setNext(tp);
		Node<T>* n = new Node(val,tp);
		tp = n;
		sz++;
	}
	const T& pop() {
		if (empty()) {
			cout << "Stack is empty\n";
			exit(-1);
		}
		T val = tp->getValue();
		Node<T>* t = tp;
		tp = tp->getNext();
		delete t; //remove the old node from memory
		sz--;
		return val;
	}
	const T& top() {
		if (empty()) {
			cout << "Stack is empty\n";
			exit(-1);
		}
		return tp->getValue();
	}
	bool empty() {
		retun sz == 0; // tp==nullptr
	}
	int size() {
		return sz;
	}
	void clear() {
		while (tp != nullptr)
			pop();
		sz = 0;
	}

};