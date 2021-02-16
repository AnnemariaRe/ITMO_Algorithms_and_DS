#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

struct Node{
    int key;
    int left;
    int right;
};

vector<Node> tree;
vector<int> height;

struct AVL {

    int dfs(int vertex, int h) {
        if (vertex < 0) {
            return 0;
        }
        height[vertex] = max(dfs(tree[vertex].left, h), dfs(tree[vertex].right, h)) + 1;
        return height[vertex];

    }

    int getHeight(int vertex) {
        if (vertex < 0) {
            return 0;
        }
        return height[vertex];
    }

    void fix(int vertex) {
        height[vertex] = max(getHeight(tree[vertex].left), getHeight(tree[vertex].right)) + 1;
    }

    void pushNode(Node *node) {
        tree.push_back(*node);
        height.push_back(0);
    }

    void calcHeight() {
        dfs(0, 0);
    }

    int rotate_left(int vertex) {
        int x = tree[vertex].right;
        tree[vertex].right = tree[x].left;
        tree[x].left = vertex;
        fix(vertex);
        fix(x);

        return x;
    }

    int rotate_right(int vertex) {
        int x = tree[vertex].left;
        tree[vertex].left = tree[x].right;
        tree[x].right = vertex;
        fix(vertex);
        fix(x);

        return x;
    }

    int rotate(int vertex) {
        int right = tree[vertex].right;
        int child_l = getHeight(tree[right].left);
        int child_r = getHeight(tree[right].right);

        if (child_r - child_l < 0) {
            tree[vertex].right = rotate_right(tree[vertex].right);
            return rotate_left(vertex);
        }

        return rotate_left(vertex);
    }
};

int main() {
    ifstream in("rotation.in");
    ofstream out("rotation.out");

    int n;
    in >> n;
    Node node{};
    AVL a;

    for(int i = 0; i < n; i++) {
        in >> node.key >> node.left >> node.right;
        node.left--;
        node.right--;
        a.pushNode(&node);
    }

    out << n << "\n";

    a.calcHeight();
    int root = a.rotate(0);

    queue<int> q;
    q.push(root);
    int line = 1;

    while(!q.empty()) {
        int vertex = q.front();
        q.pop();
        int l = 0, r = 0;

        if(tree[vertex].left >= 0) {
            q.push(tree[vertex].left);
            l = ++line;
        }
        if(tree[vertex].right >= 0) {
            q.push(tree[vertex].right);
            r = ++line;
        }
        out << tree[vertex].key << " " << (l) << " " << (r) << "\n";
    }

    return 0;
}