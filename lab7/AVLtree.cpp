#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

struct Input {
    int key;
    int left;
    int right;
};

struct Node {
    int key;
    int height;
    Node *left;
    Node *right;

    Node(int key) : key{key}, left{nullptr}, right{nullptr}, height{1} {}
};

Node *root = nullptr;

struct AVL {
    Node *build(vector<Input> &in, int vertex) {
        if (vertex < 0 || in.size() == 0) {
            return nullptr;
        }

        Node *node;
        node = new Node(in[vertex].key);

        node->left = build(in, in[vertex].left);
        node->right = build(in, in[vertex].right);
        node->height = max(this->getHeight(node->left), this->getHeight(node->right)) + 1;

        return node;
    }

    int getHeight(Node *node) {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }

    void fix(Node *node) {
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    }

    Node *balance(Node *node) {
        if (getHeight(node->right) - getHeight(node->left) > 1) {
            if (getHeight(node->right->right) - getHeight(node->right->left) < 0) {
                node->right = rotate(node->right, false);
            }
            return rotate(node, true);
        }

        if (getHeight(node->right) - getHeight(node->left) < -1) {
            if (getHeight(node->left->right) - getHeight(node->left->left) > 0) {
                node->left = rotate(node->left, true);
            }
            return rotate(node, false);
        }

        return node;
    }

    Node *rotate(Node *node, bool isLeft) {
        Node* tmp;
        if (isLeft) {
            tmp = node->right;
        } else {
            tmp = node->left;
        }

        if (isLeft) {
            node->right = tmp->left;
            tmp->left = node;
        } else {
            node->left = tmp->right;
            tmp->right = node;
        }

        fix(node);
        fix(tmp);

        return tmp;
    }

    Node *insert(int key, Node *now) {
        if (now == nullptr) {
            return new Node(key);
        }

        if (key > now->key ? now->right = insert(key, now->right) : now->left = insert(key, now->left));
        fix(now);

        return balance(now);
    }

    void buildTree(vector<Input> &in) {
        root = build(in, 0);
    }

    void insert(int key) {
        root = insert(key, root);
    }
};

int main() {
    ifstream in("addition.in");
    ofstream out("addition.out");

    int n;
    in >> n;
    vector<Input> nodes(n);

    for (int i = 0; i < n; i++) {
        in >> nodes[i].key >> nodes[i].left >> nodes[i].right;
        nodes[i].left--;
        nodes[i].right--;
    }
    int key;
    in >> key;

    AVL a;
    a.buildTree(nodes);
    a.insert(key);

    queue<Node *> q;
    q.push(root);
    int line = 1;
    out << n + 1 << "\n";

    while (!q.empty()) {
        Node *node = q.front();
        q.pop();
        int l = 0, r = 0;

        if (node->left != nullptr) {
            q.push(node->left);
            l = ++line;
        }
        if (node->right != nullptr) {
            q.push(node->right);
            r = ++line;
        }

        out << node->key << " " << (l) << " " << (r) << "\n";
    }

    return 0;
}