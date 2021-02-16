#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    ifstream in("antiqs.in");
    ofstream out("antiqs.out");

    int n = 0;
    in >> n;
    int a[n];

    for (int i = 1; i <= n; ++i) {
        a[i-1] = i;
    }

    for (int i = 0; i < n; ++i) {
        swap(a[i], a[i / 2]);
    }

    for (int i = 0; i < n; ++i) {
        out << a[i] << " "<< endl;
    }

    return 0;
}