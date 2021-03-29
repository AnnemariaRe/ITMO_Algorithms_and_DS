#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<char> color;
vector<int> answer;

void dfs(int top) {
    color[top] = 'g';
    for (int i = 0; i < graph[top].size(); i++) {
        if (color[graph[top][i]] == 'w')
            dfs(graph[top][i]);
    }
    color[top] = 'b';
    answer.push_back(top);
}

bool hamiltonCheck(int n) {
    bool check = true;
    for (int i = 0; i < n - 1; i++) {
        if (check) {
            check = false;
            for (int j = 0; j < graph[answer[n - i - 1]].size(); j++) {
                if (graph[answer[n - i - 1]][j] == answer[n - i - 2]) {
                    check = true;
                }
            }
        }
        else break;
    }
    return check;
}

int main() {
    ifstream in("hamiltonian.in");
    ofstream out("hamiltonian.out");

    int n = 0, m = 0, x = 0, y = 0;
    in >> n >> m;

    graph.resize(n);
    color.resize(n, 'w');

    for (int i = 0; i < m; i++) {
        in >> x >> y;
        graph[x - 1].push_back(y - 1);
    }

    answer.clear();
    for (int i = 0; i < n; i++) {
        if (color[i] == 'w') {
            dfs(i);
        }
    }

    if (hamiltonCheck(n)) {
        out << "YES" << endl;
    }
    else {
        out << "NO" << endl;
    }

    in.close();
    out.close();
    return 0;
}