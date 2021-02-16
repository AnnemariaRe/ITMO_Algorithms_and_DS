#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector <int> component(100000);
vector <vector <int>> list(100000);
vector <int> comp_number(100000);
bool unused[100000];

void dfs(int x) {
    unused[x] = 0;
    component.push_back(x);

    for (int i = 0; i < list[x].size(); i++) {
        if (unused[list[x][i]])
            dfs(list[x][i]);
    }
}

int find(int n){
    int k = 0;

    for (int i = 0; i < n; i++) {
        unused[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (unused[i]) {
            component.clear();
            dfs(i);

            for (int j = 0; j < component.size(); j++)
                comp_number[component[j]] = k;
            k++;
        }
    }
    return k;
}

int main() {
    ifstream in("components.in");
    ofstream out("components.out");
    int n, m, x, y;

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        list[x - 1].push_back(y - 1);
        list[y - 1].push_back(x - 1);
    }

    cout << find(n) << endl;
    for (int i = 0; i < n; i++)
        cout << comp_number[i] + 1 << ' ';
    cout << endl;

    in.close();
    out.close();
    return 0;
}