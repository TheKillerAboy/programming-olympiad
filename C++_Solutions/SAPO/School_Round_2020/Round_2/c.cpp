#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(long long i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(long long i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(long long i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(long long i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(long long i_=1;i_<a_;++i_)

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

// #define ll long long long long
// #define ull unsigned long long long long
#define pii pair<long long,long long>
#define iii array<long long,3>
#define SSIZE (long long)1e5+5
#define BSIZE (long long)1e6+5
#define MOD ((long long)1e8)

long long n,m;
string maze[1001];
long long DP[1001][1001];

long long dp(long long i, long long j){
	if(i<0||i>=n||j<0||j>=m) return 0;
	if(i==0&&j==0) return maze[0][0] == '.';
	if(DP[i][j]!=-1) return DP[i][j];
	if(maze[i][j] == '#') return 0;
	DP[i][j] = (dp(i-1,j) + dp(i,j-1))%MOD;
	return DP[i][j];
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	FOR(i,n)cin>>maze[i];
	FOR(i,1001)FOR(j,1001) DP[i][j] = -1;
	cout<<dp(n-1,m-1)<<'\n';

	return 0;
}