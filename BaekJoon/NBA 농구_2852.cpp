#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <iomanip>
using namespace std;

int N;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	map<string, int> mp;
	int ret = 0;
	string temp;
	int one_hour = 0; int one_min = 0;
	int two_hour = 0; int two_min = 0;
	
	for(int n=0; n<N; n++){
		int team;
		string time;
		
		cin >> team >> time;
		mp[time] = team;
	}
	
	for(auto a: mp){
		if(ret > 0){
			int hour = stoi(a.first.substr(0,2)) - stoi(temp.substr(0,2));
			int min = stoi(a.first.substr(3,2)) - stoi(temp.substr(3,2));
			one_hour += hour;
			one_min += min;
		}
		
		else if(ret < 0){
			int hour = stoi(a.first.substr(0,2)) - stoi(temp.substr(0,2));
			int min = stoi(a.first.substr(3,2)) - stoi(temp.substr(3,2));
			two_hour += hour;
			two_min += min;
		}
		
		if(a.second == 1) { ret++;}
		else if(a.second == 2) {ret--;}
		temp = a.first;	
	}
	
	if(ret > 0){
		int hour = 48 - stoi(temp.substr(0,2));
		int min = 0 - stoi(temp.substr(3,2));
		one_hour += hour;
		one_min += min;
		}
		
	else if(ret < 0){
		int hour = 48 - stoi(temp.substr(0,2));
		int min = 0 - stoi(temp.substr(3,2));
		two_hour += hour;
		two_min += min;
	}
	
	if(one_min < 0){
		one_hour--;
		one_min = 60 + one_min;
	}
	else if(two_min < 0){
		two_hour--;
		two_min = 60 + two_min;
	}
	cout << setw(2) << setfill('0') << one_hour << ":"
     << setw(2) << setfill('0') << one_min  << "\n";
	cout << setw(2) << setfill('0') << two_hour << ":"
     << setw(2) << setfill('0') << two_min;
}
