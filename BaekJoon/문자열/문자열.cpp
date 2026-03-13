#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int cnt;
	
	cin >> cnt;
	
	while(cnt--){
		string a;
		cin >> a;
		cout << a[0] << a[a.length()-1] << '\n';
	}
	return 0;
}
