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

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int Q,N;
	vector<bool> used;
	vector<int> value;
	vector<int> loc;
	cin>>Q;
	FOR(i,Q){
		cin>>N;
		used = vector<bool>(N-1,false);
		value.resize(N);
		loc.resize(N);
		FOR(j,N){
			cin>>value[j];
			--value[j];
			loc[value[j]] = j;
		}
		int cur = 0;
		while(cur < N){
			if(loc[cur] > cur){
				if(!used[loc[cur]-1]){
					used[loc[cur]-1] = true;
					value[loc[cur]] ^= value[loc[cur]-1] ^= value[loc[cur]] ^= value[loc[cur]-1];
					loc[value[loc[cur]]] = loc[cur];
					loc[cur] = loc[cur]-1;
				}
				else{
					++cur;
				}
			}
			else{
				++cur;
			}
		}
		FOR(i,N){
			cout<<value[i]+1<<' ';
		}
		cout<<'\n';
	}


	return 0;
}