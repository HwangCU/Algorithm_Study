#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int map[101][101];
bool visited[101][101] = {0};
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

void print(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout << visited[i][j] << " ";
		}
		cout<< "\n";
	}
}

void DFS(pair<int, int> a, int r){
	
	for(int i=0; i<4; i++){
		int ny = a.first + dy[i];
		int nx = a.second + dx[i];
		
		if(ny<0 || ny>=N || nx<0 || nx>=N) continue;
		if(visited[ny][nx] || map[ny][nx] <= r) continue;
		visited[ny][nx] = 1;
		DFS({ny,nx}, r);
	}
	return;
}

int main(){
	cin >> N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> map[i][j];
		}
	}
	int ans = 0;
	
	for(int r=0; r<=100; r++){
		memset(visited,0,sizeof(visited));
		int zone_num = 0;
		
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if(map[i][j]>r && visited[i][j] == 0){
					visited[i][j] = 1;
					DFS({i,j}, r);
//					cout << "r: "<< r << "\n";
//					print();
					zone_num++;
				}
			}
		}
		
		if(zone_num == 0) break;
		ans = max(zone_num, ans);
	}
	cout << ans;
	return 0;
}
