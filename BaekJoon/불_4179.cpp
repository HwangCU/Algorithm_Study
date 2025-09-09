#include <iostream>

using namespace std;

int r,c;
char map[1001][1001];
bool visited[1001][1001];

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

void fire(){
	
}
void dfs(int y, int x, int time){
	for(int i=0; i<4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if(ny<0 || ny>=r || nx<0 || nx>=c) continue;
		if(map[ny][nx] == '#' || map[ny][nx] == 'F') continue;
		if(visited[ny][nx]) continue;
		visited[ny][nx] = 1;
		map[y][x] = '.';
		map[ny][nx] = 'J';
		for(
		dfs(ny,nx, time+1);
		map[y][x] = 'J';
		map[ny][nx] = '.';
		visited[ny][nx] = 0;
		
	}	
}

int main(){
	cin >> r >> c;
	
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			cin >> map[i][j];
		}
	}
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}

}
