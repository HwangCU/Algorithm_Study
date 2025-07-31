#include <iostream>

using namespace std;

int main(){
	string input;
	getline(cin, input);
//	a = 97, A = 65 
	for(char i : input){
		if(i>='A' && i<'a' && i+13<='Z') cout << char(i+13);
		else if(i>='A' && i<'a' && i+13>'Z') cout << char(i+13-'Z'+'A'-1);
		else if(i>'Z' && i<='z' && i+13<='z') cout << char(i+13);
		else if(i>'Z' && i<='z' && i+13>'z') cout << char(i+13-'z'+'a'-1);
		else cout << i;
	}
}
