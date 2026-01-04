#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int x,n;
	int ans = 0;
	cin >> x >> n;
	
	while(n--){
		int a,b;
		cin >> a >> b;
		ans += a*b;
	}
	if(ans == x) cout << "Yes";
	else cout << "No";
}
