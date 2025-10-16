#include <iostream>
#include <cstring>

using namespace std;
int k;
char sign[10];
int visited[10];
int num[10];
void dfs(int lev){
	if(lev == k){
		for(int i=0; i<=k; i++){
			cout << num[i];
		}
		return;
	}
	for(int i=0; i<10; i++){
		if(visited[i]) continue;
		num[i] = i;
		visited[i] = 1;
		dfs(lev+1);
//		visited[i] = 0;
	}
}
int main(){
	cin >> k;
	for(int i=0; i<k; i++){
		cin >> sign[i];
	}
	dfs(0);
	return 0;
} 
