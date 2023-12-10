#include <iostream>
#include <algorithm>

using namespace std;

class AVLNode {
public:
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    AVLNode* root;

    // Private helper functions
    int getHeight(AVLNode* node);
    int getBalanceFactor(AVLNode* node);
    AVLNode* rotateRight(AVLNode* y);
    AVLNode* rotateLeft(AVLNode* x);
    AVLNode* insert(AVLNode* node, int value);
    AVLNode* search(AVLNode* node, int value);

public:
    AVLTree() : root(nullptr) {}

    // Public interface
    void insert(int value);
    bool search(int value);
};

// Get the height of a node
int AVLTree::getHeight(AVLNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

// Get the balance factor of a node
int AVLTree::getBalanceFactor(AVLNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

// Right rotation
AVLNode* AVLTree::rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Left rotation
AVLNode* AVLTree::rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Insert a value into the AVL tree
AVLNode* AVLTree::insert(AVLNode* node, int value) {
    // Standard BST insert
    if (node == nullptr) {
        return new AVLNode(value);
    }

    if (value < node->data) {
        node->left = insert(node->left, value);
    } else if (value > node->data) {
        node->right = insert(node->right, value);
    } else {
        // Duplicate values are not allowed
        return node;
    }

    // Update height of the current node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Get the balance factor
    int balance = getBalanceFactor(node);

    // Left Left Case
    if (balance > 1 && value < node->left->data) {
        return rotateRight(node);
    }

    // Right Right Case
    if (balance < -1 && value > node->right->data) {
        return rotateLeft(node);
    }

    // Left Right Case
    if (balance > 1 && value > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left Case
    if (balance < -1 && value < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void AVLTree::insert(int value) {
    root = insert(root, value);
}

// Search for a value in the AVL tree
AVLNode* AVLTree::search(AVLNode* node, int value) {
    if (node == nullptr || node->data == value) {
        return node;
    }

    if (value < node->data) {
        return search(node->left, value);
    } else {
        return search(node->right, value);
    }
}

bool AVLTree::search(int value) {
    return search(root, value) != nullptr;
}

int main() {
    AVLTree avl;

    // Insert elements
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);

    // Search for elements
    cout << "Search for 20: " << (avl.search(20) ? "Found" : "Not found") << endl;
    cout << "Search for 25: " << (avl.search(25) ? "Found" : "Not found") << endl;

    return 0;
}
