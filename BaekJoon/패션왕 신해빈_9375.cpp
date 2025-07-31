#include <iostream>
#include <map>
using namespace std;

int tc, n;
string name, kind;

int main(){
	cin >> tc;
	
	for(int t=0; t<tc; t++){
		map<string, int> clothes;
		cin >> n;
		
		for(int i=0; i<n; i++){	
			cin >> name >> kind;
			clothes[kind] += 1;
		}
//		디버그용 
//		for(auto i : clothes) cout << i.first <<" "<< i.second << " ";

	long long ans = 1;
	for(auto i:clothes) ans *= ((long long)i.second+1); 
	
	cout << ans - 1 << '\n';
	}
	
	return 0;
}
