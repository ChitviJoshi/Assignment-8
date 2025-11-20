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
        cout << data << " inserted successfully" << endl;
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    } else {
        cout << data << " already exists, duplicates not allowed" << endl;
    }
    
    return root;
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
    int choice, value;
    
    while (true) {
        cout << "\n1. Insert element" << endl;
        cout << "2. Display tree" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
                break;
                
            case 2:
                cout << "Tree elements: ";
                inOrder(root);
                cout << endl;
                break;
                
            case 3:
                return 0;
                
            default:
                cout << "Invalid choice" << endl;
        }
    }
    
    return 0;
}
