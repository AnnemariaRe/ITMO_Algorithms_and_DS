#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<bool> game; //1 - win, 0 - loss

void dfs(int top) {
    visited[top] = true;
    int game_status = 0;

    for (int i = 0; i < graph[top].size(); i++) {
        if (!visited[graph[top][i]])
            dfs(graph[top][i]);

        if (game[graph[top][i]] == 0)
            game_status = 1;
    }
    game[top] = game_status;
}

int main() {
    ifstream in("game.in");
    ofstream out("game.out");

    int n = 0, m = 0, x = 0, y = 0, start = 0;

    in >> n >> m >> start;
    graph.resize(n);
    game.resize(n);
    visited.resize(n, 0);

    for (int i = 0; i < m; i++) {
        in >> x >> y;
        graph[x - 1].push_back(y - 1);
    }

    dfs(start - 1);

    if (game[start - 1]) {
        out << "First player wins" << endl;
    }
    else {
        out << "Second player wins" << endl;
    }

    in.close();
    out.close();
    return 0;
}