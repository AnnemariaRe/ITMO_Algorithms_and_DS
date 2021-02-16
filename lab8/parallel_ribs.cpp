#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n, m, x, y;
    int table[100][100];

    in >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            table[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        in >> x >> y;
        table[x - 1][y - 1] += 1;
        table[y - 1][x - 1] += 1;

        if (table[x - 1][y - 1] > 1) {
            out << "YES" << endl;
            return 0;
        }
    }
    out << "NO" << endl;

    in.close();
    out.close();
    return 0;
}