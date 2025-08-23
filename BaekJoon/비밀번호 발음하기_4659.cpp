#include <iostream>

using namespace std;


int main(){
	string input;
	while(1){
		cin >> input;
		if (input == "end") break;
		bool vow_check = 0;
		bool con_check = 0;
		bool same_check = 0;
		int vow_cnt = 0;
		int const_cnt = 0;
		int idx = 1;
		for(char a: input){
			if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u') {vow_check = 1;}
			if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u'){vow_cnt++; const_cnt = 0;}
			else {const_cnt++; vow_cnt=0;}
			if(const_cnt>=3 || vow_cnt>=3) {con_check=1; break;}
			if(a!='e' && a!='o' && input.size()>idx){
				if(input[idx] == a) {same_check=1; break;}
			}
			idx++;
		}
//		cout << vow_check << " " << vow_cnt << " " << const_cnt << " " << same_check; 
		if(!vow_check || con_check || same_check) cout << "<" << input << ">" << " is not acceptable." << "\n";
		else cout << "<" << input << ">" << " is acceptable." << "\n";
	}
	return 0; 
}
