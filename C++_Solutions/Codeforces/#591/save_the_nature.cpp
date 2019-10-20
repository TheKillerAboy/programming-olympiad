#include <bits/stdc++.h>

using namespace std;

#define INF LLONG_MAX
#define ll long long int

ll gcd(ll a, ll b){
	if(b>a){
		return gcd(b,a);
	}
	if(b == 0){
		return a;
	}
	return gcd(b,a%b);
}

ll lcm(ll a, ll b){
	return a*b/gcd(a,b);
}

ll n;
ll xc,yc;
ll x,y;
ll q;
ll k;
ll t;
vector<ll> tickets;
vector<ll> ps;

ll bestPrice(ll tleft){
	ll xyuse = tleft/lcm(xc,yc);
	if(xc == yc){
		return ps[xyuse-1]*(x+y)/100;
	}	ll xuse = tleft/xc - xyuse;
	ll yuse = tleft/yc - xyuse;
	ll firstxyx = ps[xyuse+xuse-1];
	ll firstxyxy = ps[xyuse + xuse + yuse - 1];
	ll firstxy = ps[xyuse-1];
	return firstxy*(x+y)/100 + (firstxyx-firstxy)*x/100 + (firstxyxy - firstxyx)*y/100;
}

ll binarySeach(ll left, ll right){
	if(bestPrice(right) < k){
		return -1;
	}
	if(left >= right || abs(left-right) <= 1){
		if(abs(bestPrice(left) - k) < abs(bestPrice(right) - k)){
			return left;
		}
		return right;
	}
	if(bestPrice((left+right)>>1) < k){
		return binarySeach((left+right)>>1,right);
	}
	return binarySeach(left,(left+right)>>1);
}

void swap(ll& a, ll& b){
	a = a^b;
	b = a^b;
	a = a^b;
}

int main(){
	cin>>q;
	for(ll i = 0; i < q; ++i){
		cin>>n;
		tickets.resize(n);
		ps.resize(n);
		for(ll j = 0; j < n; ++j){
			cin>>tickets[j];
		}
		sort(tickets.begin(),tickets.end(),greater<int>());
		ps[0] = tickets[0];
		for(ll j = 1; j < n; ++j){
			ps[j] = ps[j-1]+tickets[j];
		}
		cin>>x>>xc>>y>>yc;
		if(y>x){
			swap(x,y);
			swap(xc,yc);
		}
		cin>>k;
		cout<<binarySeach(0,n)<<'\n';
	}

	return 0;
}