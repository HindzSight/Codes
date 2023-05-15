// B Tree 

#include<iostream>
#include<vector>

using namespace std;

const int t = 3;  // Minimum degree of the B-Tree

// Node structure for B-Tree
struct BTreeNode {
    int n; // Number of keys in the node
    vector<int> keys; // Keys stored in the node
    vector<BTreeNode*> children; // Pointers to child nodes
    bool leaf; // Is this a leaf node?

    // Constructor for B-Tree Node
    BTreeNode(bool is_leaf) {
        n = 0;
        keys.resize(2*t-1);
        children.resize(2*t);
        leaf = is_leaf;
    }

    // Destructor for B-Tree Node
    ~BTreeNode() {
        keys.clear();
        children.clear();
    }
};

// Function to search a key in B-Tree
BTreeNode* BTreeSearch(BTreeNode* node, int key) {
    int i = 0;
    while (i < node->n && key > node->keys[i]) {
        i++;
    }
    if (node->keys[i] == key) {
        return node;
    }
    if (node->leaf) {
        return NULL;
    }
    return BTreeSearch(node->children[i], key);
}

// Function to create a new B-Tree
BTreeNode* BTreeCreate() {
    BTreeNode* root = new BTreeNode(true);
    return root;
}

// Function to split a child of a node in B-Tree
void BTreeSplitChild(BTreeNode* parent, int index, BTreeNode* child) {
    BTreeNode* new_child = new BTreeNode(child->leaf);
    new_child->n = t - 1;
    for (int j = 0; j < t - 1; j++) {
        new_child->keys[j] = child->keys[j+t];
    }
    if (!child->leaf) {
        for (int j = 0; j < t; j++) {
            new_child->children[j] = child->children[j+t];
        }
    }
    child->n = t - 1;
    for (int j = parent->n; j >= index+1; j--) {
        parent->children[j+1] = parent->children[j];
    }
    parent->children[index+1] = new_child;
    for (int j = parent->n-1; j >= index; j--) {
        parent->keys[j+1] = parent->keys[j];
    }
    parent->keys[index] = child->keys[t-1];
    parent->n++;
}

// Function to insert a key in B-Tree
void BTreeInsertNonFull(BTreeNode* node, int key) {
    int i = node->n - 1;
    if (node->leaf) {
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i+1] = node->keys[i];
            i--;
        }
        node->keys[i+1] = key;
        node->n++;
    }
    else {
        while (i >= 0 && key < node->keys[i]) {
            i--;
        }
        if (node->children[i+1]->n == 2*t-1) {
            BTreeSplitChild(node, i+1, node->children[i+1]);
            if (key > node->keys[i+1]) {
                i++;
            }
        }
        BTreeInsertNonFull(node->children[i+1], key);
    }
}

// Function to insert a key in B-Tree
void BTreeInsert(BTreeNode*& root, int key) {
if (root == NULL) {
root = new BTreeNode(true);
root->keys[0] = key;
root->n = 1;
}
else {
if (root->n == 2t-1) {
BTreeNode new_root = new BTreeNode(false);
new_root->children[0] = root;
BTreeSplitChild(new_root, 0, root);
int i = 0;
if (new_root->keys[0] < key) {
i++;
}
BTreeInsertNonFull(new_root->children[i], key);
root = new_root;
}
else {
BTreeInsertNonFull(root, key);
}
}
}

// Function to print the keys in B-Tree
void BTreePrint(BTreeNode* node) {
int i;
for (i = 0; i < node->n; i++) {
if (!node->leaf) {
BTreePrint(node->children[i]);
}
cout << node->keys[i] << " ";
}
if (!node->leaf) {
BTreePrint(node->children[i]);
}
}

// Main function to test the B-Tree implementation
int main() {
BTreeNode* root = NULL;
// Insert keys
BTreeInsert(root, 10);
BTreeInsert(root, 20);
BTreeInsert(root, 5);
BTreeInsert(root, 6);
BTreeInsert(root, 12);
BTreeInsert(root, 30);
BTreeInsert(root, 7);
BTreeInsert(root, 17);

// Print keys
cout << "Keys in B-Tree: ";
BTreePrint(root);

return 0;
}
