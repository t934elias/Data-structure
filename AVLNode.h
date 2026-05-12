#pragma once
#include <iostream>
template <typename T> class AVLNode 
{
private:
    T data;
    AVLNode<T>* left, * right;
    int height;
public:
    AVLNode(T d, AVLNode* ln = NULL, AVLNode* rn = NULL, int h = 1) {
        value = d;
        left = ln;
        right = rn;
        height = h;
    }
    int getHeight() {
        return height;
    }
    void setHeight(int h) {
        height = h;
    }
    //getters
    T getData() { return data; }
    AVLNode<T>* getLeft() { return left; }
    AVLNode<T>* getRight() { return right; }
    //setters
    void setData(T val) { value = val; }
    void setLeft(AVLNode<T>* l) { left = l; }
    void setRight(AVLNode<T>* r) { right = r; }
};
