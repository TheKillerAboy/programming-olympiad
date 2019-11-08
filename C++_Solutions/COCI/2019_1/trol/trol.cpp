#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORR(i_,a_) for(int i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(int i_=1;i_<a_;++i_)
#define ll long long int
#define ull unsigned long long int

ull reduce(ull value){
	ull copy = 0;
	while(value >= 10){
		copy = 0;
		int upper = floor(log10(value))+1;
		for(int i = 0; i < upper; ++i){
			copy += value%10;
			value/=10;
		}
		value = copy;
	}
	return value;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int Q;
	cin>>Q;
	ull l,r;
	ull sum;
	FOR(i,Q){
		sum = 0;
		cin>>l>>r;
		for(ull j = l; j <= r; ++j){
			sum += reduce(j);
		}
		cout<<sum<<'\n';
	}
	return 0;
}