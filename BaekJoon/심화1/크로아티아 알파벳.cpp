#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	string str;
	cin >> str;
	
	string alpha[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "ze"};
	int ans = 0;
	for(int i=0; i<str.length(); i++){
		for(int j=0; j<8; j++){
			int cnt = 0;
			for(int k=0; k<alpha[j].length(); k++){
				if(str[i+k] == alpha[j][k]){
					cnt++;
				}
			}
			if(cnt == alpha[j].length()) {
				i += alpha[j].length()-1;
			}
		}
		ans++;
	}
	cout << ans;
	return 0;
}
