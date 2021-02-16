#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int left;
    int right;
    int height;
    
    Node() : left{-1}, right{-1}, height{-1} {}
    Node(int left, int right) : left{left}, right{right}, height{-1} {}
};

struct AVLTree {
    vector<Node> a;
    AVLTree(int n) : a{vector<Node>(n)} {}

    int height(int k) {
        if (k == -1) {
            return 0;
        }
        if (this->a[k].height != -1) {
            return this->a[k].height;
        }
        return this->a[k].height = 1 + max(height(this->a[k].left), height(this->a[k].right));
    }

    int balance(int k){
        return height(this->a[k].right) - height(this->a[k].left);
    }
};

int main() {
    ifstream in("balance.in");
    ofstream out("balance.out");

    int n;
    in >> n;
    AVLTree *tree;
    tree = new AVLTree(n);

    int val, left, right, i = 0;
    while (in >> val >> left >> right) {
        tree->a[i] = Node(left - 1, right - 1);
        i++;
    }

    for (int i = 0; i < n; i++){
        out << tree->balance(i) << endl;
    }

    return 0;
}