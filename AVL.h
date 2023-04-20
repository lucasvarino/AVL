#include "Node.h"
#include <iostream>

class AVLTree {
public:
    Node* root;

    AVLTree() {
        root = nullptr;
    }

    ~AVLTree() {
        delete root;
    }

    int height(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }

    int balanceFactor(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return height(node->left) - height(node->right);
    }

    void updateHeight(Node* node) {
        node->height = std::max(height(node->left), height(node->right)) + 1;
    }

    Node* rotateRight(Node* node) {
        Node* left = node->left;
        Node* rightOfLeft = left->right;

        left->right = node;
        node->left = rightOfLeft;

        updateHeight(node);
        updateHeight(left);

        return left;
    }

    Node* rotateLeft(Node* node) {
        Node* right = node->right;
        Node* leftOfRight = right->left;

        right->left = node;
        node->right = leftOfRight;

        updateHeight(node);
        updateHeight(right);

        return right;
    }

    Node* insert(Node* node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }

        if (key < node->key) {
            node->left = insert(node->left, key);
        } else if (key > node->key) {
            node->right = insert(node->right, key);
        } else {
            return node;
        }

        updateHeight(node);

        int balance = balanceFactor(node);

        if (balance > 1 && key < node->left->key) {
            return rotateRight(node);
        }

        if (balance < -1 && key > node->right->key) {
            return rotateLeft(node);
        }

        if (balance > 1 && key > node->left->key) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && key < node->right->key) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    void printInOrder(Node* node) {
        if(node != nullptr) {
        printInOrder(node->left);
        std::cout << node->key << " ";
        printInOrder(node->right);
    }
}

void print() {
    printInOrder(root);
    std::cout << std::endl;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

Node* remove(Node* node, int key) {
    if (node == nullptr) {
        return node;
    }

    if (key < node->key) {
        node->left = remove(node->left, key);
    } else if (key > node->key) {
        node->right = remove(node->right, key);
    } else {
        if (node->left == nullptr || node->right == nullptr) {
            Node* temp = node->left ? node->left : node->right;
            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            } else {
                *node = *temp;
            }
            delete temp;
        } else {
            Node* temp = minValueNode(node->right);
            node->key = temp->key;
            node->right = remove(node->right, temp->key);
        }
    }

    if (node == nullptr) {
        return node;
    }

    updateHeight(node);

    int balance = balanceFactor(node);

    if (balance > 1 && balanceFactor(node->left) >= 0) {
        return rotateRight(node);
    }

    if (balance > 1 && balanceFactor(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && balanceFactor(node->right) <= 0) {
        return rotateLeft(node);
    }

    if (balance < -1 && balanceFactor(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}


};
