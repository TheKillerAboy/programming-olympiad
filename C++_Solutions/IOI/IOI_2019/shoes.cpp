#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

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
	int N;
	cin>>N;
	set<int> inlist;
	FOR(i,2*N) inlist.insert(i);
	map<int,list<int>> shoes_indexed;
	vector<int> shoes(2*N);
	int a;
	FOR(i,2*N){
		cin>>a;
		shoes_indexed[a].push_back(i);
		shoes[i] = a;
	}
	ordered_set removed;
	int total = 0;
	while(!inlist.empty()){
		TRACE("HELLO")
		int currentShoe = *inlist.begin();
		inlist.erase(inlist.begin());
		removed.insert(currentShoe);
		shoes_indexed[currentShoe].pop_front();

		int nextShoe = shoes_indexed[-currentShoe].front();
		shoes_indexed[-currentShoe].pop_front();
		inlist.erase(inlist.find(nextShoe));
		removed.insert(nextShoe);

		int dif = nextShoe - currentShoe - (removed.order_of_key(nextShoe) - removed.order_of_key(currentShoe+1));
		if(shoes[currentShoe] > 0) ++dif;
		total += dif;
	}
	cout<<total<<'\n';


	return 0;
}