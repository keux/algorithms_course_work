#include <iostream>

typedef struct _node {
    int key, freq;
    struct _node *left, *right, *parent;
} node;

node* crnode(int val, node* parent = nullptr) {
    node* n = new node;
    n->key = val;
    n->left = nullptr;
    n->right = nullptr;
    n->parent = parent;
    n->freq = 1;
    return n;
}

node* insert(node *root, int val, node* parent = nullptr) {
    if (!root)
        root = crnode(val, parent);
    if (val < root->key) {
        root->left = insert(root->left, val, root);
    }
    if (val > root->key) {
        root->right = insert(root->right, val, root);
    }
    return root;
}

node* findMax(node* node) {
    return node->right ? findMax(node->right) : node;
}

node* secondMax(node* node) {
    node = findMax(node);
    return node->left ? findMax(node->left) : node->parent;
}

void deleteTree(node* a) {
    if (a) {
        deleteTree(a->left);
        deleteTree(a->right);
        delete a;
    }
}

int main() {
    node* tree = nullptr;

    int num = 0;
    while (std::cin >> num && num != 0)
        tree = insert(tree, num);

    std::cout << secondMax(tree)->key << "\n";

    deleteTree(tree);
    return 0;
}
