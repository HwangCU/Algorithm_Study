#include <iostream>

using namespace std;
long long ll;
int n;
int main(){
	while(scanf("%d", &n) != EOF){
		long long cnt = 1, ret = 1;
		
		while(true){
			if(cnt % n == 0){
				cout << ret << "\n";
				break;
			}
			cnt = cnt * 10 + 1;
			cnt %= n;
			ret++;
		}
	}
	return 0;
}
