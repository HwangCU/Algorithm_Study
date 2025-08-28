#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL); 
	int t;
	cin >> t;
	while(t--){
		string In;
		cin >> In;
		while(In.find("()") != string::npos){
			In = In.replace(In.find("()"),2,"");	
		}
		if(In.length()>0) cout << "NO\n";
		else cout << "YES\n";
	}	
}
