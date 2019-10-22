/*
ID: annekin1
TASK: beads
LANG: C++                 
*/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(int i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(int i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(int i_=1;i_<a_;++i_)
#define ll long long int
#define ull unsigned long long int

int N;
string necklace;
vector<vector<vector<int>>> DP;

int dp(bool r,bool right,int index, int length){
	if(length >= N){
		return N;
	}
	index = (index+N)%N;
	if(DP[index][r][right] != -1){
		return DP[index][r][right];
	}
	int out = 0;
	if((necklace[index] == 'w')||((necklace[index] == 'r' && r)||(necklace[index] == 'b' && !r))){
		out = dp(r,right,index + (right?1:-1),length+1) + 1;
	}
	DP[index][r][right] = out;
	return out;
}

int main(){
	ifstream fin("beads.in");
	ofstream fout("beads.out");
	fin>>N>>necklace;
	DP.resize(N,vector<vector<int>>(2,vector<int>(2,-1)));
	int MAX = 0;
	FOR(i,N){
		MAX = max(MAX,dp(necklace[i] == 'r',0,i,0)+dp(necklace[(i+1)%N] == 'r',1,i+1,0));
	}
	fout<<(MAX>N?N:MAX)<<'\n';

	return 0;
}