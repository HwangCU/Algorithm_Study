#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	string input;
	cin >> input;
	
//	�迭 �̿��� Ǯ�� 
	int ans = 1;
	for(int i = 0; i < input.size()/2; i++){
		if(input[i] != input[input.size() - i - 1]) 
		{
			ans = 0;
			break;
		}
	}
//	reverse �Լ� �̿��� Ǯ��
	string temp = input;
	reverse(temp.begin(), temp.end());
	if(temp == input) ans = 1;
	cout << ans;
}
