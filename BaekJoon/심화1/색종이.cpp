#include <iostream>
using namespace std;

int main(){
	int arr[101][101] = {0};
	
	int a;
	cin >> a;
	for(int i=0; i<a; i++){
		int y,x;
		cin >> y >> x;
		for(int i1=y; i1<y+10; i1++){
			for(int j1=x; j1<x+10; j1++){
				arr[i1][j1] += 1;
			}
		}
	}
	
	int total = 100*a;
	for(int i=0; i<100; i++){
		for(int j=0; j<100; j++){
			if(arr[i][j] > 1){
				total -= (arr[i][j]-1);
			}
		}
	}
	cout << total;
	return 0;
}
