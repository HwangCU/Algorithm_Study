#include <iostream>
#include <algorithm>

using namespace std;

//9���� 7���� �̴� ���� ����
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
//	Permutation���� 
//	sort(nan_jang, nan_jang+9);
//	do{
//		int sum = 0;
//		for(int i = 0; i < 7; i++) sum += nan_jang[i];
//		if(sum == 100) break;
//		
//	}while(next_permutation(nan_jang, nan_jang+9));
//	
//	for(int i = 0; i < 7; i++) cout<< nan_jang[i] << "\n";
	
//	����Լ� ����
 	makePermutation(9,7,0);
	return 0;
} 
