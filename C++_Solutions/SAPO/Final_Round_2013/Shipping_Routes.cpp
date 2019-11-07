#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

#define ll long long int

map<ll,set<ll>> connectionsCount;
vector<set<ll>> connections;

ll N,M;

int main(){
	cin>>N>>M;
	connections.resize(N);
	ll a,b;
	for(ll i = 0; i < N; i++){
		connectionsCount[0].insert(i);
	}
	for(ll i = 0; i < M; i++){
		cin>>a>>b;
		connectionsCount[connections[a-1].size()].erase(a-1);
		connections[a-1].insert(b-1);
		connectionsCount[connections[a-1].size()].insert(a-1);
		connectionsCount[connections[b-1].size()].erase(b-1);
		connections[b-1].insert(a-1);
		connectionsCount[connections[b-1].size()].insert(b-1);
	}
	set<ll> output;
	while(connectionsCount[1].size()>0){
		ll current = *connectionsCount[1].begin();
		output.insert(current+1);
		connectionsCount[1].erase(connectionsCount[1].begin());
		ll parent = *connections[current].begin();
		connectionsCount[connections[parent].size()].erase(parent);
		connections[parent].erase(current);
		connectionsCount[connections[parent].size()].insert(parent);
	}
	for(ll ele : connectionsCount[0]){
		output.insert(ele + 1);
	}
	for(ll ele : output){
		cout<<ele<<endl;
	}
}