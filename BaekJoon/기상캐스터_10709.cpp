#include <iostream>
#include <algorithm>

using namespace std;
int H,W;
char Map[101][101];
int ans[101][101];

void print(){
	for(int h=0;h<H; h++){
		for(int w=0; w<W; w++){
			cout << ans[h][w] << " ";
		}
		cout << "\n";
	}
}

int main(){
	cin >> H >> W;
	fill(&ans[0][0], &ans[0][0]+101*101, -1);
	
	for(int h=0;h<H; h++){
		for(int w=0; w<W; w++){
			cin >> Map[h][w];
			if(Map[h][w] == 'c'){
				ans[h][w] = 0;
			}
			else if((w-1) > -1 && ans[h][w-1] > -1){
				ans[h][w] = ans[h][w-1] + 1;
			}
		}
	}
	print();
	
	return 0;
}
