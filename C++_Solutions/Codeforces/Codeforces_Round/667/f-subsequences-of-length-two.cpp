#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(int i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(int i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(int i_=1;i_<a_;++i_)

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
#define iii array<int,3>
#define SSIZE (int)1e5+5
#define BSIZE (int)1e6+5

string s,t;
int n,k;
int DP[205][205][205];

int dp(int i, int t1, int left){
	if(i==n) return 0;
	int& out = DP[i][t1][left];
	if(out!=-1)return out;
	if(s[i]==t[0]){
		out = dp(i+1,t1+1,left);
		if(left>0)out = max(out,dp(i+1,t1,left-1)+t1);
	}
	else if(s[i]==t[1]){
		out = dp(i+1,t1,left) + t1;
		if(left>0)out = max(out,dp(i+1,t1+1,left-1));
	}
	else{
		out = dp(i+1,t1,left);
		if(left>0){
			out = max(out,dp(i+1,t1+1,left-1));
			out = max(out,dp(i+1,t1,left-1)+t1);
		}
	}
	return out;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	FOR(i,205)FOR(j,205)FOR(k_,205)DP[i][j][k_] = -1;
	cin>>n>>k;
	cin>>s>>t;
	if(t[0]==t[1]){
		int t1s = 0;
		FOR(i,n) if(s[i]==t[0]) t1s++;
		t1s += k;
		t1s = t1s>n?n:t1s;
		cout<<t1s*(t1s-1)/2<<'\n';
	}
	else cout<<dp(0,0,k)<<'\n';

	return 0;
}