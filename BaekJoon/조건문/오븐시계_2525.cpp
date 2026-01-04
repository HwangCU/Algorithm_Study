#include <iostream>

using namespace std;

int main(){
	int a,b,c;
	
	cin >> a >> b >> c;
	
	int h = c/60;
	int m = c%60;
	a = h+a;
	b = b+m;
	if(b >= 60){
		a += 1;
		b = b-60;
	}
	if(a>=24) a = a-24;
	
	cout << a << ' ' << b;
}
