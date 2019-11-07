#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(int i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(int i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(int i_=1;i_<a_;++i_)
#define FORIT(it_,c_) for(auto it_ = c_.begin(); it_!=c_.end();++it_)

#define _ cerr<<' ';
#define _N cerr<<'\n';
#define _T cerr<<'\t';
#define TRACEV(v_) cerr<<v_;
#define TRACEP(p_) cerr<<"("<<p_.first<<", "<<p_.second<<") ";
#define TRACECE(c_,tt_) for(auto e_:c_){tt_(e_);_;}_N;
#define TRACEC(c_) TRACECE(c_,TRACEV)
#define TRACEE(v_,tt_) tt_(v_);_N;
#define TRACE(v_) TRACEE(v_,TRACEV);
#define TRACEEP(v_) TRACEE(v_,TRACEP);

#define ll long long int
#define ull unsigned long long int
#define pii pair<int,int>

set<pair<ll,ll>> actions;
set<ll> has;

void get(ll n){
	if(n <= 2) return;
	if(has.find(n) !=  has.end()) return;
	else{
		ll sqr = ceil(sqrt(n));
		actions.insert({sqr,sqr*sqr -n});
		get(sqr);get(sqr*sqr -n );
		has.insert(n);
	}

}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N;
	cin>>N;
	get(N);
	FORA(ele,actions){
		cout<<ele.first<<' '<<ele.second<<'\n';
	}


	return 0;
}