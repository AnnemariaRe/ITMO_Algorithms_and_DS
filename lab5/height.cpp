#include <fstream>
#include <iostream>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) {
        key = k;
        left = right = nullptr;
    }
};

class BinTree {
    Node* root = nullptr;

    Node* insertKey(Node* node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }
        if (node->key > key) {
            node->left  =  insertKey(node->left, key);
        } else if (node->key < key) {
            node->right = insertKey(node->right, key);
        }
        return node;
    }
    Node* search(Node* node, int key) {
        if (node == nullptr || node->key == key) {
            return node;
        }
        return search((key < node->key) ? node->left : node->right, key);
    }

    int countChildren(Node* node) {
        int count = 0;
        if (node->left != nullptr) {
            count++;
        }
        if (node->right != nullptr) {
            count++;
        }
        return count;
    }
    Node* deleteKey(Node* node, int key) {
        if (node == nullptr) {
            return node;
        }
        if (node->key == key) {
            int children = countChildren(node);
            if (children < 2) {
                if (node->left != nullptr) {
                    node = node->left;
                } else {
                    node = node->right;
                }
            } else {
                Node* right_min = minimum(node->right);
                node->key = right_min->key;
                node->right = deleteKey(node->right, node->key);
            }
        } else {
            if (node->key > key) {
                node->left = deleteKey(node->left, key);
            } else {
                node->right = deleteKey(node->right, key);
            }
        }
        return node;
    }
    Node* minimum(Node* node) {
        if (node->left == nullptr) {
            return node;
        }
        return minimum(node->left);
    }
    Node* next(Node* node, int key) {
        Node* cur_node = node;
        Node* next_node = nullptr;

        while (cur_node != nullptr) {
            if (cur_node->key <= key) {
                cur_node = cur_node->right;
            } else {
                next_node = cur_node;
                cur_node = cur_node->left;
            }
        }
        return next_node;
    }
    Node* prev(Node* node, int key) {
        Node* cur_node = node;
        Node* prev_node = nullptr;
        while (cur_node != nullptr) {
            if (key <= cur_node->key) {
                cur_node = cur_node->left;
            } else {
                prev_node = cur_node;
                cur_node = cur_node->right;
            }
        }

        return prev_node;
    }

public:
    void insert(int key) {
        if (!exists(key)) {
            root = insertKey(root, key);
        }
    }
    bool exists(int key) {
        return search(root, key) != nullptr;
    }
    void remove(int key) {
        if (exists(key)) {
            root = deleteKey(root, key);
        }
    }
    int next(int key) {
        Node* next_node = next(root, key);
        if (next_node == nullptr) {
            return 1000000000;
        }
        return next_node->key;
    }
    int prev(int key) {
        Node* prev_node = prev(root, key);
        if (prev_node == nullptr) {
            return 1000000000;
        }
        return prev_node->key;
    }

};

int main() {
    ifstream in("bstsimple.in");
    ofstream out("bstsimple.out");

    BinTree tree;
    string cmd;
    int key;
    while (in >> cmd) {
        in >> key;
        if (cmd == "insert") {
            tree.insert(key);
        } else if (cmd == "delete") {
            tree.remove(key);
        } else if (cmd == "exists") {
            if (tree.exists(key)) {
                out << "true" << endl;
            } else {
                out << "false" << endl;
            }
        } else if (cmd == "next") {
            int next = tree.next(key);
            if (next < 1000000000) {
                out << next << endl;
            } else {
                out << "none" << endl;
            }
        } else if (cmd == "prev") {
            int prev = tree.prev(key);
            if (prev < 1000000000) {
                out << prev << endl;
            } else {
                out << "none" << endl;
            }
        }
    }

    return 0;
}