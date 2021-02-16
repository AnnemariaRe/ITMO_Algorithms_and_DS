#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream in("height.in");
    ofstream out("height.out");

    int n, key, left, right;
    in >> n;
    vector<int> node(n, 1);

    for (int i = 0; i < n; i++) {
        in >> key >> left >> right;
        if (left != 0) {
            node[left - 1] = node[i] + 1;
        }
        if (right != 0) {
            node[right - 1] = node[i] + 1;
        }
    }

    int height = 0;
    for (int i = 0; i < n; i++) {
        if (height < node[i] ) {
            height = node[i];
        }
    }
    out << height << endl;
    return 0;
}