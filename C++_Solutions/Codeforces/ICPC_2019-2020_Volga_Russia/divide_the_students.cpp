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

int a,b,c;

int BS(int l, int r){
	int mid = (l+r)>>1;
	if(mid == l) return r;
	if(2*mid < a || 2*mid < c || mid*3 < a+b+c){
		return BS(mid,r);
	}
	vector<int> groups(3);
	vector<int> left = {a,b,c};
	int j = 0;
	int alast = 0;
	FOR(i,3){
		while(groups[i] != mid && left[2] != 0){
			// TRACEC(left)
			// TRACEC(groups)
			int SWAP = left[j];
			left[j] -= min(left[j],mid-groups[i]);
			groups[i] += min(SWAP,mid-groups[i]);
			if(left[j] == 0){ 
				if(j==0) alast = i;
				++j;
				if(j==2 && alast == i) break; 
			}
		}
	}
	FOR(j,3){
		if(left[j]!=0) return BS(mid,r);
	}
	return BS(l,mid);
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int Q;
	cin>>Q;
	FOR(i,Q){
		cin>>a>>b>>c;
		cout<<BS(0,max(a,max(b,c)))<<'\n';
	}


	return 0;
}