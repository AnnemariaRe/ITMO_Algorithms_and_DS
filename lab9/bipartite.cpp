#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<int> used;
vector<int> multiple;
bool flag = 0;

void bfs(int top) {
    queue<int> q;
    used[top - 1] = 1;
    multiple[top - 1] = 1;
    q.push(top - 1);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int i = 0; i < graph[curr].size(); i++) {
            if (multiple[graph[curr][i]] != multiple[curr]) {
                multiple[graph[curr][i]] = -multiple[curr];
            }
            else
                flag = true;

            if (!used[graph[curr][i]]) {
                q.push(graph[curr][i]);
                used[graph[curr][i]] = 1;
            }
        }
    }
}

int main() {
    ifstream in("bipartite.in");
    ofstream out("bipartite.out");

    int n = 0, m = 0, x = 0, y = 0;
    in >> n >> m;

    graph.resize(n);
    used.resize(n, 0);
    multiple.resize(n, 0);

    for (int i = 0; i < m; i++) {
        in >> x >> y;
        graph[x - 1].push_back(y - 1);
        graph[y - 1].push_back(x - 1);
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            bfs(i + 1);
        }
    }

    if (!flag) {
        out << "YES" << endl;
    }
    else {
        out << "NO" << endl;
    }

    return 0;
}