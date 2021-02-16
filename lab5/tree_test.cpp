#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

struct node {
    int key;
    int left = 0;
    int right = 0;
};
vector<node> Tree(0);

bool check(int v, int min, int max) {
    if (Tree[v].left != -1 && Tree[v].key <= Tree[Tree[v].left].key) {
        return false;
    }
    if (Tree[v].right != -1 && Tree[v].key >= Tree[Tree[v].right].key) {
        return false;
    }
    if (Tree[v].key <= min || Tree[v].key >= max) {
        return false;
    }
    if (Tree[v].left != -1) {
        return check(Tree[v].left, min, Tree[v].key);
    }
    if (Tree[v].right != -1) {
        return check(Tree[v].right, Tree[v].key, max);
    }

    return true;
}

int main() {
    ifstream in("check.in");
    ofstream out("check.out");

    int n;
    in >> n;
    Tree.resize(n);
    for (int i = 0; i < n; i++) {
        int key, left, right;
        in >> key >> left >> right;
        Tree[i].key = key;
        Tree[i].left = left - 1;
        Tree[i].right = right - 1;
    }
    bool result = true;
    if (n != 0) {
        result = check(0, -1000000001, 1000000001);
    }
    if (result || n == 0) {
        out << "YES";
    } else {
        out << "NO";
    }

    return 0;
}
