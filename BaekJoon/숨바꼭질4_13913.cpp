#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int n,k;
int visited[100001];
int _prev[100001];
vector<int> way;

void solve(){
	queue<int> q;
	q.push(n);
	visited[n] = 1;
	
	while(q.size()){
		int now = q.front(); q.pop();
		
		if(now == k) break;
		
		for(int next:{now-1,now+1,now*2}){
			if(next<0 || next>100000) continue;
			if(visited[next]) continue;
			visited[next] += visited[now]+1;
			_prev[next] = now;
			q.push(next);
		}
	}
}

int main(){
	cin >> n >> k;
	solve();
	for(int i=k; i != n; i=_prev[i]){
		way.push_back(i);
	}
	way.push_back(n);
	reverse(way.begin(), way.end());
	cout << visited[k]-1 << '\n';
	for(int a:way) cout << a << " ";
}
