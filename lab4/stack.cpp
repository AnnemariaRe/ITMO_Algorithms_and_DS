#include <vector>
#include <fstream>

using namespace std;

struct stack {
    vector<int> st;
    int size = 0;

    explicit stack(int m) {
        st.resize(m + 1);
    }
    void push(int val) {
        st[++size] = val;
    }
    int pop() {
        return st[size--];
    }
};

int main() {
    ifstream in("stack.in");
    ofstream out("stack.out");

    int n = 0;
    in >> n;
    stack a(n);

    for (int i = 0; i < n; ++i) {
        string command;
        in >> command;

        if (command == "+") {
            int x = 0;
            in >> x;
            a.push(x);
        }
        else if (command == "-") {
            out << a.pop() << endl;
        }
    }

    return 0;
}