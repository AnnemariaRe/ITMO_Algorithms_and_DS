#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
    int first;
    int second;
    long long weight;
};

constexpr long long INF = 100000000;
vector<long long> dist;
vector<long long> parent;
vector<edge> graph;
vector<long long> answer;
int v, w, vertex;

bool BelmannFord() {
    for (int i = 0; i < v; i++) {
        vertex = -1;
        for (auto& j : graph)
            if (dist[j.second] > dist[j.first] + j.weight) {
                dist[j.second] = max(-INF, dist[j.first] + j.weight);
                parent[j.second] = j.first;
                vertex = j.second;
            }
    }

    if (vertex == -1)
        return false;
    else {
        int x = vertex;

        for (int i = 0; i < v; i++)
            x = parent[x];

        for (int i = x; ; i = parent[i]) {
            answer.push_back(i);
            if (i == x && answer.size() > 1)
                break;
        }

        reverse(answer.begin(), answer.end());

        return true;
    }
}

int main() {
    ifstream in("negcycle.in");
    ofstream out("negcycle.out");

    in >> v;

    graph.resize(v);
    parent.resize(v, -1);
    dist.resize(v, INF);

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            in >> w;
            graph.push_back({ i, j, w });
        }
    }

    if (BelmannFord()) {
        out << "YES" << endl << answer.size() << endl;
        for (long long i : answer)
            out << i + 1 << ' ';
    }
    else
        out << "NO" << endl;

    in.close();
    out.close();
    return 0;
}