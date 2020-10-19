#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(int i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(int i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(int i_=1;i_<a_;++i_)
#define FORIT(it_,c_) for(auto it_ = c_.begin(); it_!=c_.end();++it_)

#define _ cout<<' ';
#define _N cout<<'\n';
#define _T cout<<'\t';
#define TRACED(_v) cout<<_v;
void TRACEV(string a){TRACED(a);}
void TRACEV(char a){TRACED(a);}
template<typename... Args> void TRACEV(tuple<Args...> t);
template<typename l, typename r> void TRACEV(pair<l,r> t);
template<typename T> void TRACEV(T t){TRACED(t);}
template<template<typename...> class T, typename... K> void TRACEV(T<K...> t);
template<typename T, size_t S> void TRACEV(array<T,S> t){TRACEV("[");TRACEV(t[0]);FOR1(i,S){TRACEV(", ");TRACEV(t[i]);}TRACEV("]");}
template<typename T,typename... Args>void TRACEUT_(T t){TRACEV(t);}
template<typename T,typename... Args>void TRACEUT_(T t, Args... args){TRACEV(t); TRACED(", "); TRACEUT_(args...);}
template<typename T,typename... Args>void TRACEUT(T t, Args... args){TRACED('('); TRACEUT_(t,args...); TRACED(")");}
template<typename Tuple, size_t... Is>void TRACET_(Tuple t, index_sequence<Is...>){TRACEUT(get<Is>(t)...);}
template<typename Tuple>void TRACET(Tuple t){TRACET_(t,make_index_sequence<tuple_size<Tuple>::value>{});}
#define TRACEP(p_) TRACED("("); TRACEV(p_.first);TRACED(", ");TRACEV(p_.second);TRACED(")");
template<typename... Args> void TRACEV(tuple<Args...> t){TRACET(t);}
template<typename l, typename r> void TRACEV(pair<l,r> t){TRACEP(t);}
template<template<typename...> class T, typename... K> void TRACEV(T<K...> t){if(t.empty()){TRACEV("[]");return;}auto it = t.begin();
TRACED("[");TRACEV(*it);for(++it;it!=t.end();++it){TRACED(", ");TRACEV(*it);}TRACED("]");}
template<typename T> void TRACEV(T* b, T* e){if(b==e){TRACEV("[]");return;}TRACED("[");TRACEV(*b);while(++b!=e){TRACED(", ");TRACEV(*b);}TRACED("]");}
template<typename T> void TRACE(T t){TRACEV(t);_N;}
template<typename T,typename... Ts> void TRACE(T t,Ts... args){TRACEV(t); _T; TRACE(args...);}

#define ll long long int
#define ull unsigned long long int
#define pii pair<int,int>
#define SSIZE (int)1e5+5
#define DSSIZE 2*(int)1e5+5
#define BSIZE (int)1e5+5

int n,r;
int DP[SSIZE];
int DPSUFMAX[SSIZE];
pii arr[SSIZE];
int time_[SSIZE];

int dis(pii a, pii b){
	return abs(a.first-b.first)+abs(a.second-b.second);
}

int dp_suffix_max(int i);

int dp(int i){
	if(DP[i]!=-1)return DP[i];
	int out = 0;
	FORS(i+1,j,n){
		if(time_[j] > time_[i]+2*r){
			out = max(out,dp_suffix_max(j));
			break;
		}
		else{
			if(dis(arr[i],arr[j])<=time_[j]-time_[i]){
				out = max(out, dp(j));
			}
		}
	}
	DP[i] = out+1;
	return DP[i];
}

int dp_suffix_max(int i){
	if(i==n-1) return dp(i);
	if(DPSUFMAX[i]!= -1) return DPSUFMAX[i];
	DPSUFMAX[i] = max(dp_suffix_max(i+1),dp(i)); 
	return DPSUFMAX[i];
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>r>>n;
	arr[0] = {1,1};
	time_[0] = 0;
	FORI(i,n){
		cin>>time_[i]>>arr[i].first>>arr[i].second;
	}
	n++;
	FOR(i,n) DP[i] = -1;
	FOR(i,n) DPSUFMAX[i] = -1;
	cout<<dp(0)-1<<'\n';

	return 0;
}