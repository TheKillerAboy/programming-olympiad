#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(int i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(int i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(int i_=1;i_<a_;++i_)

#define _ cerr<<' ';
#define _N cerr<<'\n';
#define TRACEV(v_) cerr<<v_;
#define TRACEP(p_) cerr<<"("<<p_.first<<", "<<p_.second<<") ";
#define TRACECE(c_,tt_) for(auto e_:c_){tt_(e_);_;}_N;
#define TRACEC(c_) TRACECE(c_,TRACEV)
#define TRACEE(v_,tt_) tt_(v_);_N;
#define TRACE(v_) TRACEE(v_,TRACEV);
#define TRACEEP(v_) TRACEE(v_,TRACEP);

#define ll long long int
#define ull unsigned long long int

#define MOD 1000000009

vector<vector<bool>> isRock;
vector<vector<int>> suffixRocks;
vector<vector<int>> suffixDRocks;
vector<vector<vector<vector<ll>>>> DP;
int N,M;

ll dp(int x, int y, int right, int under);

ll getdp(int x, int y, int right, int under){
	if(x >= M || y >= N || right == -1 || under == -1){
		return 0;
	}
	else if(DP[x][y][right][under] == -1){
		DP[x][y][right][under] = dp(x,y,right,under);
	}
	TRACEV(x) _ TRACEV(y) _ TRACEV(right) _ TRACEV(under) _  TRACE(DP[x][y][right][under])
	return DP[x][y][right][under];
}

inline ll getsuffD(int x, int y){
	if(x>=M || y>=N){
		return -1;
	}
	else{
		return suffixDRocks[x][y];
	}
}
inline ll getsuff(int x, int y){
	if(x>=M || y>=N){
		return -1;
	}
	else{
		return suffixRocks[x][y];
	}
}

ll dp(int x, int y, int right, int under){
	if(isRock[x][y]){
		if(right < M - x && under < N - y){
			return (getdp(x,y+1,getsuff(x,y+1),under+1) + getdp(x+1,y,right+1,getsuffD(x+1,y))) % MOD;
		}
		else{
			return 0;
		}
	}
	else{
		if(x == M-1 && y == N - 1){
			return 1;
		}
		return (getdp(x,y+1,getsuff(x,y+1),under) + getdp(x+1,y,right,getsuffD(x+1,y))) % MOD;
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>N>>M;
	isRock.resize(M,vector<bool>(N,false));
	DP.resize(M,vector<vector<vector<ll>>>(N,vector<vector<ll>>(M+1,vector<ll>(N+1,-1))));
	suffixRocks.resize(M,vector<int>(N,0));
	suffixDRocks.resize(M,vector<int>(N,0));
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