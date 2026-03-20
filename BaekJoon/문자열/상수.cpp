#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio;
	cin.tie(0); cout.tie(0);
	
	string a;
	string b;
	
	cin >> a >> b;
	
	for(int i=0; i<a.length()/2; i++){
		swap(a[i],a[a.length()-1-i]);
	}
	
	for(int i=0; i<b.length()/2; i++){
		swap(b[i],b[b.length()-1-i]);
	}
	
	if(stoi(a) > stoi(b)) cout << a;
	else cout << b;
	return 0;
}
