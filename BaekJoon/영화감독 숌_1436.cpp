#include <iostream>

using namespace std;

int main(){
	int N;
	cin >> N;
	int i = 666;
	for(;;i++){
		if(to_string(i).find("666") != string::npos) N--;
		if(N==0) break;
	}
	cout << i;
}
