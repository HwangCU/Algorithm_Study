#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int a;
	cin >> a;
	
	for(int i=1; i<a*2; i++){
		for(int j=0; j<abs(a-i); j++) cout << ' ';
		if(i<a) for(int k=0; k<2*i-1; k++) cout << '*';
		else for(int k=0; k<(a*2-i)*2-1; k++) cout << '*';
		cout << '\n';
	}
	return 0;
}
