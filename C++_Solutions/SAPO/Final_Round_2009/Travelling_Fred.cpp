#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

#define INF LLONG_MAX
#define ll long long int

vector<vector<ll>> fasterst;
vector<vector<ll>> connectedTo;

ll C,T,F;

void quickestAll(int from, int cur, int curDis){
	for(auto con : connectedTo[cur]){
		if(fasterst[from][con] == INF){
			fasterst[from][con] = curDis+1;
			quickestAll(from, con, curDis+1);
		}
	}
}

int main(){
	cin>>C>>T>>F;
	ll a,b;
	connectedTo.resize(C);
	for(int i =0; i < F; i ++){
		cin>>a>>b;
		connectedTo[a].push_back(b);
	}
	fasterst.resize(C);
	for(int i = 0; i < C; i++){
		fasterst[i].resize(C,INF);
	}
	for(int i = 0; i < T; i++){
		fasterst[i][i] = 0;
		quickestAll(i,i,0);
	}
	vector<int> permu(T);
	for(int i = 0; i < T; i++){
		permu[i] = i;
	}
	ll MIN = INF;
	do{
		ll cur = 0;
		for(int i = 0; i < T-1; i++){
			cur += fasterst[permu[i]][permu[i+1]];
		}
		MIN = min(MIN,cur);
	}
	while(next_permutation(permu.begin()+1,permu.end()));
	cout<<MIN<<endl;

	return 0;
}