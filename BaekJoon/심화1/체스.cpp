#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio;
	cin.tie(0);cout.tie(0);
	int arr[6] = {1,1,2,2,2,8};

	for(int i=0; i<6; i++){
		int a;
		cin >> a;
		cout << arr[i] - a << ' ';
	}
	return 0;
}
