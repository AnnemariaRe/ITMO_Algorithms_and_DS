#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
constexpr int INF = 31415926535;
using namespace std;

vector <pair <int, int>> field;
vector <vector <int>> graph;
vector <int> min_w;
vector <bool> visited;
int n = 0;

void MST() {
    min_w[0] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++)
            if (!visited[j] && (v == -1 || min_w[j] < min_w[v]))
                v = j;

        visited[v] = true;
        for (int j = 0; j < n; j++)
            if (!visited[j] && graph[v][j] < min_w[j])
                min_w[j] = graph[v][j];
    }
}

int main() {
    ifstream in("spantree.in");
    ofstream out("spantree.out");

    in >> n;

    field.resize(n);
    graph.resize(n, vector<int>(n));
    min_w.resize(n, INF);
    visited.resize(n, false);

    for (int i = 0; i < n; i++)
        in >> field[i].first >> field[i].second;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = pow(field[i].first - field[j].first, 2)
            + pow(field[i].second - field[j].second, 2);

    MST();

    double result = 0;
    for (int i = 0; i < n; i++)
        result += sqrt(min_w[i]);

    out << setprecision(15) << result << endl;

    in.close();
    out.close();
    return 0;
}