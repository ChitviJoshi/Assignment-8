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

int findMaxRecursive(Node* root) {
    if (root == NULL) {
        return -1;
    }
    if (root->right == NULL) {
        return root->data;
    }
    return findMaxRecursive(root->right);
}

int findMaxNonRecursive(Node* root) {
    if (root == NULL) {
        return -1;
    }
    Node* current = root;
    while (current->right != NULL) {
        current = current->right;
    }
    return current->data;
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
    
    cout << "Tree elements: ";
    inOrder(root);
    cout << endl;
    
    cout << "Maximum element (recursive): " << findMaxRecursive(root) << endl;
    cout << "Maximum element (non-recursive): " << findMaxNonRecursive(root) << endl;
    
    return 0;
}
