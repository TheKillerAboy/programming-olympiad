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

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N,M,K;
	cin>>N;
	if(N%2==0){M=N;K=N-1;}
	else{M=N-1;K=N;}
	cout<<((M/2)*(M/2+1) - (K+1)/2 - ((K-1)/2)*((K-1)/2 + 1))<<'\n';


	return 0;
}