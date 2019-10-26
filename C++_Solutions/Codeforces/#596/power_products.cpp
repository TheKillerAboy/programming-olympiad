#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#define FOR(i_,a_) for(ll i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(ll i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(ll i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(ll i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(ll i_=1;i_<a_;++i_)

#define _ cerr<<' ';
#define _N cerr<<'\n';
#define TRACEV(v_) cerr<<v_;
#define TRACEP(p_) cerr<<"("<<p_.first<<", "<<p_.second<<") ";
#define TRACECE(c_,tt_) for(auto e_:c_){tt_(e_);_;}_N;
#define TRACEC(c_) TRACECE(c_,TRACEV)
#define TRACEE(v_,tt_) tt_(v_);_N;
#define TRACE(v_) TRACEE(v_,TRACEV);
#define TRACEEP(v_) TRACEE(v_,TRACEP);
#define ull unsigned long long int

ll N,K;
map<ll,ll> link;
map<ll,ll> inverse;

inline ll power(ll a, ll b){
	if(b==0) return 1;
	else if(b == 1) return a;
	else{
		ll tmp = power(a,b/2);
		return tmp*tmp*(b%2==0?1:a);
	}
}

void add(ll a){
	ll count = 0;
	ll value = 1;
	ll inv = 1;
	if(a%2==0){
		count = 0;
		while(a%2==0){
			a /= 2;
			++count;
		}
		if(count%K != 0){
			value*=power(2,count%K);
			inv *= power(2,K-count%K);
		}
	}
	for(ll i = 3; i <= sqrt(a); i+=2){
		count = 0;
		while(a%i==0){
			a /= i;
			++count;
		}
		if(count%K != 0){
			value*=power(i,count%K);
			inv *= power(i,K-count%K);
		}
	}
	if(a > 1){
		value*=a;
		inv *= power(a,K-1);
	}
	++link[value];
	inverse[value] = inv;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll a;
	cin>>N>>K;	
	FOR(i,N){
		cin>>a;
		add(a);
	}
	ll count = 0;
	FORA(ele,link){
		if(inverse[ele.first] == ele.first){
			count += ele.second * (ele.second-1);
		}
		else{
			count += ele.second * link[inverse[ele.first]];
		}
	}
	cout<<count/2<<'\n';

	return 0;
}