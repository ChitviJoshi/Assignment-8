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

Node* findMax(Node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

Node* search(Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

Node* inorderPredecessor(Node* root, int key) {
    Node* current = search(root, key);
    
    if (current == NULL) {
        return NULL;
    }
    
    if (current->left != NULL) {
        return findMax(current->left);
    }
    
    Node* predecessor = NULL;
    Node* ancestor = root;
    
    while (ancestor != current) {
        if (current->data > ancestor->data) {
            predecessor = ancestor;
            ancestor = ancestor->right;
        } else {
            ancestor = ancestor->left;
        }
    }
    
    return predecessor;
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
    
    int key;
    cout << "Enter node to find predecessor: ";
    cin >> key;
    
    Node* predecessor = inorderPredecessor(root, key);
    
    if (predecessor != NULL) {
        cout << "Inorder predecessor of " << key << " is " << predecessor->data << endl;
    } else {
        cout << "No inorder predecessor found" << endl;
    }
    
    return 0;
}
