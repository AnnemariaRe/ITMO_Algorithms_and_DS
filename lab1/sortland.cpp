#include <fstream> 
#include <iostream>

using namespace std;

int main()
{
	short n;
	int maxn,minn,midn;
	float *m,aver,max,min,sum,mid;
	ifstream fin("sortland.in");
	fin >> n;
	m = new float[n];
	
	for (int i = 0; i <= n; i++) {
		fin >> m[i];
	}
	max = m[0];
	min = m[0];
	for (int i = 0; i < n; i++) {
		if (m[i] > max) {
			max = m[i];
			maxn = i+1;
		}
		if (m[i] < min) {
			min = m[i];
			minn = i+1;
		}
		sum += m[i];
	}
	aver = sum / n;
	mid = m[0];
	for (int i = 0; i < n; i++) {
		if (abs(m[i] - aver) < abs(mid - aver) ) {
			mid = m[i];
			midn = i+1;
		}
	}
	
	ofstream fout("sortland.out");
	fout << minn << midn << maxn << endl;
	fin.close();
	fout.close();
	return 0;
}

