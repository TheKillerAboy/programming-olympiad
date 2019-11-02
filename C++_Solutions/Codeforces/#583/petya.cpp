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
#define _T cerr<<'\t';
#define TRACEV(v_) cerr<<v_;
#define TRACEP(p_) cerr<<"("<<p_.first<<", "<<p_.second<<") ";
#define TRACECE(c_,tt_) for(auto e_:c_){tt_(e_);_;}_N;
#define TRACEC(c_) TRACECE(c_,TRACEV)
#define TRACEE(v_,tt_) tt_(v_);_N;
#define TRACE(v_) TRACEE(v_,TRACEV);
#define TRACEEP(v_) TRACEE(v_,TRACEP);

#define ll long long int
#define ull unsigned long long int

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin>>N;
	vector<pair<int,pair<int,int>>> chains(N);
	int a;
	FOR(i,N){
		cin>>a;
		chains[i] = {a,{2*i+1,2*i+2}};
	}
	sort(chains.begin(),chains.end(),greater<pair<int,pair<int,int>>>());
	vector<int> mainChain(N);
	vector<pair<int,int>> connections(2*N-1);
	FOR(i,N){
		mainChain[i] = chains[i].second.first;
	}
	int j = 0;
	FOR(i,N-1){
		connections[j++] = {mainChain[i],mainChain[i+1]};
	}
	FOR(i,N){
		if(chains[i].first == N){
			connections[j++] = {mainChain.back(),chains[i].second.second};
			mainChain.push_back(chains[i].second.second);
		}
		else{
			if(i+chains[i].first-1 == mainChain.size()-1){
				mainChain.push_back(chains[i].second.second);
			}
			connections[j++] = {mainChain[i+chains[i].first-1],chains[i].second.second};
		}
	}
	sort(connections.begin(),connections.end());
	FOR(i,2*N-1){
		cout<<connections[i].first<<' '<<connections[i].second<<'\n';
	}

	return 0;
}