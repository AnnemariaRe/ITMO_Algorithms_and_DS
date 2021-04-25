#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<int>> board;
int n, m;

int move(int i, int j) {
    if (i < 1 || j < 1 || i > n || j > m)
        return 0;

    if (i == 1 && j == 1)
        return 1;

    if (board[i][j] != -1)
        return board[i][j];

    board[i][j] = move(i - 2, j - 1) + move(i - 2, j + 1) +
        move(i - 1, j - 2) + move(i + 1, j - 2);

    return board[i][j];
}

int main() {
    ifstream in("knight2.in");
    ofstream out("knight2.out");

    in >> n >> m;

    board.resize(n + 2);
    for (int i = 0; i <= n + 1; i++)
        board[i].resize(m + 2, -1);

    out << move(n, m);

    in.close();
    out.close();
    return 0;
}