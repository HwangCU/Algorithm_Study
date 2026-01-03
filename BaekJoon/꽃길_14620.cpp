#include <iostream>
#include <algorithm>

using namespace std;
int n;
int arr[11][11];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int visited[11][11];
int ans = 21e8;

struct Point{
	int y;
	int x;
};

void solution(int sum, int lev){
	if(lev>2){
		ans = min(sum, ans);
		return;
	}
	
	for(int i=1; i<n-1; i++){
		for(int j=1; j<n-1; j++){
			bool flag = true;
			for(int d=0; d<4; d++){
				if(visited[i+dy[d]][j+dx[d]]) flag = false;
			}
			if(flag){
				visited[i][j] = 1;
				int temp_sum = arr[i][j];
				for(int d=0; d<4; d++){
					visited[i+dy[d]][j+dx[d]] = 1;
					temp_sum += arr[i+dy[d]][j+dx[d]];
				}
				solution(sum + temp_sum, lev+1);
				visited[i][j] = 0;
				for(int d=0; d<4; d++){
					visited[i+dy[d]][j+dx[d]] = 0;
				}
			}
		}
	}
	return;
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int a;
			cin >> a;
			arr[i][j] = a;
		}
	}
	solution(0,0);
	cout << ans;
	return 0;
}

