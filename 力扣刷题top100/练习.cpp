#include<iostream>


using namespace std;



int main() {
	
	////读取数量不定的数据
	//int sum = 0, value = 0;

	//while (cin >> value)
	//	sum += value;

	//cout << " sum = " << sum << endl;

	unsigned u = 10, u2 = 42;
	cout << u2 - u << endl;
	cout << u - u2 << endl;

	int i = 10, i2 = 42;
	cout << i2 - i << endl;
	cout << i - i2 << endl;
	cout << i - u << endl;
	cout << u - i << endl;

	system("pause");
	return 0;
}