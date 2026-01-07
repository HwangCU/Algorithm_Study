#include <iostream>

using namespace std;

int main(){
	int n;
	int arr[101];
	int tar;
	int ans = 0;
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	cin >> tar;
	
	for(int i=0; i<n; i++){
		if(tar == arr[i]) ans++;
	}
	cout << ans;
	return 0;
}
