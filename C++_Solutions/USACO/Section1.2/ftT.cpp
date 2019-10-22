/*
ID: annekin1
TASK: friday
LANG: C++                 
*/

#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(int i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(int i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(int i_=1;i_<a_;++i_)
#define ll long long int
#define ull unsigned long long int

int main(){
	ifstream fin("friday.in");
	ofstream fout("friday.out");
	int years;
	fin>>years;
	int day = 12%7;
	vector<int> days(7);
	vector<int> daysInMonth = {31,28,31,30,31,30,31,31,30,31,30,31};
	++days[day];
	FOR(i,years){
		if((i)%4 == 0){
			if((1900+i)%100 == 0){
				if((1900+i)%400 == 0){
					daysInMonth[1] = 29;
				}
				else{
					daysInMonth[1] = 28;
				}
			}
			else{
				daysInMonth[1] = 29;
			}
		}
		else{
			daysInMonth[1] = 28;
		}
		FORA(addD,daysInMonth){
			day += addD;
			day%=7;
			++days[day];
		}
	}
	--days[day];
	FORS(5,i,7){
		fout<<days[i]<<' ';
	}
	FOR(i,4){
		fout<<days[i]<<' ';
	}
	fout<<days[4]<<'\n';
	return 0;
}