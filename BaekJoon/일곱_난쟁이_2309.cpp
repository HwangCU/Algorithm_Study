#include <iostream>
#include <algorithm>

using namespace std;

//9개중 7개를 뽑는 조합 문제
int nan_jang[9];

void makePermutation(int n, int r, int depth)
{
	if(r == depth){
		int sum = 0;
		for(int i = 0; i < 7; i++) sum += nan_jang[i];
		if(sum==100) {
			sort(nan_jang, nan_jang + 7);
			for(int i = 0; i < 7; i++) cout<< nan_jang[i]<<"\n";
			exit(0);	
		}
		
		return;
	}
	
	for(int i = depth; i < n; i++){
		swap(nan_jang[i], nan_jang[depth]);
		makePermutation(n, r, depth + 1);
		swap(nan_jang[i], nan_jang[depth]);
	}
}
 
int main(){
	
	for(int i = 0; i < 9; i++){
		cin >> nan_jang[i];	
	}
//	Permutation로직 
//	sort(nan_jang, nan_jang+9);
//	do{
//		int sum = 0;
//		for(int i = 0; i < 7; i++) sum += nan_jang[i];
//		if(sum == 100) break;
//		
//	}while(next_permutation(nan_jang, nan_jang+9));
//	
//	for(int i = 0; i < 7; i++) cout<< nan_jang[i] << "\n";
	
//	재귀함수 로직
 	makePermutation(9,7,0);
	return 0;
} 
