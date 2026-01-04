#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int a;
	int ans = 0;
	cin >> a;
	
	for(int i=1; i<=a; i++){
		ans += i;
	}
	cout << ans;
}
