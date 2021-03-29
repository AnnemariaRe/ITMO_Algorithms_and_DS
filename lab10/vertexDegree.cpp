#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n = 0, m = 0, x = 0, y = 0;
    in >> n >> m;

    vector<vector<int>> graph(n);

    for (int i = 0; i < m; i++) {
        in >> x >> y;
        graph[x - 1].push_back(y - 1);
        graph[y - 1].push_back(x - 1);
    }

    for (int i = 0; i < n; i++) {
        out << graph[i].size() << " ";
    }

    in.close();
    out.close();
    return 0;
}