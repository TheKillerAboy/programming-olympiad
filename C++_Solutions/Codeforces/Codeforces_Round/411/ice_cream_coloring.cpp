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

vector<int> sub_graphs;
vector<int> sub_graphs_size;
vector<int> sub_graphs_color;

int uFind(int a){
	int current = a;
	while(sub_graphs[current] != -1) current = sub_graphs[current];
	if(current != a) sub_graphs[a] = current;
	return current;
}

inline void swap(int& a, int& b) {a^=b^=a^=b;}

void uMerge(int a, int b){
	int aP = uFind(a), bP = uFind(b);
	if(aP!=bP){
		if(sub_graphs_size[aP] < sub_graphs_size[bP]) swap(aP,bP);
		sub_graphs[bP] = aP;
		sub_graphs_size[aP] += sub_graphs_size[bP];
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N,M;
	cin>>N>>M;
	sub_graphs.resize(M,-1);
	sub_graphs_size.resize(M,1);
	sub_graphs_color.resize(M,1);
	int a,c1,c2;
	int MAX_SIZE = 1;
	FOR(i,N){
		cin>>a;
		if(a>0) {cin>>c1;--c1;}
		if(a>1){
			FOR(j,a-1){
			cin>>c2;
			--c2;
				uMerge(c1,c2);
			}
			MAX_SIZE = max(MAX_SIZE,sub_graphs_size[uFind(c1)]);
		}
	}
	FOR(i,N-1) cin>>a;
	cout<<MAX_SIZE<<'\n';
	FOR(i,M){
		cout<<sub_graphs_color[uFind(i)]++<<' ';
	}
	cout<<'\n';

	return 0;
}