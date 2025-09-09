#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> v[10];

int main(){
	v[0].push_back(0);
	v[1].push_back(1);
	
	for(auto a:v){
		for(auto b:a) cout << b;
	}
	

	for(auto a:v){
		for(auto b:a) cout << b;
	}
	return 0;
}
