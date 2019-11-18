#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(int i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(int i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(int i_=1;i_<a_;++i_)
#define FORIT(it_,c_) for(auto it_ = c_.begin(); it_!=c_.end();++it_)

#define ll long long int
#define ull unsigned long long int
#define pii pair<int,int>
#define ctoi(c) (c-'0')
#define OUTTEAM "NijeZivotJedanACM"
#define INF INT_MAX

typedef tuple<int,int,string> STANDING;
void parse_out(char& S, int& V, int& X, string out){
	if(out[0] == '-'){
		S = '-';
	}
	else{
		S = out[0];
		X = ctoi(out[1]);
		V = (ctoi(out[3])*10+ctoi(out[4]))*60*60 + (ctoi(out[6])*10+ctoi(out[7]))*60 + (ctoi(out[9])*10+ctoi(out[10]));
	}
}


int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	set<STANDING> standings;

	int M,N;
	char S;
	int V;
	int X;
	cin>>N>>M;
	string teamName;
	string teamStates;
	FOR(i,N){
		cin>>teamName;
		int solved = 0, penality = 0;
		FOR(j,M){
			cin>>teamStates;
			if(teamName == OUTTEAM) continue;
			parse_out(S,V,X,teamStates);
			if(S != '-'){
				++solved;
				penality += (X-1) * 20 * 60 + V;
			}
		}
		if(teamName != OUTTEAM){
			if(solved == 0) penality = INF;
			standings.insert(STANDING{INF-solved,penality,teamName});
		}
	}
	cin>>teamName;
	int solved = 0, penality = 0;
	FOR(j,M){
		cin>>teamStates;
		parse_out(S,V,X,teamStates);
		if(S != '-'){
			++solved;
			penality += (X-1) * 20 * 60 + V;
		}
	}
	standings.insert(STANDING{INF - solved,penality,teamName});
	int i = 0;
	FORA(ele,standings){
		++i;
		if(get<2>(ele) == OUTTEAM){
			cout<<i<<'\n';
			break;
		}
	}


	return 0;
}