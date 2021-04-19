#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

constexpr long long INF = 8000000000000000000;

struct edge {
    int first;
    int second;
    long long weight;
};

vector <edge> edges;
vector <vector<int>> graph;
vector <long long> dist;
vector <bool> visited;
int v, e, s;

void dfs(int i) {
    visited[i] = true;

    for (int j : graph[i])
        if (!visited[j])
            dfs(j);
}

void BelmannFord() {
    dist[s] = 0;

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < e; j++)
            if (dist[edges[j].first] < INF)
                if (dist[edges[j].second] > dist[edges[j].first] + edges[j].weight) {
                    dist[edges[j].second] = max(-INF, dist[edges[j].first] + edges[j].weight);
                }
    }
    for (int i = 0; i < e; i++) {
        if (dist[edges[i].first] != INF && dist[edges[i].second] > dist[edges[i].first] + edges[i].weight)
            dfs(edges[i].second);
    }
}

int main() {
    ifstream in("path.in");
    ofstream out("path.out");

    in >> v >> e >> s;
    s--;

    edges.resize(e);
    graph.resize(v);
    dist.resize(v, INF);
    visited.resize(v, false);

    int x, y;
    long long w;
    for (int i = 0; i < e; i++) {
        in >> x >> y >> w;

        edges[i].first = x - 1;
        edges[i].second = y - 1;
        edges[i].weight = w;

        graph[x - 1].push_back(y - 1);
    }

    BelmannFord();

    for (int i = 0; i < v; i++) {
        if (visited[i])
            out << '-' << endl;
        else if (dist[i] == INF)
            out << '*' << endl;
        else
            out << dist[i] << endl;
    }

    in.close();
    out.close();
    return 0;
}