#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
class List
{
private:
    Node<T>* head, * tail;
    int sz = 0;

public:
    List(Node<T>* h = nullptr)
    {
        head = tail = h;
        if (head != nullptr)
            sz = 1;
    }
    // front()	Returns the value of the first element in the list.
    const T& front()
    {
        if (!empty())
            return head->getValue(); // O(1)
        exit(-1);
    }
    // back()	Returns the value of the last element in the list.
    const T& back()
    {
        if (!empty())
            return tail->getValue(); // O(1)
        exit(-1);
    }
    // begin() function returns an iterator pointing to the first element of the list.
    Node<T>* begin()
    {
        return head;
    }
    // end() function returns an iterator pointing to the theoretical last element which follows the last element.
    Node<T>* end()
    {
        return tail;
    }
    // empty() 	Returns whether the list is empty(1) or not(0).
    bool empty()
    {
        return head == nullptr;
    }
    // size()	Returns the number of elements in the list
    const int& size()
    {
        return sz;
    }
    // push_front(g)	Adds a new element ‘g’ at the beginning of the list.
    void push_front(const T& g)
    {                 // O(1)
        Node<T>* n = new Node<T>(g, head); // create node
        head = n;
        if (tail == nullptr) // first element
            tail = head;
        sz++;
        cout << g << " is added to the front\n";
    }
    // push_back(g) 	Adds a new element ‘g’ at the end of the list.   
    void push_back(const T& g) { //O(1)
        //create node
        Node<T>* n = new Node<T>(g);
        if (empty())
            head =  n;
        else {
            tail->setNext(n);          
        } 
        tail = n;
        sz++;
        cout << g << " is added at the end\n";
    }
     // insert()	Inserts new elements in the list before the element at a specified position.
    void insert(const T& g, int& pos) { //O(n) 
        if (!(pos >= 0 && pos < (sz - 1)))
        {
            cout << pos << " is invalid, should be between 0 and " << (sz - 1);
            return;
        }       
        cout << g << " was inserted at pos " << pos << endl;
        if (pos == 0)
            push_front(g);
        else {
            Node <T>* n = new Node<T>(g);
            Node<T>* prev = nullptr, * cur = head;
            while (pos >= 0) {
                prev = cur;
                cur = cur->getNext();
                pos--;
            }
            //change pointers
            prev->setNext(n);
            n->setNext(cur);
            sz++;
        }          
    }
    // pop_front()	Removes the first element of the list, and reduces size of the list by 1. 
    void pop_front() {//O(1)
        if (empty()) {
            cout << "List is already empty\n";
            return;
        }
        cout << front() << " is removed\n"; //head->getValue()
        head = head->getNext();
        //if the list became empty
        if (head == nullptr)
            tail = nullptr;
        sz--;
    }
    // pop_back()	Removes the last element of the list, and reduces size of the list by 1. 
    void pop_back() {
        if (empty()) {
            cout << "List is already empty\n";
            return;
        }
        cout << back() << " is removed\n";
        //if list contains one element
        if (sz == 1) // (head == tail)
            head = tail = nullptr;
        else {
            Node<T>* cur = head;
            while (cur->getNext() != tail)//O(n)
                cur = cur->getNext();
            cur->setNext(nullptr);
            tail = cur;
        }
        sz--;
    }
    // remove()	Removes all the elements from the list, which are equal to given element.
    void remove(const T& val) { //O(n)
        if (empty()) {
            cout << "List is already empty\n";
            return;
        }
        if (sz == 1) { // only 1 element
            if (val == head->getValue()) {
                head = tail = nullptr;
                sz--;
            }
        }
        else {//multiple elements
            Node<T>* prev = nullptr, * cur = head;
            while (cur != nullptr) {//checking all elements in the list
                //check if the cur value is the one to be removed
                if (cur->getValue() == val) {
                    if (prev == nullptr) {
                        head = head->getNext();
                        
                    }
                    else {
                        prev->setNext(cur->getNext());                       
                    }
                    if (cur == tail) {
                        tail = prev;
                    //    prev->setNext(nullptr);
                    }
                sz--;   
                }
                prev = cur;
                cur = cur->getNext();                
            }            
        }
        cout << val << " was deleted\n";
    }
    // clear() function is used to remove all the elements of the list container, thus making it size 0.
    //  should it be used anywhere?
    
    // print() function to print the content of the list 

   

};