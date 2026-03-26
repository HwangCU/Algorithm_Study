#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	string str;
	int idx = 0;
	char c_arr[16][16] = {0};
	while(getline(cin, str))
	{
		for(int i=0; i<str.length(); i++)
		{
			c_arr[idx][i] = str[i];
		}
		idx++;
	}
	
	for(int j=0; j<15; j++)
	{
		for(int i=0; i<15; i++)
		{
			if(c_arr[i][j] == '\0') continue;
			cout << c_arr[i][j];
		}
	}
	
	return 0;
}
