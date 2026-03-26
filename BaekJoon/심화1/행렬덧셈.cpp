#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int arr[101][101], arr1[101][101], arr2[101][101];
	int n,m;
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++)
		{	
			int temp;
			cin >> temp;
			arr1[i][j] = temp;
		}
		
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			int temp;
			cin >> temp;
			arr2[i][j] = temp;
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++)
		{	
			arr[i][j] = arr1[i][j] + arr2[i][j];
		}
		
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++)
			cout << arr[i][j] << ' ';
		cout << '\n';
	}
	return 0; 
}
