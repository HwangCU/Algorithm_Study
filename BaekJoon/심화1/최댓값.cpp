#include <iostream>
using namespace std;

int main(){
	int arr[10][10];
	int maxi = -1;
	int n,m;
	for(int i=0; i<9;i++){
		for(int j=0; j<9; j++){
			cin >> arr[i][j];
			if(arr[i][j] > maxi){
				maxi = arr[i][j];
				n = i+1; m = j+1;	
			}
		}
	}
	cout << maxi << '\n' << n <<' ' << m;
	return 0;
	
}
