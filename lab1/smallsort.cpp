#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int size; 
    ifstream fin("smallsort.in");
    fin >> size;
    int arr[size];
    for (int i = 0; i < size; i++) {
		fin >> arr[i];
	}
	
    int tmp; 
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
	ofstream fout("smallsort.out");
    for (int i = 0; i < size; i++) {
        fout << arr[i] << " ";
    }
    fout << endl;
    fin.close();
    fout.close();
    return 0;
}
