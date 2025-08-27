#include <iostream>
#include <algorithm>

using namespace std;
int t;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	for(int i=0; i<t;i++){
		int a;
		int ans = 0;
		cin >> a;
		for(int j=5; j<=a; j*=5){
			ans += a/j;
		}
		cout << ans << '\n';
	}
	return 0;
}
