#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n;
    bool table[100][100];

    in >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            in >> table[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (table[i][j] != table[j][i]) {
                out << "NO" << endl;
                return 0;
            }
            if (i == j && table[i][j] == 1) {
                out << "NO" << endl;
                return 0;
            }
        }
    }
    out << "YES" << endl;

    in.close();
    out.close();
    return 0;
}