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
#define pii pair<int,int>

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n;
	cin>>n;
	vector<ll> factors;
	int size = 0;
	if(n == 1){
		cout<<1<<'\n';
		return 0;
	}
	factors.reserve(100000);
	if(n%2==0){
		factors.push_back(2);
		++size;
		while(n%2==0){
			n/=2;
		}
	}
	for(ll i = 3; i <= sqrt(n); i+=2){
		if(n%i==0){
			factors.push_back(i);
			++size;
			while(n%i==0){
				n/=i;
			}
		}
	}
	if(n>1){
		++size;
		factors.push_back(n);
	}
	if(size > 1){
		cout<<1<<'\n';
	}
	else{
		cout<<factors[0]<<'\n';
	}

	return 0;
}