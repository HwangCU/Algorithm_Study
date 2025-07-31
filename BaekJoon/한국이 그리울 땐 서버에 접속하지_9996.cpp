#include <iostream>

using namespace std;

int main(){
	int N;
	cin >> N;
	
	string pattern;
	cin >> pattern;
	string S,E;
	int idx = pattern.find('*');
	S = pattern.substr(0,idx);
	E = pattern.substr(idx+1);
	
//	cout<< S << " " << E<< '\n';
	for(int i = 0; i < N; i++){
		string temp;
		cin >> temp;
		
//		cout << temp.substr(0,S.size()) << " " << temp.substr(temp.size()-E.size());
//		예외 처리 
		if(temp.size() < S.size() + E.size()) cout << "NE" << '\n'; 
		else if(temp.substr(0,S.size()) == S && temp.substr(temp.size()-E.size()) == E)
			cout << "DA" << '\n';
		else 
			cout << "NE" << '\n';
		
	}
	return 0;
}
