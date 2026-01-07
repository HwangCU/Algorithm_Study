#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int n,mp,mf,ms,mv;
int arr[15][5];

int main(){
	cin >> n;
	cin >> mp >> mf >> ms >> mv;
	map<int, vector<vector<int>>> ans;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<5; j++)
			cin >> arr[i][j];
	}
	
	int mc = 21e8;
	
	for(int i=1; i<(1<<n); i++){
		int tp=0,tf=0,ts=0,tv=0, tc=0;
		vector<int> temp;
		for(int j=0; j<n; j++){
			if(i & (1<<j)){
				tp += arr[j][0];
				tf += arr[j][1];
				ts += arr[j][2];
				tv += arr[j][3];
				tc += arr[j][4];
				temp.push_back(j+1);
			}
		}
		
		if(tp>=mp && tf>=mf && ts>=ms && tv>=mv){
			if(mc>=tc) {
				mc = tc;
				ans[mc].push_back(temp);
			}
		}
	}
	
	if(mc == 21e8){
		cout << -1;
	}
	else {
		sort(ans[mc].begin(),ans[mc].end());
		cout << mc << '\n';
		for(int a:ans[mc][0]) cout << a << ' ';
	}
	
	return 0;
}
