#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, C;
struct Edge{
	int num;
	int cost;
};
vector<Edge> node[1001];

int dist[1001];

struct cmp{
	bool operator()(Edge a, Edge b) {
		return a.cost > b.cost;
		}
};
void dijkstra(int st){
	priority_queue<Edge, vector<Edge>, cmp> pq;
	pq.push({st, 0});
	dist[st] = 0;
	while(pq.size()){
		Edge now = pq.top();
		pq.pop();
		
		if(dist[now.num] < now.cost) continue;
		
		for(int i=0; i<node[now.num].size(); i++){
			int nextCost = now.cost + node[now.num][i].cost;
			int tar = node[now.num][i].num;
			if(nextCost < dist[tar]){
				dist[tar] = nextCost;
				pq.push({tar, nextCost});
			}
		}
	}
	return; 
}

int main(){
	cin >> N >> M;
	
	for(int i=0; i<M; i++){
		int to, from, cost;
		cin >> to >> from >> cost;
		node[to].push_back({from, cost});
//		node[from].push_back({to, cost});
	}
	int st, end;
	cin >> st >> end;
	fill(dist, dist+1001, 21e8);
	dijkstra(st);
	
	cout << dist[end];
	return 0;
}
