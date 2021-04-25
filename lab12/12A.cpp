#include <vector>
#include <fstream>
#include <iostream>
#include <stack>

using namespace std;

int main() {

    int n;
    long long x;
    cin >> n;
    vector<int> arr(n);
    vector<int> len(n);
    vector<int> p(n);
    stack<int> path;

    for (int i = 0; i < n; i++) {
        cin >> x;
        arr[i] = x;
    }

    for (int i = 0; i < n; i++) {
        len[i] = 1;
        p[i] = -1;
        for (int j = 0; j < i; j++)
            if (arr[j] < arr[i])
                if (len[i] < len[j] + 1) {
                    len[i] = len[j] + 1;
                    p[i] = j;
                }
    }

    int pos = 0;
    int result = len[0];

    for (int i = 0; i < n; i++)
        if (len[i] > result) {
            result = len[i];
            pos = i;
        }

    cout << result << endl;

    while (pos != -1) {
        path.push(pos);
        pos = p[pos];
    }

    while (!path.empty()) {
        cout << arr[path.top()] << ' ';
        path.pop();
    }

    return 0;
}