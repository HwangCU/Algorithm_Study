#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int map[101][101];
bool visited[101][101];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

void DFS(pair<int,int> point){
	
	if(map[point.first][point.second] == 1){
		
		map[point.first][point.second] = 0;
		return;
	}
	
	for(int i=0; i<4; i++){
		int ny = point.first + dy[i];
		int nx = point.second + dx[i];
		
		if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
		if(visited[ny][nx] == 0){
			visited[ny][nx] = 1;
			DFS({ny,nx});
		}
	}
	return;
}

int check_map(){
	int ret = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(map[i][j] == 1) ret++;
		}
	}
	return ret;
}

int main(){
	cin >> n >> m;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> map[i][j];
		}
	}
	int cheese = check_map();
	int ret = 0;
	
	while(check_map()){
		fill(&visited[0][0], &visited[0][0]+101*101,0);
		visited[0][0] = 1;
		DFS({0,0});
		ret++;
		if(check_map() == 0) break;
		cheese = check_map();
	}
	cout << ret << "\n" << cheese;
	return 0;
}
