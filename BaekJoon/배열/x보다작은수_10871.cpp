#include <iostream>

using namespace std;

int main(){
	int a,x;
	cin >> a >> x;
	for(int i=0; i<a; i++){
		int temp;
		cin >> temp;
		if(temp < x) cout << temp << " ";
	}
}
