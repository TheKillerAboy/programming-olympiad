#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(ll i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(ll i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(ll i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(ll i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(ll i_=1;i_<a_;++i_)
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

#define MOD 1000000007

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string line;
	cin>>line;
	ll N = line.size();
	vector<ll> As(N);
	As[0] = line[0] == 'a';
	FOR1(i,N){
		As[i] = As[i-1] + (line[i] == 'a');
	}
	vector<ll> H(N+1);
	H[0] = 0;
	H[1] = 1;
	FORS(2,i,N+1){
		H[i] = 2+2*H[i-2]+H[i-1];
		H[i] %= MOD;
	}
	ll value = 0;
	FOR1(i,N){
		value += (line[i]=='b'?H[As[i-1]]:0);
		value %= MOD;
	}
	cout<<value<<'\n';


	return 0;
}