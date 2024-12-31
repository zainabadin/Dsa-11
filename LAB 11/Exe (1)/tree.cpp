#include <iostream>
using namespace std;

class TNode {
public:
    int data;
    TNode* left;
    TNode* right;

    TNode() {
        data = 0;
        left = nullptr;
        right = nullptr;
    }

    TNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    TNode* root;

    BST() {
        root = nullptr;
    }

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

    bool search(TNode* node, int val) {
        if (!node) return false;
        if (node->data == val) return true;
        return val < node->data ? search(node->left, val) : search(node->right, val);
    }

    bool search(int val) {
        return search(root, val);
    }

    TNode* findmin(TNode* node) {
        while (node && node->left)
            node = node->left;
        return node;
    }

    void delete_node(TNode*& node, int val) {
        if (!node) return;

        if (val < node->data)
            delete_node(node->left, val);
        else if (val > node->data)
            delete_node(node->right, val);
        else {
            if (!node->left) {
                TNode* temp = node->right;
                delete node;
                node = temp;
            } else if (!node->right) {
                TNode* temp = node->left;
                delete node;
                node = temp;
            } else {
                TNode* temp = findmin(node->right);
                node->data = temp->data;
                delete_node(node->right, temp->data);
            }
        }
    }

    void delete_node(int val) {
        delete_node(root, val);
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
};

int main() {
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "In-order Traversal of the BST: ";
    tree.in_orderTraverse();

    int search_val = 40;
    cout << "Searching for " << search_val << ": " 
         << (tree.search(search_val) ? "Found" : "Not Found") << endl;

    int delete_val = 30;
    cout << "Deleting " << delete_val << " from the BST.\n";
    tree.delete_node(delete_val);

    cout << "In-order Traversal after Deletion: ";
    tree.in_orderTraverse();

    return 0;
}
