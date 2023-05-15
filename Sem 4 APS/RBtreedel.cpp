//RB Tree Deletion

#include <iostream>
using namespace std;

// Node structure for RB Tree
struct Node {
    int data;
    char color;
    Node* parent;
    Node* left;
    Node* right;
};

// Function to rotate left
void leftRotate(Node*& root, Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

// Function to rotate right
void rightRotate(Node*& root, Node* x) {
    Node* y = x->left;
    x->left = y->right;
    if (y->right != NULL)
        y->right->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->right)
        x->parent->right = y;
    else
        x->parent->left = y;
    y->right = x;
    x->parent = y;
}

// Function to fix violations after deletion
void RBDeleteFixUp(Node*& root, Node* x) {
    while (x != root && x->color == 'B') {
        if (x == x->parent->left) {
            Node* w = x->parent->right;
            if (w->color == 'R') {
                w->color = 'B';
                x->parent->color = 'R';
                leftRotate(root, x->parent);
                w = x->parent->right;
            }
            if (w->left->color == 'B' && w->right->color == 'B') {
                w->color = 'R';
                x = x->parent;
            }
            else {
                if (w->right->color == 'B') {
                    w->left->color = 'B';
                    w->color = 'R';
                    rightRotate(root, w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = 'B';
                w->right->color = 'B';
                leftRotate(root, x->parent);
                x = root;
            }
        }
        else {
            Node* w = x->parent->left;
            if (w->color == 'R') {
                w->color = 'B';
                x->parent->color = 'R';
                rightRotate(root, x->parent);
                w = x->parent->left;
            }
            if (w->right->color == 'B' && w->left->color == 'B') {
                w->color = 'R';
                x = x->parent;
            }
            else {
                if (w->left->color == 'B') {
                    w->right->color = 'B';
                    w->color = 'R';
                    leftRotate(root, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = 'B';
                w->left->color = 'B';
                rightRotate(root, x->parent);
				x = root;
				}
			}
			x->color = 'B';
	}
	}
	// Function to delete a node from RB Tree
void RBDelete(Node*& root, Node* z) {
Node* y = z;
char y_original_color = y->color;
Node* x;
if (z->left == NULL) {
x = z->right;
if (z->parent == NULL)
root = x;
else if (z == z->parent->left)
z->parent->left = x;
else
z->parent->right = x;
if (x != NULL)
x->parent = z->parent;
delete z;
}
else if (z->right == NULL) {
x = z->left;
if (z->parent == NULL)
root = x;
else if (z == z->parent->left)
z->parent->left = x;
else
z->parent->right = x;
if (x != NULL)
x->parent = z->parent;
delete z;
}
else {
y = z->right;
while (y->left != NULL)
y = y->left;
y_original_color = y->color;
x = y->right;
if (y->parent == z) {
if (x != NULL)
x->parent = y;
}
else {
RBTransplant(root, y, y->right);
y->right = z->right;
y->right->parent = y;
}
RBTransplant(root, z, y);
y->left = z->left;
y->left->parent = y;
y->color = z->color;
delete z;
}
if (y_original_color == 'B')
RBDeleteFixUp(root, x);
}

// Sample main function to demonstrate RB Tree operations
int main() {
Node* root = NULL;
RBInsert(root, 10);
RBInsert(root, 20);
RBInsert(root, 30);
RBInsert(root, 15);
RBInsert(root, 18);
RBInsert(root, 25);

// Print the RB Tree in inorder traversal
cout << "Inorder Traversal: ";
inorderTraversal(root);
cout << endl;

// Delete some nodes from RB Tree
RBDelete(root, root);
RBDelete(root, root->right);
RBDelete(root, root->left);

// Print the RB Tree in inorder traversal after deletion
cout << "Inorder Traversal after Deletion: ";
inorderTraversal(root);
cout << endl;

return 0;
}
