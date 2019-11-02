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


//TEMPLATE START

template<typename T>
struct PrevSum{
	vector<T> pref;
	PrevSum(vector<T>& arr){
		pref.resize(arr.size());
		pref[0] = arr[0];
		for(size_t i = 1; i < arr.size(); ++i) pref[i] = pref[i-1] + arr[i];
	}
	inline T query(int l, int r){
		return l>r?(r==0?pref[l]:pref[l]-pref[r-1]):(l==0?pref[r]:pref[r]-pref[l-1]);
	}
};

//TEMPLATE END

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N,Q;
	cin>>N>>Q;
	vector<int> R(N),C(N);
	int a;
	FOR(i,N) {cin>>a;R[i]=a%2;}
	FOR(i,N) {cin>>a;C[i]=a%2;}
	PrevSum<int> RST(R);
	PrevSum<int> CST(C);
	int ra,ca,rb,cb;
	FOR(i,Q){
		cin>>ra>>ca>>rb>>cb;
		tie(ra,rb) = minmax({ra-1,rb-1});
		tie(ca,cb) = minmax({ca-1,cb-1});
		if(RST.query(ra,rb)%(rb-ra+1) == 0 && CST.query(ca,cb)%(cb-ca+1) == 0 && R[rb] == C[cb]) cout<<"YES"<<'\n';
		else cout<<"NO"<<'\n';
	}


	return 0;
}