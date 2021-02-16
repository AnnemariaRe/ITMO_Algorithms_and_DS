#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Element {
    string x;
    string y;
};

vector<vector<Element>> a(1000001, vector<Element>());

int hashFunction(string word) {
    int hash = 0;
    int p = 2;

    for (int i = 0; i < word.size(); i++) {
        int charCode;
        if (word[i] - 'a' >= 0 && word[i] - 'a' <= 25) {
            charCode = word[i] - 'a';
        } else {
            charCode = word[i] - 'A';
        }
        hash = (hash * p + charCode) % a.size();
    }
    return hash;
}

void put(string key, string word) {
    int hash = hashFunction(key);

    for (int i = 0; i < a[hash].size(); i++) {
        if (a[hash][i].x == key) {
            a[hash][i].y = word;
            return;
        }
    }
    Element newElem;
    newElem.x = key;
    newElem.y = word;
    a[hash].push_back(newElem);
}
string get(string key) {
    int hash = hashFunction(key);

    for (int i = 0; i < a[hash].size(); i++) {
        if (a[hash][i].x == key) {
            return a[hash][i].y;
        }
    }
    return "none";
}
void remove(string key) {
    int hash = hashFunction(key);

    for (int i = 0; i < a[hash].size(); i++) {
        if(a[hash][i].x == key) {
            a[hash].erase(a[hash].begin() + i);
            break;
        }
    }
}

int main() {
    ifstream in("map.in");
    ofstream out("map.out");

    while (!in.eof()) {
        string operation, key;
        in >> operation >> key;

        if (operation == "put") {
            string value;
            in >> value;
            put(key, value);
        } else if (operation == "delete") {
            remove(key);
        } else if (operation == "get") {
            out << get(key) << endl;
        }
    }
    return 0;
}