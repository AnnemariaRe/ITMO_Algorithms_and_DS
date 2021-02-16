#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> a(1000001, vector<int>());

int get_hash(int x) {
    int hash = abs(x % 1000001);
    return hash;
}

bool exists(int num) {
    int hash = get_hash(num);
    for (int i = 0; i < a[hash].size(); i++) {
        if (a[hash][i] == num) {
            return true;
        }
    }
    return false;
}

void insert(int x) {
    int hash = get_hash(x);
    if (!exists(x)) {
        a[hash].push_back(x);
    }
}

void remove(int x) {
    int hash = get_hash(x);
    for (int i = 0; i < a[hash].size(); i++) {
        if (a[hash][i] == x) {
            a[hash].erase(a[hash].begin() + i);
            break;
        }
    }
}

int main() {
    ifstream in("set.in");
    ofstream out("set.out");

    string cmd;
    int num;
    while(in) {
        in >> cmd;
        if(!in.eof()) {
            if (cmd == "insert") {
                in >> num;
                insert(num);
            } else if (cmd == "delete") {
                in >> num;
                remove(num);
            } else if (cmd == "exists") {
                in >> num;
                if (exists(num)) {
                    out << "true\n";
                } else {
                    out << "false\n";
                }
            }
        }
    }
    return 0;
}