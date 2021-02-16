#include <fstream>

using namespace std;
string arr[1000];
string res[1000];
int n, m, k;

void radix_sort(int pos) {
    char abc = 'a';
    int k = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j][pos] == abc) {
                res[k] = arr[j];
                k++;
            }
        }
        abc++;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = res[i];
    }
}

int main() {
    ifstream in("radixsort.in");
    ofstream out("radixsort.out");

    in >> n >> m >> k;

    for (int i = 0; i < n; ++i) {
        in >> arr[i];
    }

    for (int step = m - 1; step >= m - k; step--) {
        radix_sort(step);
    }

    for (int i = 0; i < n; i++) {
        out << arr[i] << endl;
    }

    in.close();
    out.close();
    return 0;
}