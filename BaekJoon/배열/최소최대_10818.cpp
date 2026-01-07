#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int maxi=-21e8,mini=21e8;
	int n;
	cin >> n;
	
	while(n--){
		int a;
		cin >> a;
		maxi = max(a,maxi);
		mini = min(a,mini);
	}
	
	cout << mini << ' ' << maxi;
	return 0;
}
 
