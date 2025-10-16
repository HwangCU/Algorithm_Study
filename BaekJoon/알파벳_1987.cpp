#include <iostream>
#include <algorithm>

using namespace std;
int r,c;
char map[21][21];
int visited[100];

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int ans = 0;

void dfs(int y, int x, int lev){
	ans = max(lev, ans);
	for(int i=0; i<4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if(ny<0 || ny>=r || nx<0 || nx>=c) continue;
		if(visited[map[ny][nx]]) continue;
		visited[map[ny][nx]] = 1;
		dfs(ny,nx, lev+1);
		visited[map[ny][nx]] = 0;
	}
	return;
}
int main(){
	cin >> r >> c;
	for(int i = 0; i<r; i++){
		for(int j=0; j<c; j++){
			cin >> map[i][j];			
		}
	}
	
	visited[map[0][0]] = 1;
	dfs(0,0,1);
	cout << ans;
	return 0;	
}
