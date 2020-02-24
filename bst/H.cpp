#include <iostream>

typedef struct _node {
    int key, freq;
    struct _node *left, *right, *parent;
} node;

node* crnode(int val) {
    node* n = new node;
    n->key = val;
    n->left = nullptr;
    n->right = nullptr;
    n->parent = nullptr;
    n->freq = 1;
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
    if (val == root->key)
        root->freq += 1;
    return root;
}

void print_tree(node *root) {
    if (root != nullptr) {
        print_tree(root->left);
        std::cout << root->key << " " << root->freq << "\n";
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

void vetka(node *root) {
    if (root != nullptr) {
        vetka(root->left);
        if ((root->left != nullptr && root->right == nullptr) ||
                (root->left == nullptr && root->right != nullptr))
            std::cout << root->key << "\n";
        vetka(root->right);
    }
}

bool node_ABL(node *a) {
    return (std::abs(height(a->right) - height(a->left)) <= 1);
}

bool isABL(node *root) {
    bool a, b, c;
    if (root != nullptr) {
        a = isABL(root->left);
        b = node_ABL(root);
        c = isABL(root->right);
        return a * b * c;
    } else {
        return true;
    }
}
int main() {
    int a;
    std::cin >> a;
    node *root = crnode(a);
    root->freq = 0;
    while (a != 0) {
        insert(root, a);
        std::cin >> a;
    }

    print_tree(root);
    return 0;
}
