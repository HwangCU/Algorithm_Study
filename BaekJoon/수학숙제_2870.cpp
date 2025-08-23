#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<string> v;

bool cmp(string a, string b){
	if(a.length() == b.length()){
		return a < b;
	}
	return a.length() < b.length();
}

int main(){
	cin >> N;
	
	for(int n=0; n<N; n++){
		string input;
		cin >> input;
		string temp="";
		int idx = 0;
		for(char i:input){
			if(i>='0' && i<='9') temp+=i;
			
			if(i>'9' || idx==input.size()-1){
				if(temp.size()>0){
					while(temp.size()>1 && temp[0] == '0'){
						temp = temp.substr(1);
					}
					v.push_back(temp);
					temp = "";
				}
			}
			idx++;
		}
	}
	sort(v.begin(), v.end(), cmp);
	for(string i:v) cout << i << " ";
}
