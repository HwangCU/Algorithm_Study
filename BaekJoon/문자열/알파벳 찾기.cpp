#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string s;
	cin >> s;
	int arr[200];
	memset(arr,-1,sizeof(arr));
	
	for(int i=0; i<s.length(); i++){
		if(arr[s[i]] == -1) arr[s[i]] = i;
	}
	for(int i='a'; i<='z'; i++){
		cout << arr[i] << " ";
	}
	return 0;
}
