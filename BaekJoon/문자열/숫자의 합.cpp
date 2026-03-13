#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int a;
	string b;
	cin >> a >> b;
	int ans = 0;
	for(int i=0; i<a; i++){
		ans += int(b[i]-'0');
		}
	cout << ans;	
	return 0;
}
