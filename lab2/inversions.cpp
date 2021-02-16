#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> a;
vector<int> tmp;
long long invers = 0;

void copy_array(int left, int right) {
    for (int i = left; i < right; ++i)
    {
        a[i] = tmp[i];
    }
}

void merge(int left, int middle, int right) {
    int i = left;
    int j = middle;

    for (int k = left; k < right; ++k) {
        if (j == right || (i < middle && a[i]<=a[j])) {
            tmp[k] = a[i];
            i++;
        } else {
            invers += middle - i;
            tmp[k] = a[j];
            j++;
        }
    }

    copy_array(left, right);
}

void merge_sort(int left, int right) {
    if (right <= left + 1) {
        return;
    }

    int middle = (left + right) / 2;
    merge_sort(left, middle);
    merge_sort(middle, right);
    merge(left, middle, right);
}
int main() {
    ifstream in("inversions.in");
    ofstream out("inversions.out");

    int n ;
    in >> n;
    a.resize(n);
    tmp.resize(n);

    for (int i = 0; i < n; ++i)
    {
        in >> a[i];
    }
    merge_sort(0, n);
    out << invers << endl;

    return 0;

}
