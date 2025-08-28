#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N,M;
int map[9][9];
int ori_map[9][9];
bool visited[9][9];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int ans = 0;
queue<pair<int, int>> q;

void BFS(){
	while(q.size()){
		pair<int, int> p = q.front();
		q.pop();
		
		for(int i=0; i<4; i++){
			int ny = p.first + dy[i];
			int nx = p.second + dx[i];
			
			if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
			if(visited[ny][nx] == 0 && ori_map[ny][nx] == 0){
				q.push({ny, nx});
				ori_map[ny][nx] = 2; 
				visited[ny][nx] = 1;
			}
		}
	}
	return;
}

int count_safe(){
	int ret = 0;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(ori_map[i][j] == 0) ret++;
		}
	}
	return ret;
}

void DFS(int lev){
	if(lev == 3){
		fill(&visited[0][0], &visited[0][0]+9*9, 0);
		memcpy(ori_map, map, sizeof(ori_map));
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				if(map[i][j] == 2) q.push({i,j});
			}
		}
		BFS();
		ans = max(ans, count_safe());
		return;
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(map[i][j] == 0){
				map[i][j] = 1;
				DFS(lev+1);
				map[i][j] = 0;
			}
		}
	}
	return;
}

int main(){
	cin >> N >> M;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> map[i][j];
			ori_map[i][j] = map[i][j];
		}
	}
	DFS(0);
	cout << ans;
}
