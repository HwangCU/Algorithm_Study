#include <iostream>
using namespace std;

int main(){
	int a = 11; // 1011
	int b = a >> 1; // 0101
	int c = b << 1; // 1010
	cout << a<< '\n' << b << '\n' << c << '\n';
	
	int a1 = 9; // 1001
	int b1 = 8; // 1000
	cout << (a1^b1) << '\n';
	
	cout << (~-2) << '\n';
	return 0;
}
