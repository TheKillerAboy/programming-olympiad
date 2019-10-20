#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORR(i_,a_) for(int i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(int i_=1;i_<a_;++i_)
#define ll long long int
#define ull unsigned long long int

inline ll gcd(ll a, ll b){
	return b>a?gcd(b,a):(b==0?a:gcd(b,a%b));
}
inline ll lcm(ll a, ll b){
	return a*b/gcd(a,b);
}
inline void swap(ll& a, ll& b){
	a^=b^=a^=b;
}

ll Q,N;
ll needed;
ll xP,yP;
ll xPeriod,yPeriod;
vector<ll> tickets;

ll priceFor(ll nTickets){
	ll out = 0;
	ll xyT = nTickets/lcm(xPeriod,yPeriod);
	ll xT = nTickets/xPeriod - xyT;
	ll yT = nTickets/yPeriod - xyT;
	for(ll i = 0; i < xyT; ++i){
		out+=tickets[i] * (xP+yP);
	}
	for(ll i = xyT; i < xyT + xT; ++i){
		out+=tickets[i] * xP;
	}
	for(ll i = xyT + xT; i < xyT + xT + yT; ++i){
		out+=tickets[i] * yP;
	}
	return out;
}

ll bS(ll l, ll r){
	ll mid = (l+r)>>1;
	if(mid == l || mid == r){
		if(priceFor(r)>=needed){
			return r;
		}
		return -1;
	}
	ll midPrice = priceFor(mid);
	if(midPrice < needed){
		return bS(mid,r);
	}
	return bS(l,mid);
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>Q;
	FOR(i,Q){
		cin>>N;
		tickets.resize(N);
		FOR(j,N){
			cin>>tickets[j];
			tickets[j]/=100;
		}
		sort(tickets.begin(),tickets.end(),greater<ll>());
		cin>>xP>>xPeriod;
		cin>>yP>>yPeriod;
		if(yP>xP){
			swap(xP,yP);
			swap(xPeriod,yPeriod);
		}
		cin>>needed;
		cout<<bS(0,N)<<'\n';
	}


	return 0;
}