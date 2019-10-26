#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define FOR(i_,a_) for(ll i_=0;i_<a_;++i_)
#define FORR(i_,a_) for(ll i_=a_-1;i_>=0;--i_)

inline ll power(ll a,ll b){
	return (b==0?1:(b==1?a:power(a,b/2)*power(a,b/2+b%2)));
}

ll query(ll n){
	ll upper = floor(log(n)/log(3))+1;
	vector<ll> fill(upper+1,1);
	ll value = power(3,upper+1);
	bool change = true;
	while(change){
		// cout<<value<<'\n';
		change = false;
		FOR(i,n){
			if(value>n){
				if(fill[i] == 1){
					value -= power(3,i);
					fill[i] = 0;
					change = true;
				}
			}
			else{
				break;
			}
		}
		FOR(i,n){
			if(value<n){
				if(fill[i] == 0){
					fill[i] = 1;
					value += power(3,i);
					change = true;
				}
			}
			else{
				break;
			}
		}
	}
	return value;
}

int main(){
	// cin.tie(0);
	// ios::sync_with_stdio(false);
	ll Q,N;
	cin>>Q;
	FOR(i,Q){
		cin>>N;
		cout<<query(N)<<'\n';
	}
	return 0;
}











