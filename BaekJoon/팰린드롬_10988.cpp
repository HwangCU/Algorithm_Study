#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	string input;
	cin >> input;
	
//	배열 이용해 풀기 
	int ans = 1;
	for(int i = 0; i < input.size()/2; i++){
		if(input[i] != input[input.size() - i - 1]) 
		{
			ans = 0;
			break;
		}
	}
//	reverse 함수 이용해 풀기
	string temp = input;
	reverse(temp.begin(), temp.end());
	if(temp == input) ans = 1;
	cout << ans;
}
