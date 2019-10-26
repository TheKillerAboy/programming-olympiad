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

inline ll pow2(int a){
	return 1<<a;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N,P;
	cin>>N>>P;
	if(P == 0){
		cout<<__builtin_popcountll(N)<<'\n';
		return 0; 
	}
	FOR1(i,N-i*P+1){
		if(N-i*P > 0 && __builtin_popcountll(N-i*P)<=i){
			cout<<i<<'\n';
			return 0;
		}
	}
	cout<<-1<<'\n';


	return 0;
}