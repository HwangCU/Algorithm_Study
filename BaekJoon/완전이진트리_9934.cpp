#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> ret[11];
int n, a[1024];

void solution(int s, int e, int lev){
	if(s>e) return;
	if(s == e){
		ret[lev].push_back(a[s]);
		return;
	}
	
	int mid = (s+e) / 2;
	ret[lev].push_back(a[mid]);
	solution(s, mid-1, lev+1);
	solution(mid+1, e, lev+1);
	return;
}
	
int main(){
	cin >> n;
	int e = pow(2,n) - 1;
	
	for(int i=0; i < e; i++){
		cin >> a[i];
	}
	
	solution(0, e, 1);
	
	for(int i=1; i<=n; i++){
		for(int j: ret[i]){
			cout << j << " ";
		}
		cout << "\n";
	}
	return 0;
}
