#include <map>
#include <iostream>
#include <climits>

using namespace std;

#define ll long long int

ll N,M,A;

map<ll,ll> DP;

#define INF LLONG_MAX-1;

ll dp(ll c);

ll getDP(ll c){
	if(c >= M){
		return c-M;
	}
	if(DP.find(c) == DP.end()){
		DP[c] = INF;
		DP[c] = dp(c);
	}
	return DP[c];
}

ll dp(ll c){
	ll out = INF;
	if(c > 1){
		out = min(out,getDP(c-1)+1);
	}
	return min(out,getDP(c*A)+1);
}

int main(){
	cin>>A>>N>>M;
	cout<<getDP(N)<<endl;
	return 0;
}