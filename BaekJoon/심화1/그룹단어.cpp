#include <iostream>
#include <cstring> 
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n;
	int ans = 0;
	cin >> n;
	int dat[200];
	while(n--){
		bool flag = 1;
		memset(dat, 0, sizeof(dat));
		string str;
		cin >> str;
		for(int i=0; i<str.length(); i++){
			if((dat[str[i]] > 0) && (str[i] != str[i-1])) {
				flag = 0;
				break;
			}
			dat[str[i]]++;
		}
		if(flag) {
			ans++;
			flag = 0;
		}
	}
	cout << ans; 
}
