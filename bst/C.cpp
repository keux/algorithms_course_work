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

int main() {
    int a;
    std::cin >> a;
    node *root = crnode(a);
    while (a != 0) {
        insert(root, a);
        std::cin >> a;
    }

    print_tree(root);
    return 0;
}
