#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<vector<int>> graph;
vector<vector<int>> invGraph;
vector<int> topsort;
vector<bool> visited;
vector<int> component;
int count = 1;

void dfs(int top) {
    visited[top] = true;
    for (int i = 0; i < graph[top].size(); i++) {
        if (!visited[graph[top][i]])
            dfs(graph[top][i]);
    }
    topsort.push_back(top);
}

void inv_dfs(int top) {
    visited[top] = true;
    component[top] = count;
    for (int i = 0; i < invGraph[top].size(); i++) {
        if (!visited[invGraph[top][i]])
            inv_dfs(invGraph[top][i]);
    }
}

int main() {
    ifstream in("cond.in");
    ofstream out("cond.out");

    int n = 0, m = 0, x = 0, y = 0;
    cin >> n >> m;

    graph.resize(n);
    invGraph.resize(n);
    component.resize(n);
    visited.resize(n, false);

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        graph[x - 1].push_back(y - 1);
        invGraph[y - 1].push_back(x - 1);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    for (int i = 0; i < n; i++)
        visited[i] = false;

    for (int i = 0; i < n; i++) {
        if (!visited[topsort[n - 1 - i]]) {
            inv_dfs(topsort[n - 1 - i]);
            count++;
        }
    }

    cout << count - 1 << endl;
    for (int i = 0; i < n; i++)
        cout << component[i] << " ";

    in.close();
    out.close();
    return 0;
}
