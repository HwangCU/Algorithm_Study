#include<iostream>

using namespace std;

int main() {
	int n = 4;
	string a[n] = {"사과", "딸기", "포도", "배"};
	for(int i = 0; i < (1 << n); i++){
		string ret = "";
		for(int j = 0; j < n; j++){
			if(i & (1 << j)){
				ret += (a[j] + " ");
				}
			}
			cout << ret << '\n';
	}
	return 0;
}

