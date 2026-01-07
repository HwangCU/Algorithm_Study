#include <iostream>
using namespace std;

int main(){
	int dat[42] = {0};
	
	for(int i=0; i<10; i++){
		int a;
		cin >> a;
		dat[a%42] = 1;
	}
	int ans = 0;
	for(int i=0; i<42; i++) if(dat[i]) ans++;
	cout << ans;
	return 0;
}
