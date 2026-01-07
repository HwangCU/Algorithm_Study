#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int maxi=0;
	int idx;
	for(int i=0; i<9; i++){
		int a;
		cin >> a;
		if(maxi<a){
			maxi = a;
			idx = i+1;
		}
	}
	cout << maxi << '\n' << idx;
}
