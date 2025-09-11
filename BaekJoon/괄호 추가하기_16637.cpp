#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int ret = -21e9;

vector<int> num;
vector<char> giho;

int oper(char g, int a, int b){
	if(g == '+') return a+b;
	else if(g == '-') return a-b;
	else if(g == '*') return a*b;
}

void solve(int lev, int sum){
	
	if(lev == num.size() - 1){
		ret = max(ret, sum);
		return;
	}
	
	solve(lev+1, oper(giho[lev], sum, num[lev+1]));
	if(lev+2 <= num.size()-1){
		int temp = oper(giho[lev+1], num[lev+1],num[lev+2]);
		solve(lev+2, oper(giho[lev], sum, temp));
	}
	return;
}

int main(){
	cin>> n;
	
	for(int i=0; i<n; i++){
		char a;
		cin >> a;
		if(i%2 == 0) num.push_back(a-'0');
		else giho.push_back(a);
	}
	solve(0, num[0]);
	cout << ret;
	return 0;
}
