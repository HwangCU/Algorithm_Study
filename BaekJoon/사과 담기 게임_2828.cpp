#include <iostream>

using namespace std;
int N,M,J;
int apple[21] = {0};
int main(){
	cin >> N >> M >> J;
	
	for(int i=0; i<J; i++){
		cin >> apple[i];
	}
	
	int st = 1;
	int e = M;
	int move = 0;
	
	for(int a:apple){
		if(a == 0) break;
		if(st>a){
			move += (st - a); 
			e = e - st + a; 
			st = a;
		}
		else if(e<a){
			move += (a-e);
			st = st +a-e;
			e = a;
		}
		
	}
	cout << move;
}
