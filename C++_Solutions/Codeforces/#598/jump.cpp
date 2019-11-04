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
	int N,M,D;
	cin>>N>>M>>D;
	vector<int> platforms(M);
	int p;
	int sum = 0;
	FOR(i,M){
		cin>>platforms[i];
		sum += platforms[i];
	}
	int index = 0;
	if(sum >= N-(M+1)*(D-1)){
		cout<<"YES\n";
		int D1 = (N-sum) % (M+1);
		int Dis = (N-sum) / (M+1);
		FOR(i,M){
			if(D1>0){
				FOR(i,Dis+1) cout<<0<<' ';
				--D1;
			}
			else{
				FOR(i,Dis) cout<<0<<' ';
			}
			FOR(i,platforms[index]) cout<<index+1<<' ';
			++index;
		}
		FOR(i,Dis)cout<<0<<' ';
		cout<<'\n';
	}
	else cout<<"NO\n";


	return 0;
}