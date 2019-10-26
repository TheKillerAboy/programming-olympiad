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

int N,K,D;
vector<int> programs;

int query(){
	vector<int> totals(K+1,0);
	int uniques = 0;
	FOR(i,D){
		if(totals[programs[i]] == 0){
			++uniques;
		}
		++totals[programs[i]];
	}
	int MIN = uniques;
	FORS(D,i,N){
		--totals[programs[i-D]];
		if(totals[programs[i-D]] == 0){
			--uniques;
		}
		if(totals[programs[i]] == 0){
			++uniques;
		}
		++totals[programs[i]];
		MIN = min(MIN,uniques);
	}
	return MIN;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int Q;
	cin>>Q;
	FOR(i,Q){
		cin>>N>>K>>D;
		programs.resize(N);
		FOR(j,N){
			cin>>programs[j];
		}
		cout<<query()<<'\n';
	}


	return 0;
}