#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;
constexpr int INF = 2000000001;

int main() {
    int n = 0, x = 0, k = -1;
    cin >> n;

    vector<int> arr(n);
    vector<int> len(n + 1);
    vector<int> pos(n + 1, -1);
    vector<int> p(n + 1, -1);
    stack<int> path;

    for (int i = 0; i < n; i++) {
        cin >> x;
        arr[i] = x;
    }

    for (int i = 0; i <= n; i++) {
        if (i == 0) len[i] = -INF;
        else len[i] = INF;
    }

    for (int i = 0; i < n; i++) {
        int j = upper_bound(len.begin(), len.end(), arr[i]) - len.begin();

        if (arr[i] > len[j - 1] && len[j] > arr[i]) {
            len[j] = arr[i];
            pos[j] = i;
            p[i] = pos[j - 1];
            if (k < j) k = j;
        }
    }

    k = pos[k];
    while (k != -1) {
        path.push(arr[k]);
        k = p[k];
    }

    cout << path.size() << endl;

    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }


    return 0;
}