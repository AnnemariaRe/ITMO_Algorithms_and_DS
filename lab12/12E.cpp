#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> d;
vector<vector<int>> vertex;
int maxx;

void dfs(int v) {
    d[v][0] = 0;
    d[v][1] = 1;

    for (int u : vertex[v])
        dfs(u);

    for (int u : vertex[v]) {
        d[v][1] += d[u][0];
        d[v][0] += max(d[u][0], d[u][1]);
    }

    if (maxx < d[v][1] || maxx < d[v][0])
        if (d[v][1] <= d[v][0]) maxx = d[v][0];
        else maxx = d[v][1];

}

int main() {
    int n, x;
    cin >> n;

    d.resize(n, vector<int>(2));
    vertex.resize(n, vector<int>());

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x != 0)
            vertex[x - 1].push_back(i);
    }

    for (int i = 0; i < n; i++)
        dfs(i);

    cout << maxx << endl;

    return 0;
}