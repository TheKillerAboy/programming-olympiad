#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#define FOR(i_,a_) for(ll i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(ll i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(ll i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(ll i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(ll i_=1;i_<a_;++i_)
#define ull unsigned long long int

vector<pair<ll,ll>> salaries;
vector<ll> salariesMax;
ll N;
ll cost;

ll BS(ll l, ll r){
	ll mid = (l+r)>>1;
	if(mid == l){
		return l;
	}
	set<pair<ll,ll>,greater<pair<ll,ll>>> smallerEqual;
	ll striclyBigger = 0;
	bool hasMid = false;
	FORA(s,salaries){
		if(s.first < mid){
			smallerEqual.insert(s);
		}
		else if(s.first == mid){
			hasMid = true;
		}
		else{
			++striclyBigger;
		}
	}
	ll costNeeded = 0;
	ll sizeSE = smallerEqual.size();
	FORA(s,smallerEqual){
		if(sizeSE <= N/2){
			break;
		}
		if(s.second >= mid){
			costNeeded += mid - s.first;
			--sizeSE;
			hasMid = true;
		}
	}
	if(costNeeded > cost || sizeSE > N/2 || !hasMid || striclyBigger > N/2){
		return BS(l,mid);
	}
	return BS(mid,r);
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll Q;
	ll a,b;
	cin>>Q;
	FOR(i,Q){
		cin>>N>>cost;
		salaries.resize(N);
		salariesMax.resize(N);
		FOR(j,N){
			cin>>a>>b;
			salaries[j] = {a,b};
			salariesMax[j] = b;
			cost-=a;
		}
		sort(salariesMax.begin(),salariesMax.end());
		sort(salaries.begin(),salaries.end());
		ll l = salaries[N/2].first;
		ll r = salariesMax[N/2];
		cout<<BS(l,max(l,r) +1)<<'\n';
	}


	return 0;
}