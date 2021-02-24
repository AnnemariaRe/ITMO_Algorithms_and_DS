#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

int n = 0, m = 0;
int matrix[102][102];

struct cell {
    cell* left = nullptr;
    cell* right = nullptr;
    cell* up = nullptr;
    cell* down = nullptr;
    string path = "";
    bool unused = true;
    int number = 0;
    int distance = 0;
};

cell* fill_graph (cell graph[]) {
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            if (matrix[i][j] != -1) {
                if (matrix[i][j - 1] != -1) {
                    graph[matrix[i][j]].left = &graph[matrix[i][j - 1]];
                }
                if (matrix[i - 1][j] != -1) {
                    graph[matrix[i][j]].up = &graph[matrix[i - 1][j]];
                }
                if (matrix[i][j + 1] != -1) {
                    graph[matrix[i][j]].right = &graph[matrix[i][j + 1]];
                }
                if (matrix[i + 1][j] != -1) {
                    graph[matrix[i][j]].down = &graph[matrix[i + 1][j]];
                }
            }
        }
    }
    return graph;
}

void bfs (cell* graph, int finish, queue<int> &q) {
    ofstream out("output.txt");

    while (!q.empty()) {
        int current = q.front();
        graph[current].unused = false;
        q.pop();

        if (graph[current].left != nullptr && graph[current].left->unused) {
            graph[current].left->unused = false;
            graph[current].left->distance = graph[current].distance + 1;
            graph[current].left->path = graph[current].path + 'L';
            q.push(graph[current].left->number);
        }
        if (graph[current].right != nullptr && graph[current].right->unused) {
            graph[current].right->unused = false;
            graph[current].right->distance = graph[current].distance + 1;
            graph[current].right->path = graph[current].path + 'R';
            q.push(graph[current].right->number);
        }
        if (graph[current].up != nullptr && graph[current].up->unused) {
            graph[current].up->unused = false;
            graph[current].up->distance = graph[current].distance + 1;
            graph[current].up->path = graph[current].path + 'U';
            q.push(graph[current].up->number);
        }
        if (graph[current].down != nullptr && graph[current].down->unused) {
            graph[current].down->unused = false;
            graph[current].down->distance = graph[current].distance + 1;
            graph[current].down->path = graph[current].path + 'D';
            q.push(graph[current].down->number);
        }
        if (current == finish) {
            out << graph[current].distance << endl;
            out << graph[current].path << endl;
            out.close();
            exit(0);
        }
    }
}

int main() {
    ifstream in("input.txt");

    in >> n >> m;
    for (int i = 0; i < 102; i++) {
        for (int j = 0; j < 102; j++) {
            matrix[i][j] = -1;
        }
    }

    int startRow = 0, startColumn = 0, finishRow = 0, finishColumn = 0, count = 0;
    string str = "";

    for (int i = 0; i < n; i++) {
        in >> str;
        for (int j = 0; j < m; j++) {
            if (str[j] == 'S') {
                matrix[i + 1][j + 1] = count;
                count++;
                startRow = i + 1;
                startColumn = j + 1;
            }
            else if (str[j] == 'T') {
                matrix[i + 1][j + 1] = count;
                count++;
                finishRow = i + 1;
                finishColumn = j + 1;
            }
            else if (str[j] == '.') {
                matrix[i + 1][j + 1] = count;
                count++;
            }
            else if (str[j] == '#') {
                matrix[i + 1][j + 1] = -1;
            }
        }
    }

    cell graph[count];
    for (int i = 0; i < count; i++) {
        graph[i].number = i;
    }

    fill_graph(graph);

    queue<int> q;
    q.push(matrix[startRow][startColumn]);
    int finish = matrix[finishRow][finishColumn];

    bfs(graph, finish, q);

    ofstream out("output.txt");
    out << -1 << endl;
    in.close();
    out.close();
    return 0;
}
