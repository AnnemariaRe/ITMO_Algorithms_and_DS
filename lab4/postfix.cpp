#include <vector>
#include <fstream>

using namespace std;

struct stack {
    vector<int> st;
    int size = 0;

    explicit stack(int n) {
        st.resize(n);
    }
    void push(int val) {
        st[++size] = val;
    }
    int pop() {
        return st[size--];
    }
};

int eval(int a, int b, char operation) {
    if (operation == '+')
        return a + b;
    if (operation == '-')
        return a - b;
    if (operation == '*')
        return a * b;
}

int main() {
    ifstream in("postfix.in");
    ofstream out("postfix.out");

    string expression;
    getline(in, expression);
    stack acc(expression.size());

    for (auto & ch : expression) {
        if (ch == ' ')
            continue;
        if (isdigit(ch))
            acc.push(ch - '0');
        else
            acc.push(eval(acc.pop(), acc.pop(), ch));
    }

    out << acc.pop();
    return 0;
}