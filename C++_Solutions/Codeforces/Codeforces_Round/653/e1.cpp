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
#define SIZE 2*(int)1e5+5

int n,k;
int both[SIZE]; int boths;
int a[SIZE]; int as;
int b[SIZE]; int bs;
bool al,bl;
int val;

void make_prefsum(int* arr, int size){
	FOR1(i,size){
		arr[i]+=arr[i-1];
	}
}

int prefsum_get(int* arr, int l, int r){
	if(r==-1) return 0;
	if(l==0) return arr[r];
	return arr[r] - arr[l-1];
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	boths = 0;
	as = 0;
	bs = 0;
	cin>>n>>k;
	FOR(i,n){
		cin>>val>>al>>bl;
		if(al&&bl) both[boths++] = val;
		else if(al) a[as++] = val;
		else if(bl) b[bs++] = val;
	}
	sort(both,both+boths);
	sort(a,a+as);
	sort(b,b+bs);
	make_prefsum(both,boths);
	make_prefsum(a,as);
	make_prefsum(b,bs);
	int out = INT_MAX;
	FOR(share,k+1){
		if(boths>=share&&as>=k-share&&bs>=k-share){
			out = min(out,prefsum_get(both,0,share-1)+prefsum_get(a,0,k-share-1)+prefsum_get(b,0,k-share-1));
		}
	}
	cout<<(out==INT_MAX?-1:out)<<'\n';

	return 0;
}