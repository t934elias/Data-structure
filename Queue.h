#pragma once
#include "Node.h"
template <typename T>
class Queue {
public:
	virtual void enqueue(const T&) = 0;
	virtual const T& dequeue() = 0;
	virtual const T& front() = 0;
	virtual bool empty() = 0;
	virtual int size() = 0;
	virtual void clear() = 0;
};
template <typename T>
class LinkedQueue : public Queue<T> {
private:
	int sz;
	Node<T>* head, * tail;
public:
	LinkedQueue(Node<T>* t = nullptr) {
		head = tail = t;
		if (t != nullptr)
			sz = 1;
		else sz = 0;
	}
	~LinkedQueue() {
		clear();
	}
	//enqueue  O(1)
	void enqueue(const T& val) {
		Node<T> n = new Node(val);
		//check if empty
		if (empty())
			head = n;
		else {
			tail->setNext(n);		
		}
		tail = n;
		sz++;
		cout << val << " was enqueued\n";
	}
	//dequeue O(1)
	const T& dequeue() {
		if (empty()) {
			cout << "Qeueue is already empty\n";
			exit(-1);
		}
		//save the val
		T temp = head->getValue();
		Node<T>* c = head;
		head = head->getNext();
		delete c;
		sz--;
		if (head == nullptr)
			tail = nullptr;
		return temp;
	}
	bool empty() {//O(1)
		return sz == 0;//return head==nullptr
	}
	int size() {//O(1)
		return sz;
	}
	const T& front() {
		return head->getValue(); //check if empty then exit(-1);
	}
	void clear() {//O(n)
		//Node<T>* cur = head;
		while (head != nullptr)
			dequeue();
	}
};