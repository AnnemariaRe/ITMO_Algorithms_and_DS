#include <fstream>
#include <vector>

using namespace std;

struct queue {
    vector<int> q;
    int left = 0;
    int right = 0;

    explicit queue(int size) {
        q.resize(size + 1);
    }
    void push(int value) {
        q[++right] = value;
    }
    int pop() {
        return q[++left];
    }
};

int main() {
    ifstream in("queue.in");
    ofstream out("queue.out");

    int n = 0;
    in >> n;
    queue q(n);

    for (int i = 0; i < n; ++i) {
        string command;
        in >> command;

        if (command == "+") {
            int x = 0;
            in >> x;
            q.push(x);
        }
        else if (command == "-") {
            out << q.pop() << endl;
        }
    }

    return 0;
}