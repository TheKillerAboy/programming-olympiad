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

vector<set<int>> quarals;
vector<pair<int,int>> skill;
vector<int> start;
map<int,int> loc;
int N,K;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>N>>K;
	skill.resize(N);
	quarals.resize(N);
	start.resize(N);

	int a,b;
	FOR(i,N){
		cin>>a;
		skill[i] = {a,i};
	}
	sort(skill.begin(),skill.end());
	FOR(i,N){
		loc[skill[i].second] = i;
	}
	start[0] = -1;
	FOR1(i,N){
		if(skill[i].first == skill[i-1].first) start[i] = start[i-1];
		else start[i] = i-1;
	}
	FOR(i,K){
		cin>>a>>b;
		quarals[a-1].insert(b-1);
		quarals[b-1].insert(a-1);
	}
	int canM;
	vector<int> canMentor(N);
	FOR(i,N){
		canM = start[i] + 1;
		FORA(opp,quarals[skill[i].second]){
			if(loc[opp] <= start[i]) -- canM;
		}
		canMentor[skill[i].second] = (canM>0?canM:0);
	}
	FOR(i,N){
		cout<<canMentor[i]<<' ';
	}
	cout<<'\n';




	return 0;
}