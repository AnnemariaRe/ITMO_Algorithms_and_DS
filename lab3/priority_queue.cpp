#include <fstream>

using namespace std;

int heap_size = 0;
struct Element {
    int value;
    int priority;
};


class priority_queue {

    Element a[100001];

    void down(int i) {
        int l = 2 * i;
        int r = 2 * i + 1;
        int smallest;

        if (l <= heap_size && a[l].value < a[i].value) {
            smallest = l;
        } else {
            smallest = i;
        }
        if (r <= heap_size && a[r].value < a[smallest].value)
            smallest = r;
        if (smallest != i) {
            swap(a[i], a[smallest]);
            down(smallest);
        }
    }

public:
    int extract_min() {
        int min = a[1].value;
        a[1] = a[heap_size];
        heap_size--;
        down(1);
        return min;
    }

    void push(int key, int new_value) {
        heap_size++;
        a[heap_size].value = 1000000000;
        a[heap_size].priority = new_value;
        decrease_key(key, heap_size);
    }

    void decrease_key(int new_value, int key) {
        bool flag = true;
        int parent = key / 2;
        if (a[key].value < new_value) {
            flag = false;
        }
        if (flag) {
            a[key].value = new_value;
            while (key > 1 && a[parent].value > a[key].value) {
                swap(a[key], a[parent]);
                key = parent;
                parent = key / 2;
            }
        }
    }

    int formation(int number) {
        int flag = false;
        for (int j = 1; j <= heap_size; j++)
            if (a[j].priority == number) {
                flag = j;
                break;
            }
        return flag;
    }
};

int main() {
    ifstream fin("priorityqueue.in");
    ofstream fout("priorityqueue.out");

    priority_queue queue;
    int priority = 1;
    string operation;

    while (fin >> operation) {

        if (operation == "push") {
            int key;
            fin >> key;
            queue.push(key, priority);
        }
        if (operation == "extract-min") {
            if (heap_size == 0)
                fout << "*" << endl;
            else
                fout << queue.extract_min() << endl;
        }
        if (operation == "decrease-key") {
            int number, new_value;
            fin >> number >> new_value;
            number = queue.formation(number);
            if (number != false) {
                queue.decrease_key(new_value, number);
            }
        }
        priority++;
    }
    fin.close();
    fout.close();
    return 0;
}