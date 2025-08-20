#include <iostream>

using namespace std;

int main(){
	int a[10][10] = {0};
	
	a[0][1] = 1;
	
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}
