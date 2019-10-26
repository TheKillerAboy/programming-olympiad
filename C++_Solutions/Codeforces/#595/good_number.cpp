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

inline int power(int a, int b){
	if(b==0) return 1;
	else if(b==1) return a;
	else{
		int tmp = power(a,b/2);
		return tmp*tmp*(b%2==1?a:1);
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll Q,N,M;
	cin>>Q;
	FOR(i,Q){
		cin>>N;
		M = floor(log(N)/log(3))+2;
		// TRACEV(M) _ TRACEV(N) _N
		vector<int> base(2*M);
		int last2 = -1;
		FORR(i,M){
			base[i] = N/power(3,i);
			if(base[i] == 2 && last2 == -1) last2 = i; 
			N = N%power(3,i);
		}
		TRACEC(base);
		FOR(i,2*M){
			if(base[i] == 2){
				base[i] = 0;
				if(base[i+1] != 2){
					if(base[i+1] == 1 || i >= last2){
						base[i+1] += 1;
					}
				}
				else if(i<last2){
					base[i] = 0;
				}
			}
		}
		TRACEC(base);
		ll out = 0;
		ll mul = 1;
		FOR(i,2*M){
			out += mul * base[i];
			mul *= 3;
		}
		cout<<out<<'\n';
	}


	return 0;
}