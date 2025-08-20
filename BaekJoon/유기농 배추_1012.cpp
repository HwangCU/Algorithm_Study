#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int map[50][50] = {0};
int visited[50][50] = {0};
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int M, N, K;

void print(){
	for(int n=0; n<N; n++){
		for(int m=0; m<M; m++){
			cout << map[n][m] << " ";
		}
		cout << "\n";
	}
	
	for(int n=0; n<N; n++){
		for(int m=0; m<M; m++){
			cout << visited[n][m] << " ";
		}
		cout << "\n";
	}
}

void DFS(pair<int,int> a){
	
	for(int i=0; i<4; i++){
		int ny,nx; 
		ny = a.first + dy[i];
		nx = a.second + dx[i];
		
		if(ny<0 || ny>=N || nx<0 || nx>=M || map[ny][nx] == 0 || visited[ny][nx]) continue;
		
		visited[ny][nx] = 1;
		DFS({ny,nx});
	}
}

int main(){
	int T;
	cin >> T;
	
	for(int t=0; t<T; t++)	{
		memset(map,0,sizeof(map));
		memset(visited,0,sizeof(visited));
		int ret = 0;
		cin >> M >> N >> K;
		for(int k=0; k<K; k++){
			int y,x;
			cin >> y >> x;
			map[x][y] = 1;
		}
		
		for(int m=0; m<M; m++){
			for(int n=0; n<N; n++){
				if(map[n][m] == 1 && visited[n][m] == 0){
					visited[n][m] = 1;
					DFS({n,m});
//					print();
					ret++;
				}
			}
		}
		cout << ret << "\n";
	}
}
