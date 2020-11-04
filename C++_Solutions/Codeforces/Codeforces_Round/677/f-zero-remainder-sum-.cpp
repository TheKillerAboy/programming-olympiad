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
#define NINF INT_MIN/750

int n,m,k;
int mat[75][75];
int power_k;
int DP[75][75][75][75];

int dp(int x, int y, int cnt, int rem){
	if(cnt == 0){
		if(rem != 0) return NINF;
		return 0;
	}
	if(x<0) return NINF;
	int& out = DP[x][y][cnt][rem];
	if(out != -1) return out;
	out = NINF;
	out = max(out, dp(x-1,y,cnt,rem));
	out = max(out, dp(x-1,y,cnt-1,(rem-mat[y][x]+power_k)%k) + mat[y][x]);
	return out;
}

int DP2[75][75];
int biggest[75][75];

int dp_2(int y, int rem){
	int& out = DP2[y][rem];
	if(out!=-1) return out;
	out = NINF;
	if(y==0){
		FOR(cnt,m/2+1) out = max(out, dp(m-1,y,cnt,rem));
	}
	else{
		FOR(cnt,m/2+1){
			FOR(i,k) {
				out = max(out, dp_2(y-1,(rem-i+power_k)%k)+dp(m-1,y,cnt,i));
				// TRACE((rem-i+k*k)%k);
				// TRACE(y,rem,out,i,(rem-i+k)%k,dp(m-1,y,cnt,i));
			}
		}
	}
	return out;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	power_k = 700*k;
	FOR(i,n) FOR(j,m) cin>>mat[i][j];
	FOR(i,75) FOR(j,75) FOR(k_,75) FOR(rem, 75) DP[i][j][k_][rem] = -1;
	FOR(i,75) FOR(j,75) DP2[i][j] = -1;
	cout<<dp_2(n-1,0);

	return 0;
}