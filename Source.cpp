#include <iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Node {
    int data;
    Node* left, * right;
};

class Tree {
private:
    Node* root;

public:
    Tree() {
        root = NULL;
    }

    Node* getRoot() {
        return this->root;
    }

    // A utility function to do inorder traversal of BST
    void inorder(Node* r) {
        if (r != NULL) {
            inorder(r->left);
            cout << r->data << " ";
            inorder(r->right);
        }
    }

    /* A utility function to insert a new node with given key in BST */
    Node* insert(Node* node, int key) {
        Node* newNode = new Node;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->data = key;
        if (this->root == NULL) {
            this->root = newNode;
        }
        /* If the tree is empty, return a new node */
        if (node == NULL) {
            node = newNode;
        }
        /* Otherwise, recur down the tree */
        if (key < node->data)
            node->left = insert(node->left, key);
        else if (key > node->data)
            node->right = insert(node->right, key);

        return node;
    }
    int height(Node* root, int count) {
        if (root != NULL) {
            count++;
            int h1 = height(root->left, count);
            int h2 = height(root->right, count);
            if (h2 > h1)
                return h2;
            return h1;
        }
        return count;
    }
};

int main() {
    Tree T;
    int choice;
    char ch;
    do {
        cout << "Enter number you want to inser "; cin >> choice;
        T.insert(T.getRoot(), choice);
        cout << "Enter y if you want to continue "; cin >> ch;
    } while (ch == 'Y' || ch == 'y');
    cout << "height is "<< T.height(T.getRoot(), 0) << endl;
    T.inorder(T.getRoot());
    cout << endl;
    return 0;
}