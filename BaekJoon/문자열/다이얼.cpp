#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio;
	cin.tie(0); cout.tie(0);
	
	string a;
	cin >> a;
	int cnt = 0;
	for(char b:a){
		if(b=='A' || b=='B' || b=='C') cnt+=3;
		else if(b=='D' || b=='E' || b=='F') cnt+=4;
		else if(b=='G' || b=='H' || b=='I') cnt+=5;
		else if(b=='J' || b=='K' || b=='L') cnt+=6;
		else if(b=='M' || b=='N' || b=='O') cnt+=7;
		else if(b=='P' || b=='Q' || b=='R' || b=='S') cnt+=8;
		else if(b=='T' || b=='U' || b=='V') cnt+=9;
		else if(b=='W' || b=='X' || b=='Y' || b=='Z') cnt+=10;
	}
	cout << cnt;
}
