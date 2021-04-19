﻿#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

constexpr long long INF = 2000000000002;
vector<vector<long long>> graph;
vector<long long> dist;
vector<bool> used;
int n, s, f, vertex, x;

long long dijkstra() {
    used.resize(n, false);
    dist.resize(n, INF);
    dist[s] = 0;

    for (int i = 0; i < n; i++) {
        vertex = -1;
        for (int j = 0; j < n; j++)
            if (!used[j] && (vertex == -1 || dist[j] < dist[vertex]))
                vertex = j;

        used[vertex] = true;

        for (int j = 0; j < n; j++)
            if (graph[vertex][j] > 0 && dist[vertex] + graph[vertex][j] < dist[j])
                dist[j] = dist[vertex] + graph[vertex][j];
    }

    return dist[f];
}

int main() {
    ifstream in("pathmgep.in");
    ofstream out("pathmgep.out");

    in >> n >> s >> f;
    s--; f--;
    graph.resize(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            in >> x;
            graph[i].push_back(x);
        }
    }

    long long answer = dijkstra();

    if (answer == INF)
        out << -1;
    else
        out << answer;


    in.close();
    out.close();
    return 0;
}