#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int M,N,K;
int map[101][101] = {0};
bool visited[101][101];

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

void print(){
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

int BFS(pair<int, int> a){
	queue<pair<int, int>> q;	
	q.push(a);
	int ret = 1;
	while(q.size()){
		pair<int, int> now = q.front();
		q.pop();
		
		for(int i=0; i<4; i++){
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];
			
			if(ny<0 || ny>=M || nx<0 || nx>=N) continue;
			if(visited[ny][nx] == 1 || map[ny][nx] == 1) continue;
			visited[ny][nx] = 1;
			q.push({ny, nx});
			ret++;
		}
	}
	return ret;
}

int main(){
	vector<int> ans;
	cin >> M >> N >> K;
	
	for(int k=0; k<K; k++){
		int dy, dx, ny, nx;
		cin >> dy >> dx >> ny >> nx;
		
		for(int i=dy; i<ny; i++){
			for(int j=dx; j<nx; j++){
				map[j][i] = 1;
			}
		}
	}
	
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			if(visited[i][j]==0 && map[i][j] == 0){
				visited[i][j] = 1;
				int ret = BFS({i,j});
				ans.push_back(ret);
			}
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for(int a : ans) cout << a << " ";
	return 0;
}
