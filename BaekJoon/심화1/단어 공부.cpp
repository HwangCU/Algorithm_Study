#include <iostream>
#include <algorithm>
#include <cstring> 
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	string a;
	cin >> a;
	int dat[100];
	memset(dat,0,sizeof(dat));
		
	for(char c:a){
		if('a'<=c && 'z'>=c) dat[c-('a'-'A')]++;
		else dat[c]++;
	}
	
	int ret = 0;
	for(int i='A'; i<='Z'; i++){
		ret = max(ret, dat[i]);
	}
	int cnt = 0;
	char ans;
	for(int i='A'; i<='Z'; i++){
		if(ret == dat[i]) {
			ans = i;
			cnt++; 	
		}
		if(cnt>1) {
			cout << '?';
			return 0;
		}
	}
	cout << ans;
	return 0;
}
