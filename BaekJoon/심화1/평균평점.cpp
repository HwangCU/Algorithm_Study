#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string sub;
	
	float total_sum = 0;
	int total_sco = 0;
	float avg;

	while(getline(cin, sub)){
		int first_space = sub.find(' ');
		int second_space = sub.find(' ', first_space+1);
		
		string str_sco = sub.substr(first_space+1,3);
		float sco = stoi(str_sco);
		string gra = sub.substr(second_space+1);
		
		if(gra == "P") continue;
		else if(gra == "A+") total_sum += 4.5*sco;
		else if(gra == "A0") total_sum += 4.0*sco;
		else if(gra == "B+") total_sum += 3.5*sco;
		else if(gra == "B0") total_sum += 3.0*sco;
		else if(gra == "C+") total_sum += 2.5*sco;
		else if(gra == "C0") total_sum += 2.0*sco;
		else if(gra == "D+") total_sum += 1.5*sco;
		else if(gra == "D0") total_sum += 1.0*sco;
		else if(gra == "F") total_sum += .0*sco;
		total_sco += sco;
	}
	avg = total_sum / total_sco;
	cout << avg;
	return 0;
}
