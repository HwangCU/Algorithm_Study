#include <iostream>
#include <queue>

using namespace std;
int n;
int scv[3];
int visited[64][64][64];
int attack[6][3] = {
	{9,3,1},
	{9,1,3},
	{3,9,1},
	{3,1,9},
	{1,9,3},
	{1,3,9},
};
struct A{
	int a;
	int b;
	int c;
};

int solve(){
	int ret = 0;
	queue<A> q;
	q.push({scv[0],scv[1],scv[2]});
	visited[scv[0]][scv[1]][scv[2]] = 1;
	
	while(q.size()){
		A now = q.front(); q.pop();
		if(visited[0][0][0]) break;
		for(int i=0; i<6; i++){
			int na = max(0, now.a - attack[i][0]);
			int nb = max(0, now.b - attack[i][1]);
			int nc = max(0, now.c - attack[i][2]);
			
			if(visited[na][nb][nc]) continue;
			visited[na][nb][nc] += visited[now.a][now.b][now.c] + 1;
			q.push({na,nb,nc});
		}
		
	}
	return visited[0][0][0]-1;
}
int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> scv[i];
	}
	cout << solve();
}
