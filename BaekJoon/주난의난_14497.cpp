#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n,m,x1,x2,y1,y2;
int visited[301][301];
char map[301][301];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};


bool bfs(){
	queue<pair<int,int>> q;
	fill(&visited[0][0], &visited[0][0]+301*301, 0);
	q.push({y1,x1});
	visited[y1][x1] = 1;
	
	while(q.size()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++){
			int ny = y+dy[i];
			int nx = x+dx[i];
			if(ny<0|| ny>n || nx<0 || nx>m) continue;
			if(visited[ny][nx]) continue;
			if(map[ny][nx] == '1'){
				map[ny][nx] = '0';
				visited[ny][nx] = 1;
			}
			else if(map[ny][nx] == '0'){
				q.push({ny,nx});
				visited[ny][nx] = 1;
			}
			else if(map[ny][nx] == '#'){
				return true;
			}
		}
	}
	return false;
}
int main(){
	int ret = 1;
	cin >> n >> m;
	cin >> y1>> x1 >> y2 >> x2;
	y1-=1; x1-=1; y2-=1; x2-=1;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> map[i][j];
		}
	}
	while(1){
		if(bfs()){
			break;
		}
		ret++;
	}
	cout << ret;
}
