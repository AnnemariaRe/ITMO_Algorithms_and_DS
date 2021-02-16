#include <fstream>
#include <vector>

using namespace std;

void heapify(vector<int> & arr, int i, int end) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest;

    if (left <= end && arr[left] > arr[i]) {
        largest = left;
    } else {
        largest = i;
    }

    if (right <= end && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, largest, end);
    }
}

void build_heap(vector<int> & arr) {
    for (int i = arr.size() / 2; 0 <= i; --i) {
        heapify(arr, i, arr.size()-1);
    }
}

void heap_sort(vector<int> & arr) {
    build_heap(arr);

    for (int end = arr.size() - 1; 0 < end; ) {
        swap(arr[0], arr[end]);
        --end;
        heapify(arr, 0, end);
    }
}

int main() {
    ifstream input("sort.in");
    ofstream output("sort.out");

    int n;
    input >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        input >> arr[i];
    }

    heap_sort(arr);
    for (auto & item : arr) {
        output << item << " ";
    }

    return 0;
}
