#include <iostream>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    // Private helper functions
    TreeNode* insert(TreeNode* node, int value);
    TreeNode* remove(TreeNode* node, int value);
    TreeNode* findMin(TreeNode* node);
    TreeNode* search(TreeNode* node, int value);
    void displayPreorder(TreeNode* node);
    void displayInorder(TreeNode* node);
    void displayPostorder(TreeNode* node);

public:
    BinarySearchTree() : root(nullptr) {}

    // Public interface
    void insert(int value);
    void remove(int value);
    bool search(int value);
    void displayPreorder();
    void displayInorder();
    void displayPostorder();
};

// Insert a value into the BST
TreeNode* BinarySearchTree::insert(TreeNode* node, int value) {
    if (node == nullptr) {
        return new TreeNode(value);
    }

    if (value < node->data) {
        node->left = insert(node->left, value);
    } else if (value > node->data) {
        node->right = insert(node->right, value);
    }

    return node;
}

void BinarySearchTree::insert(int value) {
    root = insert(root, value);
}

// Remove a value from the BST
TreeNode* BinarySearchTree::remove(TreeNode* node, int value) {
    if (node == nullptr) {
        return nullptr;
    }

    if (value < node->data) {
        node->left = remove(node->left, value);
    } else if (value > node->data) {
        node->right = remove(node->right, value);
    } else {
        // Node with one or no child
        if (node->left == nullptr) {
            TreeNode* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            TreeNode* temp = node->left;
            delete node;
            return temp;
        }

        // Node with two children
        TreeNode* temp = findMin(node->right);
        node->data = temp->data;
        node->right = remove(node->right, temp->data);
    }

    return node;
}

void BinarySearchTree::remove(int value) {
    root = remove(root, value);
}

// Find the minimum value in the BST
TreeNode* BinarySearchTree::findMin(TreeNode* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

// Search for a value in the BST
TreeNode* BinarySearchTree::search(TreeNode* node, int value) {
    if (node == nullptr || node->data == value) {
        return node;
    }

    if (value < node->data) {
        return search(node->left, value);
    } else {
        return search(node->right, value);
    }
}

bool BinarySearchTree::search(int value) {
    return search(root, value) != nullptr;
}

// Display elements of the BST in preorder traversal
void BinarySearchTree::displayPreorder(TreeNode* node) {
    if (node != nullptr) {
        std::cout << node->data << " ";
        displayPreorder(node->left);
        displayPreorder(node->right);
    }
}

void BinarySearchTree::displayPreorder() {
    displayPreorder(root);
    std::cout << std::endl;
}

// Display elements of the BST in inorder traversal
void BinarySearchTree::displayInorder(TreeNode* node) {
    if (node != nullptr) {
        displayInorder(node->left);
        std::cout << node->data << " ";
        displayInorder(node->right);
    }
}

void BinarySearchTree::displayInorder() {
    displayInorder(root);
    std::cout << std::endl;
}

// Display elements of the BST in postorder traversal
void BinarySearchTree::displayPostorder(TreeNode* node) {
    if (node != nullptr) {
        displayPostorder(node->left);
        displayPostorder(node->right);
        std::cout << node->data << " ";
    }
}

void BinarySearchTree::displayPostorder() {
    displayPostorder(root);
    std::cout << std::endl;
}

int main() {
    BinarySearchTree bst;

    // Insert elements
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Display elements in different traversal orders
    std::cout << "Preorder: ";
    bst.displayPreorder();

    std::cout << "Inorder: ";
    bst.displayInorder();

    std::cout << "Postorder: ";
    bst.displayPostorder();

    // Search for elements
    std::cout << "Search for 40: " << (bst.search(40) ? "Found" : "Not found") << std::endl;
    std::cout << "Search for 90: " << (bst.search(90) ? "Found" : "Not found") << std::endl;

    // Remove an element
    bst.remove(30);

    // Display elements after removal
    std::cout << "Inorder after removal: ";
    bst.displayInorder();

    return 0;
}
