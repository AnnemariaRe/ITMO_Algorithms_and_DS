#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<char> color;
vector<int> answer;
int flag = 0;
int cycle = 0;
int start = 0;

void dfs(int top) {
    color[top] = 'g';
    for (int i = 0; i < graph[top].size(); i++) {
        if (color[graph[top][i]] == 'g') {
            start = graph[top][i];
            flag = true;
            cycle = true;
        }
        else if (color[graph[top][i]] == 'w')
            dfs(graph[top][i]);

        if (cycle) {
            answer.push_back(top + 1);
            if (top == start)
                cycle = false;

            color[top] = 'b';
            return;
        }
    }
    color[top] = 'b';
}

int main() {
    ifstream in("cycle.in");
    ofstream out("cycle.out");

    int n = 0, m = 0, x = 0, y = 0;
    in >> n >> m;

    graph.resize(n);
    color.resize(n, 'w');

    for (int i = 0; i < m; i++) {
        in >> x >> y;
        graph[x - 1].push_back(y - 1);
    }

    for (int i = 0; i < n; i++) {
        if (color[i] == 'w' && !flag)
            dfs(i);
    }

    if (flag) {
        out << "YES" << endl;
        for (int j = answer.size() - 1; j > -1; j--) {
            out << answer[j] << ' ';
        }
    }
    else {
        out << "NO" << endl;
    }

    in.close();
    out.close();
    return 0;
}