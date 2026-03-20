#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio;
	cin.tie(0); cout.tie(0);
	
	string a;
	getline(cin, a);
	int space = 1;
	int cnt = 0;
	
	for(char b : a){
		if(b != ' ' && space > 0){
			cnt++;
			space = 0;
		}
		else if(b == ' ') space++;
	}
	cout << cnt;
}
