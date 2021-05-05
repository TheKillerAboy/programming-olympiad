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
#define TRACED(_v) cerr<<_v;
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

int R[(int)1e3],G[(int)1e3],B[(int)1e3];
int r,g,b;

int DP[300][300][300];

int dp(int r_, int g_, int b_){
	if(DP[r_][g_][b_]!=-1){return DP[r_][g_][b_];}
	DP[r_][g_][b_] = 0;
	if(r_>0 && g_>0){
		DP[r_][g_][b_] = max(DP[r_][g_][b_],R[r-r_]*G[g-g_] + dp(r_-1,g_-1,b_));
	}
	if(r_>0 && b_>0){
		DP[r_][g_][b_] = max(DP[r_][g_][b_],R[r-r_]*B[b-b_] + dp(r_-1,g_,b_-1));
	}
	if(b_>0 && g_>0){
		DP[r_][g_][b_] = max(DP[r_][g_][b_],B[b-b_]*G[g-g_] + dp(r_,g_-1,b_-1));
	}
	return DP[r_][g_][b_];
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>r>>g>>b;
	FOR(i,r){cin>>R[i];}
	FOR(i,g){cin>>G[i];}
	FOR(i,b){cin>>B[i];}
	sort(R,R+r);
	sort(G,G+g);
	sort(B,B+b);
	FOR(i,r+1){
		FOR(j,g+1){
			FOR(k,b+1){
				DP[i][j][k] = -1;
			}
		}
	}
	int out = 0;
	FOR(i,r+1){
		FOR(j,g+1){
			FOR(k,b+1){
				out = max(out,dp(i,j,k));
			}
		}
	}
	cout<<out;
	return 0;
}