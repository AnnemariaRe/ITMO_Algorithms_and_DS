#include <fstream>
#include <vector>

using namespace std;

struct runner {
    int place;
    string name;
    string country;
};

vector<runner> a;
vector<runner> tmp;

void copy_array(int left, int right) {
    for (int i = left; i < right; ++i) {
        a[i] = tmp[i];
    }
}

void merge(int left, int middle, int right) {
    int i = left;
    int j = middle;

    for (int k = left; k < right; ++k) {
        if (j == right || (i < middle && a[i].country <= a[j].country))
        {
            tmp[k] = a[i];
            i++;
        } else {
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
    ifstream in("race.in");
    ofstream out("race.out");

    int n = 0;
    in >> n;
    a.resize(n);
    tmp.resize(n);

    string country;
    string runner;

    for (int i = 0; i < n; ++i) {
        in >> country >> runner;
        a[i].name = runner;
        a[i].place = i+1;
        a[i].country = country;
    }

    merge_sort(0, n);
    string curr_country;

    for (int i = 0; i < n; i++) {
        if (curr_country != a[i].country) {
            curr_country = a[i].country;
            out << "=== " << a[i].country << " ===" << endl;
        }
        out << a[i].name << endl;
    }

    return 0;
}