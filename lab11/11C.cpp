#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

constexpr long long INF = 2147483647;
vector<vector<pair<int, int>>> graph;
vector<long long> dist;
set<pair<int, int>> q;

void dijkstra(int vertex) {
    dist[vertex] = 0;
    q.insert({ 0, vertex });

    while (!q.empty()) {
        vertex = q.begin()->second;
        q.erase(q.begin());

        for (int i = 0; i < graph[vertex].size(); i++) {
            if (dist[graph[vertex][i].second] > dist[vertex] + graph[vertex][i].first) {
                q.erase({ dist[graph[vertex][i].second], graph[vertex][i].second });
                dist[graph[vertex][i].second] = dist[vertex] + graph[vertex][i].first;
                q.insert({ dist[graph[vertex][i].second], graph[vertex][i].second });
            }
        }
    }


}

int main() {
    ifstream in("pathmgep.in");
    ofstream out("pathmgep.out");

    int n, m, x, y, w;
    cin >> n >> m;
    graph.resize(n);
    dist.resize(n, INF);

    for (int i = 0; i < m; i++) {
        cin >> x >> y >> w;;
        graph[x - 1].push_back({ w, y - 1 });
        graph[y - 1].push_back({ w, x - 1 });
    }

    dijkstra(0);

    for (int i = 0; i < n; i++)
        cout << dist[i] << " ";

    in.close();
    out.close();
    return 0;
}