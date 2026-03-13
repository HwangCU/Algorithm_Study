#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int t;
	cin >> t;
	for(int i = 0; i<t; i++){
		int a;
		string s;
		cin >> a >> s;
		for(int j=0; j<s.length(); j++){
			for(int k=0; k<a; k++){
				cout << s[j];
			}
		}
		cout << '\n';
	}
	return 0;
}
