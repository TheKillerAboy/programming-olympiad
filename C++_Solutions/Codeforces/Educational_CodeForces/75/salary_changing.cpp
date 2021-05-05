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

#define ull unsigned long long int
#define INF LLONG_MAX

vector<pair<ll,ll>> salaries;
vector<ll> salariesMax;
ll N,cash,M;

ll BS(ll l, ll r){
	ll mid = (l+r)>>1;
	if(mid == l){return l;}
	bool hasMid = false;
	multiset<pair<ll,ll>,greater<pair<ll,ll>>> stricklyLess;
	FORA(ele,salaries){
		if(ele.first < mid){
			stricklyLess.insert(ele);
		}
		else if(ele.first == mid){
			hasMid = true;
		}
	}
	ll stricklyLessSize = stricklyLess.size();
	ll neededCost = 0;
	while(stricklyLessSize > M && !stricklyLess.empty()){
		pair<ll,ll> currentEle = *stricklyLess.begin();
		stricklyLess.erase(stricklyLess.begin());
		if(currentEle.second >= mid){
			neededCost += mid - currentEle.first;
			--stricklyLessSize;
			hasMid = true;
		}
	}
	if(neededCost > cash || stricklyLessSize > M || !hasMid){
		return BS(l,mid);
	}
	return BS(mid,r);
}

ll query(){
	sort(salaries.begin(),salaries.end());
	sort(salariesMax.begin(),salariesMax.end());
	M = N/2;
	return BS(salaries[M].first,salariesMax[M]+1);
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll Q;
	ll a,b;
	cin>>Q;
	FOR(i,Q){
		cin>>N>>cash;
		salaries.resize(N);
		salariesMax.resize(N);
		FOR(j,N){
			cin>>a>>b;
			salaries[j] = {a,b};
			salariesMax[j] = {b};
			cash-=a;
		}
		cout<<query()<<'\n';
	}

	return 0;
}

/*
1
5 100
2 100
2 100
4 100
5 100
6 100
*/