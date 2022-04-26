#include<iostream>
#include<ctime>

using namespace std;



int main() {
	int n = 1000000000;
	string s1 = "";

	clock_t startTime = clock();
	for (int i = 0; i < n; ++i)		
		s1.push_back('A');

	clock_t endTime = clock();
	cout << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
	s1.clear();
	string s2 = "";
	startTime = clock();
		s2 += "A";
	for (int i = 0; i < n; ++i)
	endTime = clock();
	cout << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;




	system("pause");
	return 0;
}