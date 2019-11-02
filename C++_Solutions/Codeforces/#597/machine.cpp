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

#define MOD 1000000007

#define ll long long int
#define ull unsigned long long int

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	vector<ll> machine(100000);
	machine[0] = 1;
	machine[1] = 1;
	FORS(2,i,100000) machine[i] = (machine[i-2] + machine[i-1])%MOD;
	string word;
	cin>>word;
	vector<int> con;
	con.reserve(word.size());
	int curSize = 0;
	ll out = 1;
	FOR(i,word.size()){
		if(word[i] == 'n'){
			if(i>0 && word[i-1] != 'n'){
				con.push_back(curSize);
				curSize = 0;
			}
		}
		else if(word[i] == 'u'){
			if(i>0 && word[i-1] != 'u'){
				con.push_back(curSize);
				curSize = 0;
			}
		}
		else if(word[i] == 'm' || word[i] == 'w') out = 0;
		else{
			con.push_back(curSize);
			curSize = 0;
		}
		++curSize;
	}
	con.push_back(curSize);
	FOR(i,con.size()){
		out *= machine[con[i]];
		out %= MOD;
	}
	cout<<out<<'\n';


	return 0;
}