#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n, m, x, y;
    bool table[100][100];

    in >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            table[i][j] = 0;

    for (int i = 0; i < m; i++) {
        in >> x >> y;
        table[x - 1][y - 1] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            out << table[i][j] << ' ';
        out << endl;
    }

    in.close();
    out.close();
    return 0;
}
