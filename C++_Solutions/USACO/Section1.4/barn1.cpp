/*
ID: annekin1
TASK: barn1
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
#define TRACEC(c_) for(auto e_:c_){cout<<e_<<' ';}cout<<'\n';
#define ll long long int
#define ull unsigned long long int

int N,S,C;
vector<int> stall;

int main(){
	ifstream fin("barn1.in");
	ofstream fout("barn1.out");
	fin>>N>>S>>C;
	stall.resize(C);
	FOR(i,C){
		fin>>stall[i];
	}
	sort(stall.begin(),stall.end());
	vector<int> stallempty(C-1);
	FOR(i,C-1){
		stallempty[i] = stall[i+1]-stall[i]-1;
	}
	sort(stallempty.begin(),stallempty.end(),greater<int>());
	TRACEC(stallempty);
	int empty = 0;
	FOR(i,N-1){
		if(i > C-2){
			break;
		}
		empty+=stallempty[i];
	}
	fout<<stall[C-1]-stall[0]+1-empty<<'\n';

	return 0;
}