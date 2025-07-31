#include <iostream>

using namespace std;

int main(){
	string input;
	cin >> input;
	
	int abc[26] = {0};

	for(int i : input){
		abc[i - 'a'] += 1;
	}
	for(int i = 0; i < 26; i++){
		cout << abc[i] << " ";
	}
}
