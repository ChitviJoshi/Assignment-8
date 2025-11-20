#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

bool searchRecursive(Node* root, int key) {
    if (root == NULL) {
        return false;
    }
    if (root->data == key) {
        return true;
    }
    if (key < root->data) {
        return searchRecursive(root->left, key);
    } else {
        return searchRecursive(root->right, key);
    }
}

bool searchNonRecursive(Node* root, int key) {
    Node* current = root;
    while (current != NULL) {
        if (current->data == key) {
            return true;
        }
        if (key < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return false;
}

void inOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main() {
    Node* root = NULL;
    
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    
    cout << "Binary Search Tree (In-order): ";
    inOrder(root);
    cout << endl << endl;
    
    int key;
    cout << "Enter element to search: ";
    cin >> key;
    
    if (searchRecursive(root, key)) {
        cout << "\nRecursive Search: " << key << " Found in BST" << endl;
    } else {
        cout << "\nRecursive Search: " << key << " NOT Found in BST" << endl;
    }
    
    if (searchNonRecursive(root, key)) {
        cout << "Non-Recursive Search: " << key << " Found in BST" << endl;
    } else {
        cout << "Non-Recursive Search: " << key << " Not Found in BST" << endl;
    }
    
    return 0;
}
