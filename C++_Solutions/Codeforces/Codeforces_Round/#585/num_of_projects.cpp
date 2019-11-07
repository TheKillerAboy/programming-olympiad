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

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin>>N;
	vector<int> pos(N);
	vector<int> neg(N);
	vector<int> num(N);

	FOR(i,N){
		cin>>num[i];
	}

	pos[0] = num[0] > 0;
	neg[0] = num[0] < 0;
	FOR1(i,N){
		if(num[i] > 0){
			pos[i] = pos[i-1]+1;
			neg[i] = neg[i-1];
		}
		else if(num[i] < 0){
			pos[i] = neg[i-1];
			neg[i] = pos[i-1]+1;
		}
	}
	ll num_of_pos = 0;
	FOR(i,N){
		num_of_pos += pos[i];
	}
	ll num_of_neg = 0;
	FOR(i,N){
		num_of_neg += neg[i];
	}
	cout<<num_of_neg<<' '<<num_of_pos<<'\n';


	return 0;
}