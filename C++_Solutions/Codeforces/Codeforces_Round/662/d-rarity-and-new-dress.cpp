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

char cloth[2000][2000];

int n,m;

int DP[2000][2000][2][2];

char get_color(int i, int j){
	if(i<0||i>=n) return '!';
	if(j<0||j>=m) return '!';
	return cloth[i][j];
}

int dp(int i, int j, bool i_f, bool j_f){
	if(i<0||i>=n) return 0;
	if(j<0||j>=m) return 0;
	int i_c = i_f?1:-1;
	int j_c = j_f?1:-1;
	int& out = DP[i][j][i_f][j_f];
	if(out != -1) return out;
	out = 0;
	if(get_color(i,j)==get_color(i+i_c,j)&&get_color(i,j)==get_color(i,j+j_c)){
		out = min(dp(i+i_c,j,i_f,j_f),dp(i,j+j_c,i_f,j_f));
	}
	out++;
	return out;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	string val;
	FOR(i,n){
		cin>>val;
		FOR(j,m) cloth[i][j] = val[j];
	}
	FOR(i,n)FOR(j,m)FOR(k,2)FOR(l,2)DP[i][j][k][l] = -1;
	// dp(0,0,1,1);
	// dp(0,m-1,1,0);
	// dp(n-1,0,0,1);
	// dp(n-1,m-1,0,0);
	ll out = 0;
	FOR(i,n){
		FOR(j,m){
			int min_ = INT_MAX;
			FOR(k,2) FOR(l,2) min_ = min(min_,dp(i,j,k,l));
			out += min_;
		}
	}
	cout<<out<<'\n';
	return 0;
}