#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
int map[51][51];
int mini = 21e8;
vector <pair<int, int>> home;
vector <pair<int, int>> chicken;
vector <pair<int, int>> chicken_list;

void go(int lev, int idx){
	if(lev == m){
		int local_mini = 0;
		for(auto h:home){
			int mini_dis = 21e8;
			int dis;
			for(auto c:chicken){
				dis = abs(h.first - c.first) + abs(h.second - c.second);
				mini_dis = min(dis, mini_dis);
			}
			local_mini += mini_dis;
			if(local_mini > mini) return;
		}
		mini = min(mini, local_mini);
		return;
	}
	
	for(int i=idx; i<chicken_list.size(); i++){
		chicken.push_back(chicken_list[i]);
		go(lev+1, i+1);
		chicken.pop_back();
	}
}

int main(){
	cin >> n >> m;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> map[i][j];
			if(map[i][j] == 1) home.push_back({i,j});
			if(map[i][j] == 2) chicken_list.push_back({i,j});
		}
	}
	go(0, 0);
	
	cout << mini;
}
