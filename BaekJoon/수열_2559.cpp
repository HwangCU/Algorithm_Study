#include <iostream>
#include <algorithm>
using namespace std;

int N[100001];
int sum[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	cin >> sum[0];
	
	for(int i = 1; i < N; i++){
		int temp;
		cin >> temp; 
		sum[i] = temp + sum[i-1];
	}
	
////	debuging
//	for(int i=0; i<N; i++) cout<< sum[i] << " "; 
	
	int maxis=sum[K-1];
	
	for(int i=K; i<N; i++){
		maxis = max(maxis, sum[i]-sum[i-K]);
	}
	cout << maxis;
}
