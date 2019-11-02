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
#define INF INT_MAX/10

vector<vector<vector<int>>> DP;
vector<int> values;
int DIFIN = 0;
	int N;


int dp(int index, int mod,  int dif){
	if(index == N-1) return 0;
	if(abs(values[index] + mod - values[index+1]+dif) > 1) return INF;
	if(DP[index][mod+1][DIFIN] != -1) return DP[index][mod+1][DIFIN];
	int out = INF;
	if(values[index] + mod + dif == values[index+1]) out = dp(index+1,0,dif);
	else if(values[index] + mod + dif == values[index+1]+1) out =  1+dp(index+1,1,dif);
	else if(values[index] + mod + dif == values[index+1]-1) out =  1+dp(index+1,-1,dif);
	DP[index][mod+1][DIFIN] = out;
	return out;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>N;
	DP.resize(N,vector<vector<int>>(3,vector<int>(9,-1)));
	values.resize(N);
	FOR(i,N){
		cin>>values[i];
	}
	int MIN = INF;
	FOR(i,3){
		FOR(j,3){
			int dif = values[1] + j - 1 - (values[0] + i - 1);
			MIN = min(MIN,dp(0,i-1,dif) + abs(i-1));
			++DIFIN;
		}
	}
	cout<<(MIN >= INF ? -1 : MIN)<<'\n';


	return 0;
}