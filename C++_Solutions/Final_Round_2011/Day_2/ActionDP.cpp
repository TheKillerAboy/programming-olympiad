#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#include <numeric>

using namespace std;

int N,K;

map<pair<int,int>,int> bids;
vector<vector<map<int,int>>> storedDP;
vector<set<int>> children;

int getBid(int a, int b){
	if(a>b){
		return getBid(b,a);
	}
	auto it = bids.find(pair<int,int>{a,b});
	return it == bids.end() ? 0 : (*it).second;
}

int dp(int node, int parent, int left);

int getDP(int node, int parent, int left){
	if(storedDP[node][left-(K-1)].find(parent+1) == storedDP[node][left-(K-1)].end()){
		return dp(node,parent,left);
	}
	return storedDP[node][left-(K-1)][parent+1];
}

void setBid(int a, int b, int c){
	if(a>b){
		setBid(b,a,c);
		return;
	}
	bids[pair<int,int>{a,b}] = c;
}

int dp(int node, int parent, int left){
	set<tuple<int,int,int>,greater<tuple<int,int,int>>> bestChildren;
	for(int child : children[node]){
		if(child != parent){
			bestChildren.insert({getDP(child,node,K-1) + getBid(child,node),child,1});
			bestChildren.insert({getDP(child,node,K),child,0});
		}
	}

	storedDP[node][left-(K-1)][parent+1] = 0;
	int i = 0;
	auto it = bestChildren.begin();
	set<int> inBest;
	while(it != bestChildren.end()){
		if(inBest.find(get<1>(*it)) == inBest.end()){
			if(i < left && get<2>(*it)){
				storedDP[node][left-(K-1)][parent+1] += get<0>(*it);
				inBest.insert(get<1>(*it));
				i++;
			}
			else if(!get<2>(*it)){
				storedDP[node][left-(K-1)][parent+1] += get<0>(*it);
				inBest.insert(get<1>(*it));
			}
		}
		advance(it,1);
	}
	return storedDP[node][left-(K-1)][parent+1];
}

int main(){
	cin>>N>>K;
	storedDP.resize(N,vector<map<int,int>>(2));
	children.resize(N);
	int a, b, c;
	for(int i = 0; i < N-1; i++){
		cin>>a>>b>>c;
		setBid(a-1,b-1,c);
		children[a-1].insert(b-1);
		children[b-1].insert(a-1);
	}
	int MAX = 0;
	for(int i = 0; i < N; i++){
		cout<<i<<' '<<getDP(i,-1,K)<<endl;
		MAX = max(MAX,getDP(i,-1,K));
	}
	cout<<MAX<<endl;
}