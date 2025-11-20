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

Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
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

Node* inorderSuccessor(Node* root, int key) {
    Node* current = search(root, key);
    
    if (current == NULL) {
        return NULL;
    }
    
    if (current->right != NULL) {
        return findMin(current->right);
    }
    
    Node* successor = NULL;
    Node* ancestor = root;
    
    while (ancestor != current) {
        if (current->data < ancestor->data) {
            successor = ancestor;
            ancestor = ancestor->left;
        } else {
            ancestor = ancestor->right;
        }
    }
    
    return successor;
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
    cout << "Enter node to find successor: ";
    cin >> key;
    
    Node* successor = inorderSuccessor(root, key);
    
    if (successor != NULL) {
        cout << "Inorder successor of " << key << " is " << successor->data << endl;
    } else {
        cout << "No inorder successor found" << endl;
    }
    
    return 0;
}
