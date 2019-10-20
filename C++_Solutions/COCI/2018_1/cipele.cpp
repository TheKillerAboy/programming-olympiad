#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define ll long long int

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N,M;
	cin>>N>>M;
	vector<ll> leftShoes(N);
	vector<ll> rightShoes(M);
	FOR(i,N){
		cin>>leftShoes[i];
	}
	FOR(i,M){
		cin>>rightShoes[i];
	}
	sort(leftShoes.begin(),leftShoes.end());
	sort(rightShoes.begin(),rightShoes.end());
	int pairs = min(M,N);
	ll minimalA = 0;
	FOR(i,pairs){
		minimalA = max(minimalA,abs(leftShoes[i]-rightShoes[i]));
	}
	ll minimalB = 0;
	FOR(i,pairs){
		minimalB = max(minimalB,abs(leftShoes[N-1-i]-rightShoes[M-1-i]));
	}
	cout<<min(minimalA,minimalB)<<'\n';


	
	return 0;
}