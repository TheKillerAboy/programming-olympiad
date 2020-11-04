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

set<int> peaks;
set<int> valleys;

int arr[3*SSIZE];
int q,n;
int t;

void remove(int i){
	if(i==0||i==n+1) return;
	if(peaks.find(i)!=peaks.end()) peaks.erase(i);
	if(valleys.find(i)!=valleys.end()) valleys.erase(i);
}

void add(int i){
	if(i==0||i==n+1) return;
	if(arr[i]>arr[i-1]&&arr[i]>arr[i+1]){
		peaks.insert(i);
	}
	if(arr[i]<arr[i-1]&&arr[i]<arr[i+1]){
		valleys.insert(i);
	}
}

int best(){
	int out = 0;
	int i = -1;
	while(true){
		auto peaks_it = peaks.upper_bound(i);
		if(peaks_it == peaks.end()) break;
		if(valleys.find(i)!=valleys.end()) out -= arr[i];
		out += arr[*peaks_it];
		auto valleys_next = valleys.upper_bound(i);
		if(valleys_next==valleys.end()) i = INT_MAX;
		else i = *valleys_next;
	}
	return out;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		// TRACE("-------");
		peaks.clear();
		valleys.clear();
		cin>>n>>q;
		FORI(i,n) cin>>arr[i];
		arr[0] = INT_MIN;
		arr[n+1] = INT_MIN;
		FORI(i,n) add(i);
		int l,r;
		cout<<best()<<'\n';
		while(q--){
			cin>>l>>r;
			FORS(l-1,i,l+2) remove(i);
			FORS(r-1,i,r+2) remove(i);
			swap(arr[l],arr[r]);
			FORS(l-1,i,l+2) add(i);
			FORS(r-1,i,r+2) add(i);
			cout<<best()<<'\n';
		}
	}

	return 0;
}