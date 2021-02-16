#include <fstream> 
#include <iostream>

using namespace std;

int main()
{
	int h, w;
	ifstream fin("turtle.in");
	fin >> h;
	fin >> w;
	
	int x[h][w];
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			fin >> x[i][j]; 
		}
	}
	for (int i = h - 1; i >= 0; i--) {
		for (int j = 0; j < w; j++) {
			int left = 0, down = 0;
			if (i != h-1) {
				down = x[i+1][j];
			}
			if (j != 0) {
				left = x[i][j-1];
			}
			if (left > down) { 
				x[i][j] += left;
			} else x[i][j] += down;
		}
	}
	ofstream fout ("turtle.out");
	fout << x[0][w-1] << endl;
	fin.close();
	fout.close();
	
	return 0;
}

