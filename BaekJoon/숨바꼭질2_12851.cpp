#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int ret = 100001;
int method = 0;
bool visited[100001];
void dfs(int x, int time){
	cout << x << " ";
	visited[x] = 1;
	if(time > ret || x<0 || x>100000) return;
	if(x == k){
		if(time < ret){
			ret = time;
			method = 1;
		}
		else if(time == ret) method++;
		return;
	}
	dfs(x-1, time+1);
	dfs(x+1, time+1);
	dfs(x*2, time+1);
	
	return;
}

int main(){
	cin >> n >> k;
	dfs(n,0);
	cout << ret << "\n" << method;
}
