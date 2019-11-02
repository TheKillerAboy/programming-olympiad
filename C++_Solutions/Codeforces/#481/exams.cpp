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
	vector<int> days(N,0);
	bool isPos = true;
	multiset<pair<int,tuple<int,int,int>>> queue;
	int a,b,c;
	FOR(i,M){
		cin>>a>>b>>c;
		queue.insert({c,{a-1,b-1,i}});
		if(days[b-1] == 0)
			days[b-1] = M+1;
		else isPos = false;
	}
	int ind, be, examda, need; 
	while(!queue.empty()){
		need = (*queue.begin()).first;
		tie(be,examda,ind) = (*queue.begin()).second;
		queue.erase(queue.begin());
		int index = examda-1;
		while(index >= be && need > 0){
			if(days[index] == 0){
				--need;
				days[index] = ind+1;
			}
			--index;
		}
		if(need > 0) isPos = false;
	}
	if(!isPos) cout<<-1<<'\n';
	else{
		FOR(i,N){
			cout<<days[i]<<' ';
		}
		cout<<'\n';
	}


	return 0;
}