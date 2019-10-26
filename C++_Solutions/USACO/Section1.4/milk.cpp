/*
ID: annekin1
TASK: milk
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
	ifstream fin("milk.in");
	ofstream fout("milk.out");
	int quant,N;
	fin>>quant>>N;
	vector<pair<int,int>> costAmount(N);
	int a,b;
	FOR(i,N){
		fin>>a>>b;
		costAmount[i] = {a,b};
	}
	sort(costAmount.begin(),costAmount.end());
	int amount = 0;
	FOR(i,N){
		if(quant == 0){
			break;
		}
		if(costAmount[i].second > quant){
			amount += quant*costAmount[i].first;
			quant = 0;
		}
		else{
			amount+=costAmount[i].first*costAmount[i].second;
			quant -= costAmount[i].second;
		}
	}
	fout<<amount<<'\n';

	return 0;
}