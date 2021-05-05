#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(long long i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(long long i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(long long i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(long long i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(long long i_=1;i_<a_;++i_)
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

// #define ll long long long long
// #define ull unsigned long long long long
#define pii pair<long long,long long>

long long t;
long long n,k;
long long l1,r1;
long long l2,r2;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n>>k;
		cin>>l1>>r1;
		cin>>l2>>r2;
		if(l2<l1) swap(l1,l2), swap(r1,r2);
		long long extra = max((long long)0,min(r2,r1)-max(l1,l2));
		long long A = max((long long)0,l2-r1);
		if(A == 0) k-=extra*n;
		long long out = 0;
		if(k<=0) cout<<out<<'\n';
		else{
			long long index = 0;
			while(k>0 && index<n){
				long long c = max(r2,r1)-min(l1,l2) - extra;
				if(A+min(c,k)<2*k || index == 0){
					out += A+min(c,k);
					k-=min(c,k);
				}
				else break;
				index++;
			}
			if(k<=0) cout<<out<<'\n';
			else{
				out += 2*k;
				cout<<out<<'\n';
			}
		}
	}

	return 0;
}