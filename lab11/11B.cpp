#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

constexpr int MAX = 10000;
vector<vector<int>> graph;

void find_min(int v) {
    for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++)
                if (graph[i][j] < graph[i][k] + graph[k][j])
                    continue;
                else
                    graph[i][j] = graph[i][k] + graph[k][j];
        }
    }
}

int main() {
    ifstream in("pathsg.in");
    ofstream out("pathsg.out");

    int v, e, x, y, z;
    cin >> v >> e;

    graph.resize(v, vector<int>(v));

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = MAX;
        }
    }

    for (int i = 0; i < e; i++) {
        cin >> x >> y >> z;
        graph[x - 1][y - 1] = z;
    }

    find_min(v);

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cout << graph[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}