#include <iostream>
#include <fstream>
#include <vector>
#include <set>

constexpr int INF = 31415926535;
using namespace std;

int main() {
    ifstream in("spantree3.in");
    ofstream out("spantree3.out");

    int n = 0, m = 0;
    int x = 0, y = 0, w = 0, v = 0;
    in >> n >> m;

    vector <vector<pair <int, int>>> graph(n);
    set <pair <int, int>> q;
    vector <int> min_w(n, INF);
    vector <bool> visited(n, false);

    for (int i = 0; i < m; i++) {
        in >> x >> y >> w;
        graph[x - 1].push_back({ w, y - 1 });
        graph[y - 1].push_back({ w, x - 1 });
    }

    min_w[0] = 0;
    q.insert(make_pair(0, 0));
    while (!q.empty()) {
        v = q.begin()->second;
        q.erase(q.begin());

        for (int j = 0; j < graph[v].size(); j++)
            if (!visited[graph[v][j].second])
                if (graph[v][j].first < min_w[graph[v][j].second]) {
                    q.erase(make_pair(min_w[graph[v][j].second], graph[v][j].second));
                    min_w[graph[v][j].second] = graph[v][j].first;
                    q.insert(make_pair(min_w[graph[v][j].second], graph[v][j].second));
                }

        visited[v] = true;
    }

    long long result = 0;
    for (int i : min_w)
        result += i;

    out << result << endl;

    in.close();
    out.close();
    return 0;
}