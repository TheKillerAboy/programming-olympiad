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

#define MOD ((int)998244353)

int add(int a_, int b_){
	long long int a=(long long int)a_,b=(long long int)b_;
	return (a+b)%MOD;
}
int neg(int a_, int b_){
	long long int a=(long long int)a_,b=(long long int)b_;
	return (a-b)%MOD;
}
int mul(int a_, int b_){
	long long int a=(long long int)a_,b=(long long int)b_;
	return (a*b)%MOD;
}
int power(int a, int n){
	if(n==0)return 1;
	if(n==1)return a;
	int temp = power(a,n/2);
	return mul(temp,mul(temp,n%2==1?a:1));
}
int divide(int a, int b){
	int b_inv = power(b,MOD-2);
	return mul(a,b_inv);
}
int FAC[3*SSIZE];

int choose(int n, int k){
	return divide(FAC[n],mul(FAC[n-k],FAC[k]));
}

int arr[3*SSIZE];
int n;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	FAC[0] = 1;
	FAC[1] = 1;
	FORS(2,i,3*SSIZE) FAC[i] = mul(FAC[i-1],i);
	cin>>n;
	FOR(i,2*n) cin>>arr[i];
	sort(arr,arr+2*n);
	int out = 0;
	FOR(i,n){
		out = add(out, neg(arr[2*n-1-i],arr[i]));
	}
	out = mul(choose(2*n,n),out);
	cout<<out<<'\n';

	return 0;
}