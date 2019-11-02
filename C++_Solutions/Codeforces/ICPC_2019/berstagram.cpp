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
	int N,M;
	cin>>N>>M;
	vector<int> state(N);
	vector<int> pos(N);
	vector<int> posMin(N);
	vector<int> posMax(N);
	FOR(i,N){
		state[i] = i;
		pos[i] = i;
		posMin[i] = i;
		posMax[i] = i;
	}
	int A;
	FOR(i,M){
		cin>>A;
		--A;
		if(pos[A] != 0){
			int B = state[pos[A]-1];
			++pos[B];
			--pos[A];
			state[pos[A]] = A;
			state[pos[B]] = B;
			posMin[A] = min(posMin[A],pos[A]);
			posMin[B] = min(posMin[B],pos[B]);
			posMax[A] = max(posMax[A],pos[A]);
			posMax[B] = max(posMax[B],pos[B]);
		}
	}
	FOR(i,N){
		cout<<posMin[i]+1<<' '<<posMax[i]+1<<'\n';
	}


	return 0;
}