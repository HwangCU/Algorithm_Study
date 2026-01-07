#include <iostream>

using namespace std;

int main(){
	int n,m;
	int arr[101] = {0};
	cin >> n >> m;
	
	for(int i=0; i<m; i++){
		int a,b,c;
		cin >> a >> b >> c;
		for(int j=a; j<=b; j++){
			arr[j] = c;
		}
	}
	
	for(int i=1; i<=n; i++) cout << arr[i] << ' ';
	return 0;
} 
