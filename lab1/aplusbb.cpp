#include <fstream> 
#include <iostream>

using namespace std;

int main()
{
	int64_t a,b;
	ifstream fin("aplusbb.in");
	
	fin >> a;
	fin >> b;
	
	ofstream fout("aplusbb.out");
	fout << (a + b * b) << endl;
	
	fin.close();
	fout.close();
	return 0;
}

