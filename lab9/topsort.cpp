#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<char> color;
vector<int> answer;
bool flag = false;

void dfs(int top) {
    color[top] = 'g';

    for (int i = 0; i < graph[top].size(); i++) {
        if (color[graph[top][i]] == 'g') {
            flag = true;
        }
        else {
            if (color[graph[top][i]] == 'w')
                dfs(graph[top][i]);
        }
    }

    color[top] = 'b';
    answer.push_back(top);
}

int main() {
    ifstream in("topsort.in");
    ofstream out("topsort.out");

    int n = 0, m = 0, x = 0, y = 0;
    in >> n >> m;

    graph.resize(n);
    color.resize(n, 'w');

    for (int i = 0; i < m; i++) {
        in >> x >> y;
        graph[x - 1].push_back(y - 1);
    }

    for (int i = 0; i < n; i++) {
        if (color[i] == 'w') {
            dfs(i);
        }
    }

    if (!flag) {
        for (int i = answer.size() - 1; i > -1; i--)
            out << answer[i] + 1 << ' ';
    }
    else out << -1;
    out << endl;

    in.close();
    out.close();
    return 0;
}