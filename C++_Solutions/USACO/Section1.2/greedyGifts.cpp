/*
ID: annekin1
TASK: gift1
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
	ifstream fin("gift1.in");
	ofstream fout("gift1.out");
	int N;
	fin>>N;
	map<string,int> index;
	vector<int> money(N);
	vector<string> moneyA(N);
	string name;
	FOR(i,N){
		fin>>name;
		index[name] = i;
		money[i] = 0;
		moneyA[i] = name;
	}
	int cash, people;
	string curP;
	FOR(i,N){
		fin>>curP;
		fin>>cash>>people;
		FOR(j,people){
			fin>>name;
			money[index[name]]+=cash/people;
		}
		if(people>0){
			money[index[curP]]-=cash-cash%people;
		}
		else{
			money[index[curP]]+=cash;
		}
	}
	FOR(i,N){
		fout<<moneyA[i]<<' '<<money[i]<<'\n';
	}
	return 0;
}