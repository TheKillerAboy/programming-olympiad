#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(int i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(int i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(int i_=1;i_<a_;++i_)
#define ll long long int
#define ull unsigned long long int

inline ll gcd(ll a, ll b){
	return b>a?gcd(b,a):(b==0?a:gcd(b,a%b));
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N;
	cin>>N;
	ll GCD;
	ll a;
	cin>>GCD;
	FOR(i,N-1){
		cin>>a;
		GCD = gcd(GCD,a);
	}
	map<int,int> counter;
	while(GCD%2==0){
		++counter[2];
		GCD/=2;
	}
	for(int i =3; i <= sqrt(GCD); i+=2){
		while(GCD%i==0){
			++counter[i];
			GCD/=i;
		}
	}
	if(GCD > 1){
		++counter[GCD];
	}
	ll count = 1;
	FORA(e,counter){
		count*=e.second+1;
	}
	cout<<count<<'\n';


	return 0;
}