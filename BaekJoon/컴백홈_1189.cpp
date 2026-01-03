#include<iostream>
using namespace std;

int r,c,k;
int ans = 0;
char map[6][6];
int dy[4] = {-1,1,0,0}, dx[4] = {0,0,-1,1};
bool visited[6][6];

struct Point{
	int y;
	int x;
};

void solution(Point p, int lev){
	if(k == lev && p.y == 0 && p.x == c-1){
		ans++;
		return;
	}
	if(lev > k) return;
	
	for(int i=0; i<4; i++){
		int ny = p.y + dy[i];
		int nx = p.x + dx[i];
		if(ny<0||ny>=r||nx<0||nx>=c) continue;
		if(map[ny][nx] == 'T') continue;
		if(visited[ny][nx]) continue;
		
		visited[ny][nx] = 1;
		solution({ny,nx}, lev+1);
		visited[ny][nx] = 0;	
		
	}
	return;
}

int main(){
	cin >> r >> c >> k;
	for(int i=0; i<r; i++){
		for(int j=0; j<r; j++){
			cin >> map[i][j];
		}
	}
	visited[r-1][0] = 1;
	solution({r-1,0},1);
	cout << ans;
	return 0;
}
