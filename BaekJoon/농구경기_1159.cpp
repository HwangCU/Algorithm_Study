#include <iostream>

using namespace std;

int main(){
	int N;
	int dat[26] = {0};
	cin >> N;
	
	for(int i = 0; i < N; i++){
		string name;
		cin >> name;
		
		dat[name[0] - 'a']++;
	}
	
	bool flag = true;
	
	for(int i = 0; i < 26; i++){
		if(dat[i]>=5) {
			cout << char('a' + i);
			flag = false;
		}
	}
	if(flag) cout << "PREDAJA";
}
