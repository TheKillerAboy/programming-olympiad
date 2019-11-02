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

#define MOD 1000000007

inline ll mulM(ll a,ll b){
	return (a*b)%MOD;
}

inline ll subM(ll a, ll b){
	ll out = a-b;
	while(out < 0) out += MOD;
	return out;
}

inline ll addM(ll a, ll b){
	return (a+b)%MOD;
}

inline ll powerM(ll a, ll b){
	if(b == 0) return 1;
	else if(b==1) return a;
	ll tmp = powerM(a,b/2);
	return mulM(mulM(tmp,tmp),(b%2?a:1));
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll M,N;
	cin>>M>>N;
	cout<<powerM(subM(powerM(2,N),1),M)<<'\n';


	return 0;
}