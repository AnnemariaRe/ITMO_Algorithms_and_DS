#include <fstream>
#include <vector>

using namespace std;

void med_swap(int &a, int &b, int &c) {
    if (a > c) {
        swap(a, c);
    }
    if (b > c) {
        swap(b, c);
    }
    if (b < a) {
        swap(a, b);
    }
}

int order_statistics(vector<int> &arr, int k) {
    int left = 0;
    int right = arr.size() - 1;
    while (true) {
        if (left + 1 >= right) {
            if (left + 1 == right && arr[left] > arr[right]) {
                swap(arr[left], arr[right]);
            }
            return arr[k];
        }
        med_swap(arr[left], arr[left + 1], arr[right]);
        int l = left + 1;
        int r = right;
        int p = arr[l];
        while (true) {
            do {
                l++;
            } while(arr[l] < p);
            do {
                r--;
            } while(arr[r] > p);
            if (l > r) {
                break;
            }
            swap(arr[l], arr[r]);
        }
        arr[left + 1] = arr[r];
        arr[r] = p;
        if(r <= k) {
            left = l;
        }
        if(r >= k) {
            right = r - 1;
        }
    }
}

int main() {
    ifstream in("kth.in");
    ofstream out("kth.out");

    int n, k;
    in >> n >> k;
    vector<int> arr(n);
    int a, b, c, a1, a2;
    in >> a >> b >> c >> a1 >> a2;

    arr[0] = a1;
    arr[1] = a2;
    for (int i = 2; i < n; ++i) {
        arr[i] = a * arr[i - 2] + b * arr[i - 1] + c;
    }

    out << order_statistics(arr, k - 1) << endl;

    return 0;
}