#include <fstream> 
#include <iostream>

using namespace std;

int main()
{
	int a,b,sum;
	ifstream fin("aplusb.in");
	
	fin >> a;
	fin >> b;
	sum = a + (b*b);
	
	ofstream fout("aplusb.out");
	fout << sum << endl;
	
	fin.close();
	fout.close();
	return 0;
}

