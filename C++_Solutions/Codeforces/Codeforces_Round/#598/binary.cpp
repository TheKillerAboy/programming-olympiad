#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(ll i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(ll i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(ll i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(ll i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(ll i_=1;i_<a_;++i_)
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
	ll Q;
	cin>>Q;
	ll N,k;
	string line;
	FOR(_i,Q){
		cin>>N>>k>>line;
		ll cnt = 0;
		bool isDone = false;
		FOR(i,N){
			if(line[i] == '0'){
				if(cnt < k){
					k -= cnt;
				}
				else{
					FOR(j,i-cnt) cout<<0;
					FOR(j,cnt-k) cout<<1;
					cout<<0;
					FOR(j,k) cout<<1;
					FORS(i+1,j,N) cout<<line[j];
					cout<<'\n';
					isDone = true;
					break;
				}
			}
			else{
				++cnt;
			}
		}
		if(!isDone){
			FOR(j,N-cnt) cout<<0;
			FOR(j,cnt) cout<<1;
			cout<<'\n';
		}
	}


	return 0;
}