#include <iostream>

using namespace std;

int main(){
	int A, B, C;
	int dat[101] = {0};
	cin >> A >> B >> C;
	
	for(int i = 0; i < 3; i++){
		int s,e;
		cin >> s >> e;
		
		for(int j = s; j < e; j++){
			dat[j]++;
		}
	}
	
	int result = 0;
	
	for(int i = 0; i < 101; i++){
		if(dat[i] == 1) result += A;
		else if(dat[i] == 2) result += 2*B;
		else if(dat[i] == 3) result += 3*C;
	}
	cout << result;
}
