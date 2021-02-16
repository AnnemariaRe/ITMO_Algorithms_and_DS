#include <fstream>
#include <vector>

using namespace std;

int binsearch_right(vector<int> & arr, int x) {
    int left = 0;
    int right = arr.size();

    while (left < right) {
        int middle = (left + right) / 2;
        if (x < arr[middle]) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }
    return arr[left - 1] == x ? left : -1;
}

int binsearch_left(vector<int> & arr, int x) {
    int left = 0;
    int right = arr.size();

    while (left < right) {
        int middle = (left + right) / 2;
        if (x <= arr[middle]) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }
    return arr[left] == x ? left + 1 : -1;
}

int main() {
    ifstream in("binsearch.in");
    ofstream out("binsearch.out");

    int n, m = 0;
    in >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        in >> arr[i];
    }

    in >> m;

    for (int i = 0; i < m; ++i) {
        int x = 0;
        in >> x;
        int leftmost = binsearch_left(arr, x);
        int rightmost = binsearch_right(arr, x);
        out << leftmost << " " << rightmost << endl;
    }
}