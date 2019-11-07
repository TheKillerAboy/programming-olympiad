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

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	vector<set<int>> seq(5);
	int N,v;
	FOR(i,5){
		cin>>N;
		FOR(j,N){
			cin>>v;
			seq[i].insert(v);
		}
	}
	set<pii> top;
	int count  = 0;
	FOR(i,5){
		if(!seq[i].empty()){
			top.insert({*seq[i].begin(),i});
			seq[i].erase(seq[i].begin());
		}
	}
	while(top.size() >= 3){
		TRACECE(top,TRACEP) TRACE(count)
		pii thrid;
		int i = 0;
		FORA(value,top){
			if(i==3) break;
			thrid = value;
			++i;
		}
		int index,time;
		pii first = *top.begin();
		if(thrid.first - first.first < 1000){
		pii group = {first.first,thrid.first};
			++count;
			int initSize = top.size();
			set<pii> addLater;
			FOR(i,initSize){
				if(top.empty()) break;
				tie(time,index) = *top.begin();
				if(time - first.first >= 1000) break;
				group.second = max(group.second,time);
			top.erase(top.begin());
				if(!seq[index].empty()){
					addLater.insert({*seq[index].begin(),index});
					seq[index].erase(seq[index].begin());
				} 
			}
			FORA(value,addLater) top.insert(value);
			TRACEE(group,TRACEP)
		}
		else{
			tie(time,index) = *top.begin();	
			top.erase(top.begin());
			if(!seq[index].empty()){
				top.insert({*seq[index].begin(),index});
				seq[index].erase(seq[index].begin());
			} 
		}
	}
	cout<<count<<'\n';


	return 0;
}