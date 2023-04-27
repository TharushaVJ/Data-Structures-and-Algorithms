#include <iostream>
using namespace std;

struct node {
    int key;
    struct node* left, * right;
};

// Inorder traversal
void traverseInOrder(struct node* root) {
    if (node == NULL) return;
    traverseInOrder(root->left);
    cout << root->key << endl;
    traverseInOrder(root->right);
}

// Insert a node
struct node* insertNode(struct node* node, int key) {
    if (node == NULL) {
        node->key = key;
    }
    else if (key <= node->key) {
        struct node* newNode = new node;
        node->left = insertNode(newNode, key);
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    else if (key > node->key) {
        struct node* newNode = new node;
        node->right = insertNode(newNode, key);
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

// Deleting a node
struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) return root

        //traverse 
        if (key < root->key) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->key) {
            root->right = deleteNode(root->right, key);
        }

    //key found
        else {
            //has no child or 1 child
            if (root->left == NULL) {
                node* temp = root->right;
                root = NULL;
                return temp;
            }
            else if (root->right == NULL) {
                node* temp = root->left;
                root = NULL;
                return temp;
            }

            //has 2 children
            else {
                node* current = root->right;
                //get the minimum in the right sub tree
                while (current->left != NULL) {
                    current = current->left;
                }
                node* temp = current;
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key)
            }
        }
    return root;

}

// Driver code
int main() {
    struct node* root = NULL;

    int operation;
    int operand;
    cin >> operation;

    while (operation != -1) {
        switch (operation) {
        case 1: // insert
            cin >> operand;
            root = insertNode(root, operand);
            cin >> operation;
            break;
        case 2: // delete
            cin >> operand;
            root = deleteNode(root, operand);
            cin >> operation;
            break;
        default:
            cout << "Invalid Operator!\n";
            return 0;
        }
    }

    traverseInOrder(root);
}