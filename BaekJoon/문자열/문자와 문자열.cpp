#include <iostream>
using namespace std;

int main(){
	char a[1001];
	cin >> a;
	int i = 0;
	
	while(a[i] != '\0'){
		i++;
	}
	
	cout << i;
	return 0;
}
