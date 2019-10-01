#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

#define ll unsigned long long int

ll nCr(ll n, ll r){
	ll out = 1;
	for(ll i = n-r+1; i <= n; i++){
		out*=i;
	}
	for(ll i = 1; i <= r; i++){
		out/=i;
	}
	return out;
}

vector<vector<ll>> comb( ll N, ll K){
	vector<vector<ll>> combs(nCr(N,K));
	ll curComb = 0;
	vector<ll> bitmask(K,1);
	bitmask.resize(N,0);
	do{
		ll cur = 0;
		vector<ll> current(K,0);	
		for(ll i = 0; i < N; i++){
			if(bitmask[i]){
				current[cur++] = i;
			}
		}
		combs[curComb++] = current;
	}
	while(prev_permutation(bitmask.begin(),bitmask.end()));
	return combs;
}

ll N,K;
vector<pair<ll,pair<ll,ll>>> bids;

ll score(vector<ll> cmb){
	vector<ll> sizes(N);
	ll sum = 0;
	for(auto index : cmb){
		if(sizes[bids[index].second.second] < K && sizes[bids[index].second.first] < K){
			sizes[bids[index].second.second]++;
			sizes[bids[index].second.first]++;
			sum += bids[index].first;
		}
		else{
			return 0;
		}
	}
	return sum;
}

int main(){
	cin>>N>>K;
	bids.resize(N-1);
	ll a,b,c;
	for(ll i = 0; i < N-1; i++){
		cin>>a>>b>>c;
		bids[i] = pair<ll,pair<ll,ll>>{c,pair<ll,ll>{a,b}};
	}
	ll MAX = 0;
	for(ll r = 1; r <= N - 1; r++){
		for(vector<ll> cmb : comb(N-1,r)){
			MAX = max(MAX,score(cmb));
		}
	}
	cout<<MAX<<endl;
}