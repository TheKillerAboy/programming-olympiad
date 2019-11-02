#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(ull i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(int i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(int i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(ull i_=1;i_<a_;++i_)
#define FORIT(it_,c_) for(auto it_ = c_.begin(); it_!=c_.end();++it_)

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
	ull N;
	cin>>N;
	ull L,W;
	vector<pair<ull,ull>> lands(N);
	FOR(i,N){
		cin>>L>>W;
		if(L>W) lands[i] = {W,L};
		else lands[i] = {L,W};
	}
	sort(lands.begin(),lands.end(),greater<pair<ull,ull>>());
	vector<ull> bestTo(N);
	TRACECE(lands,TRACEP)
	bestTo[0] = lands[0].second;
	FOR1(i,N){
		bestTo[i] = max(bestTo[i-1],lands[i].second);
	}
	ull best = 0;
	FOR1(i,N){
		best = max(best,2*min(bestTo[i-1],lands[i].second)*lands[i].first);
	}
	best = max(best,lands[0].first*lands[0].second);
	cout<<best/2<<(best%2?".5":".0")<<'\n';
	return 0;
}