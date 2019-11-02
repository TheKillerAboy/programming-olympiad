/*
ID: annekin1
TASK: skidesign
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

#define _ cerr<<' ';
#define _N cerr<<'\n';
#define TRACEV(v_) cerr<<v_;
#define TRACEP(p_) cerr<<"("<<p_.first<<", "<<p_.second<<") ";
#define TRACECE(c_,tt_) for(auto e_:c_){tt_(e_);_;}_N;
#define TRACEC(c_) TRACECE(c_,TRACEV)
#define TRACEE(v_,tt_) tt_(v_);_N;
#define TRACE(v_) TRACEE(v_,TRACEV);
#define TRACEEP(v_) TRACEE(v_,TRACEP);

#define ll long long int
#define ull unsigned long long int

int main(){
	ifstream fin("skidesign.in");
	ofstream fout("skidesign.out");
	int N;
	fin>>N;
	multiset<pair<int,int>> hills;
	int a;
	FOR(i,N){
		fin>>a;
		hills.insert({a,0});
	}
	int cost = 0;
	int height,ccost;
	while((*hills.rbegin()).first - (*hills.begin()).first > 17){
		int lowCost = 0;
		auto it = hills.begin();
		lowCost = 1+2*(*it).second;
		while((*next(it)).first == (*it).first){
			it = next(it);
			lowCost += 1+2*(*it).second;
		}
		int topCost = 0;
		it = prev(hills.end());
		topCost = 1+2*(*it).second;
		while((*prev(it)).first == (*it).first){
			it = prev(it);
			topCost += 1+2*(*it).second;
		}
		if(topCost < lowCost){
			int h = (*hills.rbegin()).first;
			auto it = prev(hills.end());
			while((*it).first == h){
				tie(height,ccost) = *it;
				cost += 1 + 2* ccost;
				hills.erase(it);
				hills.insert({height-1,ccost+1});
				it = prev(hills.end());
			}
		}
		else{
			int h = (*hills.begin()).first;
			auto it = hills.begin(); 
			while((*it).first == h){
				tie(height,ccost) = *it;
				cost += 1 + 2* ccost;
				hills.erase(it);
				hills.insert({height+1,ccost+1});
				it = hills.begin();
			}
		}
	}
	fout<<cost<<'\n';
	return 0;
}