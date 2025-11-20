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

Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int data) {
    if (root == NULL) {
        cout << data << " not found in tree" << endl;
        return root;
    }
    
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            cout << data << " deleted successfully" << endl;
            return NULL;
        } else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            cout << data << " deleted successfully" << endl;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            cout << data << " deleted successfully" << endl;
            return temp;
        } else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
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
    Node* root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);
    root->left->left = createNode(20);
    root->left->right = createNode(40);
    root->right->left = createNode(60);
    root->right->right = createNode(80);
    
    cout << "Tree elements: ";
    inOrder(root);
    cout << endl;
    
    int value;
    cout << "Enter value to delete: ";
    cin >> value;
    root = deleteNode(root, value);
    
    cout << "Tree elements after deletion: ";
    inOrder(root);
    cout << endl;
    
    return 0;
}
```

**Example Output:**
```
Tree elements: 20 30 40 50 60 70 80 
Enter value to delete: 30
30 deleted successfully
Tree elements after deletion: 20 40 50 60 70 80