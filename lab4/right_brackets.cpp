#include <vector>
#include <fstream>

using namespace std;

struct stack{
    vector<char> st;
    int size = 0;

    explicit stack(int n) {
        st.resize(n);
    }
    void push(char value) {
        st[++size] = value;
    }
    char pop() {
        return st[size--];
    }
    char top() {
        return st[size];
    }
    bool empty() {
        return size == 0;
    }
};

char inv_bracket(char bracket) {
    if (bracket == '[')
        return ']';
    if (bracket == '(')
        return ')';
}

bool check(string line) {
    stack st(line.size());

    for (auto & bracket : line) {
        if (bracket == '(' || bracket == '[')
            st.push(bracket);
        else if (!st.empty() && bracket == inv_bracket(st.top()))
            st.pop();
        else
            return false;
    }

    return st.empty();
}

int main() {
    ifstream in("brackets.in");
    ofstream out("brackets.out");

    string line;
    while (in >> line) {
        out << (check(line) ? "YES" : "NO") << endl;
    }

    return 0;
}