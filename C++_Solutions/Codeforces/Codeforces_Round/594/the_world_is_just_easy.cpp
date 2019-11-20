#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(int i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(int i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(int i_=1;i_<a_;++i_)
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
#define pii pair<int,int>

inline void swap(char& a_,char& b_){char SWAP_ = a_; a_ = b_; b_ = SWAP_;}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	string line;
	cin>>N>>line;
	pair<int,pair<int,int>> best = {0,{-1,-1}};
	int count = 0;
	FOR(i,N){
		if(line[i] == '(') ++count;
		else if(line[i] == ')') --count;
	}
	FOR(i,N){
		FOR(j,N){
			if(i<j) break;
			swap(line[i],line[j]);
			
			int start;
			FOR(k,N)if(line[k] == '('){
				start = k;
				break;
			}
			int count = line[i]=='('?1:-1;
			bool pos = true;
			int minCorrect = 0;
			FOR1(k,N){
				if(line[k] == '(') ++count;
				else --count;
				minCorrect = min(minCorrect,count);
			}
			best = max(best,{-minCorrect,{j,i}});
			swap(line[i],line[j]);
		}
	}
	cout<<best.first<<'\n';
	cout<<best.second.first+1<<' '<<best.second.second+1<<'\n';

	return 0;
}