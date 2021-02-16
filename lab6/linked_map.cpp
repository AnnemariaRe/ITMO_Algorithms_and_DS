#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Element {
    string x;
    string y;
    Element *next = nullptr;
    Element *prev = nullptr;
};

Element *createElement(string key, string value) {
    Element* node = new Element;

    node->x = key;
    node->y = value;
    node->prev = nullptr;
    node->next = nullptr;

    return node;
}

vector<vector<Element *>> a(1000001, vector<Element *>());
Element* last;
Element* first;

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
        if (a[hash][i]->x == key) {
            a[hash][i]->y = word;
            return;
        }
    }

    Element* newElem = createElement(key, word);
    newElem->prev = last;
    if (last != nullptr) {
        last->next = newElem;
    }
    last = newElem;
    if (first == nullptr) {
        first = newElem;
    }
    a[hash].push_back(newElem);
}

string get(string key) {
    int hash = hashFunction(key);

    for (int i = 0; i < a[hash].size(); i++) {
        if (a[hash][i]->x == key) {
            return a[hash][i]->y;
        }
    }
    return "none";
}

void remove(string key) {
    int hash = hashFunction(key);

    for (int i = 0; i < a[hash].size(); i++) {
        if(a[hash][i]->x == key) {
            if (a[hash][i]->prev != nullptr) {
                a[hash][i]->prev->next = a[hash][i]->next;
            } else {
                first = a[hash][i]->next;
            }
            if (a[hash][i]->next != nullptr) {
                a[hash][i]->next->prev = a[hash][i]->prev;
            } else {
                last = a[hash][i]->prev;
            }
            a[hash].erase(a[hash].begin() + i);
            break;
        }
    }
}

string prev(string key) {
    int hash = hashFunction(key);

    for (int i = 0; i < a[hash].size(); i++) {
        if(a[hash][i]->x == key) {
            if (a[hash][i]->prev != nullptr) {
                return a[hash][i]->prev->y;
            } else {
                return "none";
            }
        }
    }
    return "none";
}

string next(string key) {
    int hash = hashFunction(key);

    for (int i = 0; i < a[hash].size(); i++) {
        if(a[hash][i]->x == key) {
            if (a[hash][i]->next != nullptr) {
                return a[hash][i]->next->y;
            } else {
                return "none";
            }
        }
    }
    return "none";
}

int main() {
    ifstream in("linkedmap.in");
    ofstream out("linkedmap.out");

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
        } else if (operation == "prev") {
            out << prev(key) << endl;
        } else if (operation == "next") {
            out << next(key) << endl;
        }
    }

    return 0;
}