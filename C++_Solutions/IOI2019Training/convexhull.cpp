#include <iostream>
#include <climits>
#include <set>
#include <vector>
#include <tuple>
#include <map>

using namespace std;

#define INF LLONG_MAX
#define ll long long int

ll N,K,M;

map<ll,set<tuple<ll,ll,ll>>> routes;

ll mllime(ll A, ll B){
	set<tuple<ll,ll,ll>> queue; //damaged hull distance index;
	queue.insert(tuple<ll,ll,ll>{0,0,A});
	vector<vector<ll>> best(K,vector<ll>(N,INF));
	best[0][A] = 0;

	ll curDamage,curDistance,curIndex;
	ll extraDamage, extraDistance, extraIndex;
	while(!queue.empty()){
		tie(curDamage,curDistance,curIndex) = *queue.begin();
		queue.erase(queue.begin());
		for(auto extraInfo : routes[curIndex]){
			tie(extraIndex,extraDamage,extraDistance) = extraInfo;
			if(curDamage + extraDamage >= K){
				continue;
			}
			auto& bestNext = best[extraDamage+curDamage][extraIndex];
			if(curDistance+extraDistance < bestNext){
				if(bestNext != INF){
					queue.erase(queue.find({extraDamage+curDamage,bestNext,extraIndex}));
				}
				queue.insert({extraDamage+curDamage,curDistance+extraDistance,extraIndex});
				bestNext = curDistance+extraDistance;
			}
		}
	}
	ll MIN = INF;
	for(ll i = 0; i < K; i++){
		MIN = min(MIN,best[i][B]);
	}
	return (MIN == INF ? -1 : MIN);
}

int main(){
	cin>>K>>N>>M;
	ll a,b,t,h;
	for(ll i = 0; i < M; i++){
		cin>>a>>b>>t>>h;
		routes[a-1].insert({b-1,h,t});
		routes[b-1].insert({a-1,h,t});
	}
	ll A,B;
	cin>>A>>B;
	cout<<mllime(A-1,B-1)<<endl;
	return 0;
}