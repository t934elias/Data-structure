#pragma once
#include "AVLNode.h"
#include"BST.h"
template <typename T> class AVL : public BST <T> {
public:
    // A helper function to get the height of the tree
    int height(AVLNode<T>* N)
    {
        if (N == NULL)
            return 0;
        return N->getHeight();
    }
    // A helper function to get maximum of two integers
    T max(const T& a, const & b)
    {
        return (a > b) ? a : b;
    }
    //  right rotate subtree rooted with y
    AVLNode<T>* rightRotate(AVLNode<T>* y)
    {
        AVLNode<T>* x =  y->left();
        AVLNode<T>* T2 =   x->right();
        // Perform rotation
        x->setRight(y);
        y->setLeft(T2);
        // Update heights
        y->setHeight(max(height( y->left()), height(y->right())) + 1);
        x->setHeight(max(height( x->left()), height( x->right())) + 1);
        // Return new root
        return x;
    }
    // left rotate subtree rooted with x
    AVLNode<T>* leftRotate(AVLNode<T>* x)
    {
        AVLNode<T>* y =  x->right();
        AVLNode<T>* T2 = y->left();
        // Perform rotation
        y->setLeft(x);
        x->setRight(T2);
        // Update heights
        x->setHeight(max(height( x->left()), height( x->right())) + 1);
        y->setHeight(max(height( y->left()), height( y->right())) + 1);
        // Return new root
        return y;
    }
    // Get Balance factor of node N
    int getBalance(AVLNode<T>* N)
    {
        if (N == NULL)
            return 0;
        return height( N->left()) - height( N->right());
    }
    // Recursive function to insert a key in the subtree rooted with node and returns the new root of the subtree.
    AVLNode<T>* insert(E key)
    {  //1. apply BST insert
        AVLNode<T>* node = (AVLNode<T>*) (BST<T>::insert(key));
        /* 2. Update height of this ancestor node */
        node->setHeight(1 + max(height(node->left()), height(node->right())));
        /* 3. Get the balance factor of this ancestor node to check whether this node became unbalanced */
        int balance = getBalance(node);
        // If this node becomes unbalanced, then there are 4 cases
        if (balance > 1)
        {   // Left Left Case
            if (node->left() != NULL)
                if (key < node->left()->element())
                    return rightRotate(node);
            // Left Right Case
                else //if (key > node->left->element)
                {
                    node->setLeft(leftRotate(node));
                    return rightRotate(node);
                }
        }
        else if (balance < -1) {
            // Right Right Case
            if (node->right() != NULL)
                if (key > node->right()->element())
                    return leftRotate(node);
            // Right Left Case
                else //if (key < node->right->element)
                {
                    node->setRight(rightRotate(node->right()));
                    return leftRotate(node);
                }
        }
        /* return the (unchanged) node pointer */
        return node;
    }
    // Recursive function to delete a node with given key from subtree with  given root. It returns root of the  modified subtree.
    AVLNode<T>* deleteNode(T key)
    {
        // STEP 1: PERFORM STANDARD BST DELETE
        AVLNode<T>* root = BST::remove(key);
        // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
        root->setHeight(1 + max(height(root->left()), height( root->right())));
        // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to check whether this node became unbalanced)
        int balance = getBalance(root),
            leftBalance = getBalance( root->left()),
            rightBalance = getBalance( root->right());
        // If this node becomes unbalanced,then there are 4 cases
        if (balance > 1) {
            // Left Left Case
            if (leftBalance >= 0)
                return rightRotate(root);
            else {  // Left Right Case
                root->setLeft(leftRotate(root->left()));
                return rightRotate(root);
            }
        }
        else if (balance < -1) {
            // Right Right Case
            if (rightBalance <= 0)
                return leftRotate(root);
            // Right Left Case
            else {
                root->setRight(rightRotate( root->right()));
                return leftRotate(root);
            }
        }
        return root;
    }

};
