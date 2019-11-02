#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ull unsigned long long int

#define FOR(i_,a_) for(ll i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(ll i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(ll i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(ll i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(ll i_=1;i_<a_;++i_)

#define _ cerr<<' ';
#define _N cerr<<'\n';
#define TRACEV(v_) cerr<<v_;
#define TRACEP(p_) cerr<<"("<<p_.first<<", "<<p_.second<<") ";
#define TRACECE(c_,tt_) for(auto e_:c_){tt_(e_);_;}_N;
#define TRACEC(c_) TRACECE(c_,TRACEV)
#define TRACEE(v_,tt_) tt_(v_);_N;
#define TRACE(v_) TRACEE(v_,TRACEV);
#define TRACEEP(v_) TRACEE(v_,TRACEP);

#define MOD 1000000009

vector<vector<bool>> isRock;
vector<vector<ll>> suffixRocks;
vector<vector<ll>> suffixDRocks;
vector<vector<vector<vector<ll>>>> DP;
ll N,M;

ll dp(ll x, ll y, ll right, ll under);

ll getdp(ll x, ll y, ll right, ll under){
	if(x >= M || y >= N){
		return 0;
	}
	else if(DP[x][y][right][under] == -1){
		DP[x][y][right][under] = dp(x,y,right,under);
	}
	// TRACEV(x) _ TRACEV(y) _ TRACEV(right) _ TRACEV(under) _  TRACE(DP[x][y][right][under])
	return DP[x][y][right][under];
}

inline ll getsuffD(ll x, ll y){
	if(x>=M || y>=N){
		return 0;
	}
	else{
		return suffixDRocks[x][y];
	}
}
inline ll getsuff(ll x, ll y){
	if(x>=M || y>=N){
		return 0;
	}
	else{
		return suffixRocks[x][y];
	}
}

ll dp(ll x, ll y, ll right, ll under){
	if(x == M-1 && y == N-1){
		return 1;
	}
	ll out = 0;
	if(right < M - x-1){
		out += getdp(x+1,y,right,getsuffD(x+1,y+1));
	}
	if(under < N - y-1){
		out += getdp(x,y+1,getsuff(x+1,y+1),under);
	}
	return out % MOD;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>N>>M;
	isRock.resize(M,vector<bool>(N,false));
	DP.resize(M,vector<vector<vector<ll>>>(N,vector<vector<ll>>(M+1,vector<ll>(N+1,-1))));
	suffixRocks.resize(M,vector<ll>(N,0));
	suffixDRocks.resize(M,vector<ll>(N,0));
	string line;
	FOR(i,N){
		cin>>line;
		FOR(j,M){
			isRock[j][i] = line[j] == 'R';
		}
	}
	FOR(i,N){
		suffixRocks[M-1][i] = isRock[M-1][i];
		FORR(j,M-1){
			suffixRocks[j][i] = suffixRocks[j+1][i] + isRock[j][i];
		}
	}
	FOR(j,M){
		suffixDRocks[j][N-1] = isRock[j][N-1];
		FORR(i,N-1){
			suffixDRocks[j][i] = suffixDRocks[j][i+1] + isRock[j][i];
		}
	}
	cout<<getdp(0,0,suffixRocks[0][0],suffixDRocks[0][0])<<'\n';


	return 0;
}