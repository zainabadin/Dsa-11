#include <iostream>
using namespace std;

class TNode {
public:
    int data;
    TNode* left;
    TNode* right;

    TNode() : data(0), left(nullptr), right(nullptr) {}
    TNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
    TNode* root;

    BST() : root(nullptr) {}

    void insert(TNode*& node, int val) {
        if (node == nullptr) {
            node = new TNode(val);
            return;
        }
        if (val < node->data)
            insert(node->left, val);
        else
            insert(node->right, val);
    }

    void insert(int val) {
        insert(root, val);
    }

    TNode* findmin(TNode* node) {
        while (node && node->left)
            node = node->left;
        return node;
    }

    void in_orderTraverse(TNode* node) {
        if (!node) return;
        in_orderTraverse(node->left);
        cout << node->data << " ";
        in_orderTraverse(node->right);
    }

    void in_orderTraverse() {
        in_orderTraverse(root);
        cout << endl;
    }

    TNode* searchNode(TNode* node, int val, TNode*& parent) {
        parent = nullptr;
        while (node && node->data != val) {
            parent = node;
            node = (val < node->data) ? node->left : node->right;
        }
        return node;
    }
};

void printPath(TNode* node, int val) {
    while (node) {
        cout << node->data << " ";
        if (node->data == val) break;
        node = (val < node->data) ? node->left : node->right;
    }
    cout << endl;
}

int findMax(TNode* node) {
    while (node && node->right)
        node = node->right;
    return node ? node->data : -1;
}

int findSibling(TNode* parent, int val) {
    if (!parent) return -1;
    if (parent->left && parent->left->data == val)
        return parent->right ? parent->right->data : -1;
    if (parent->right && parent->right->data == val)
        return parent->left ? parent->left->data : -1;
    return -1;
}

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "In-order Traversal: ";
    tree.in_orderTraverse();

    cout << "Path to 40: ";
    printPath(tree.root, 40);

    cout << "Maximum Value: " << findMax(tree.root) << endl;

    TNode* parent = nullptr;
    tree.searchNode(tree.root, 40, parent);
    cout << "Sibling of 40: " << findSibling(parent, 40) << endl;

    return 0;
}
