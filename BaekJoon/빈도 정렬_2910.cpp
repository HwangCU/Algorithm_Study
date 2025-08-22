#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int N,C;
int arr[1001];
map <int,int> mp, mp_th;
vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b){
	if(a.first == b.first) return mp_th[a.second] < mp_th[b.second];
	return a.first > b.first; 
}

int main(){
	cin >> N >> C;
	
	for(int i=0; i<N; i++){
		cin >> arr[i];
		mp[arr[i]]++;
		if(mp_th[arr[i]] == 0) mp_th[arr[i]] = i+1;
	}
	for(auto i: mp){
		v.push_back({i.second, i.first});
	}
	sort(v.begin(),v.end(),compare);
	
	for(auto i: v){
		for(int j=0; j<i.first; j++) cout << i.second << " ";
	}
}
