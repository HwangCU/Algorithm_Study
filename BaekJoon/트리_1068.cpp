#include <iostream>
#include <vector>
using namespace std;

int n;
int node;
int ret = 0;
vector<int> v[51];
vector<int> st;

void dfs(int p){
	if(v[p].size() == 0){
		ret++;
		return;
	}
	if(v[p].size() == 1 && v[p][0] == node){
		ret++;
		return;
	}
	for(int i=0; i<v[p].size();i++){
		if(v[p][i] == node) continue;
		dfs(v[p][i]);
	}
}

int main(){
	cin >> n;
	
	for(int i=0; i<n;i++){
		int a;
		cin >> a;
		if(a == -1) st.push_back(i);
		else v[a].push_back(i);		
	}
	cin >> node;
	for(auto s:st){
		if(s==node) continue;
		dfs(s);
	}
	cout << ret;
}
