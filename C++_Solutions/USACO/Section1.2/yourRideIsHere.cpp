/*
ID: annekin1
TASK: ride
LANG: C++                 
*/

#include <bits/stdc++.h>

using namespace std;

int score(string A){
	int out = 1;
	for(auto let : A){
		out *= let -'A'+1;
		out%=47;
	}
	return out;
}

int main(){
	ifstream fin("ride.in");
	ofstream fout("ride.out");

	string A,B;
	fin>>A>>B;
	if(score(A) == score(B)){
		fout<<"GO"<<endl;
	}
	else{
		fout<<"STAY"<<endl;
	}

	return 0;
}