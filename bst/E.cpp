#include <iostream>

typedef struct _node {
    int key;
    struct _node *left, *right, *parent;
} node;

node* crnode(int val) {
    node* n = new node;
    n->key = val;
    n->left = nullptr;
    n->right = nullptr;
    n->parent = nullptr;
    return n;
}

node* insert(node *root, int val) {
    if (nullptr == root)
        root = crnode(val);
    if (val < root->key) {
        if (nullptr == root->left)
            root->left = crnode(val);
        else
            insert(root->left, val);
    }
    if (val > root->key) {
        if (nullptr == root->right)
            root->right = crnode(val);
        else
            insert(root->right, val);
    }
    return root;
}

void print_tree(node *root) {
    if (root != nullptr) {
        print_tree(root->left);
        std::cout << root->key << "\n";
        print_tree(root->right);
    }
}

int height(node *root) {
    int b = 0, c = 0;
    if (root != nullptr) {
        b = height(root->left);
        c = height(root->right);
        return std::max(b, c) + 1;
    } else {
        return 0;
    }
}

int maximum(node *a) {
    while (a->right != nullptr) {
        a = a->right;
    }
    return a->key;
}

void leaves(node *root) {
    if (root != nullptr) {
        leaves(root->left);
        if (root->left == nullptr && root->right == nullptr)
            std::cout << root->key << "\n";
        leaves(root->right);
    }
}

void razvilka(node *root) {
    if (root != nullptr) {
        razvilka(root->left);
        if (root->left != nullptr && root->right != nullptr)
            std::cout << root->key << "\n";
        razvilka(root->right);
    }
}

int main() {
    int a;
    std::cin >> a;
    node *root = crnode(a);
    while (a != 0) {
        insert(root, a);
        std::cin >> a;
    }

    razvilka(root);
    return 0;
}
