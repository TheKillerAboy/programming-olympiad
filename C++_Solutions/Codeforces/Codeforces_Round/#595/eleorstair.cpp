#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define FORA(e_,c_) for(auto e_:c_)

int N,C;
vector<vector<int>> DP;
vector<int> stairs;
vector<int> ele;

int dp(int i,bool inEle){
	if(i==0){
		return 0;
	}
	if(DP[i][inEle] == -1){
		DP[i][inEle] = min(ele[i-1] + dp(i-1,true) + (inEle?0:C),stairs[i-1] + dp(i-1,false));
	}
	return DP[i][inEle];
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>N>>C;
	DP.resize(N+1,vector<int>(2,-1));
	stairs.resize(N-1);
	ele.resize(N-1);
	FOR(i,N-1){
		cin>>stairs[i];
	}
	FOR(i,N-1){
		cin>>ele[i];
	}
	FOR(i,N){
		cout<<dp(i,false)<<' ';
	}
	return 0;
}