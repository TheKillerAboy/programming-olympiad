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
#define TRACEP(p_) cerr<<'('<<p_.first<<", "<<p_.second<<") ";
#define TRACECE(c_,tt_) for(auto e_:c_) tt_(e_); _ _N
#define TRACEC(c_) TRACECE(c_,TRACEV)
#define TRACEE(v_,tt_) tt_(v_);_N
#define TRACE(v_) TRACEE(v_,TRACEV)
#define TRACEEP(v_) TRACEE(v_,TRACEP)

#define ll long long int
#define ull unsigned long long int

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int Q,N,a;
	cin>>Q;
	FOR(i,Q){
		cin>>N;
		map<int,int> distinc;
		vector<int> dFirst(N);
		vector<int> dLast(N);
		int total = 0;
		FOR(j,N){
			cin>>a;
			if(distinc.find(a) == distinc.end()){
				distinc[a] = total;
				dFirst[total++] = j;
			}
			dLast[distinc[a]] = j;
		}
		int MAX = 1;
		int current = 1;
		for(auto it = distinc.begin(); next(it) != distinc.end(); ++it){
			// TRACEV(dLast[(*it).second]) _ TRACEV(dFirst[(*next(it)).second]) _N
			if(dLast[(*it).second] < dFirst[(*next(it)).second]) ++current;
			else current = 1;
			MAX = max(MAX,current);
		}
		cout<<total - MAX<<'\n';
	}


	return 0;
}

/*
2
1
1
2
1 1
*/