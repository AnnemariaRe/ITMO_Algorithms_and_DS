#include <vector>
#include <iostream>

using namespace std;

constexpr long long number = 1000000000;
vector <int> vertex;
vector <vector<long long>> d;

long long calc(int i, int j) {
    if (d[i][j] == -1) {
        if (vertex[i] == vertex[j])
            d[i][j] = (calc(i + 1, j) + calc(i, j - 1) + 1) % number;
        else
            d[i][j] = (calc(i + 1, j) + calc(i, j - 1) - calc(i + 1, j - 1) + number) % number;
    }

    return d[i][j] % number;
}

int main() {
    int n, color;
    cin >> n;

    vertex.resize(n);
    d.resize(n, vector<long long>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                d[i][j] = 1;
            else if (i < j)
                d[i][j] = -1;
            else
                d[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> color;
        vertex[i] = color;
    }

    cout << calc(0, n - 1) % number << endl;


    return 0;
}