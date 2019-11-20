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
template<typename T> void TRACE(T t){TRACEV(t);_N;}
template<typename T,typename... Ts> void TRACE(T t,Ts... args){TRACEV(t); _T; TRACE(args...);}

#define ll long long int
#define ull unsigned long long int
#define pii pair<int,int>
#define swap(a,b) a^=b^=a^=b

vector<int> group;
vector<int> groupSize;
vector<int> groupMax;

inline int uFind(int a){
	int current = a;
	while(group[current] != -1) current = group[current];
	if(current != a) group[a] = current;
	return current;
}

inline void uMerge(int a, int b){
	int aP = uFind(a), bP = uFind(b);
	if(aP == bP) return;
	if(groupSize[bP] > groupSize[aP]) swap(aP,bP);
	group[bP] = aP;
	groupSize[aP] += groupSize[bP];
	groupMax[aP] = max(groupMax[aP],groupMax[bP]);
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N,M;
	cin>>N>>M;
	group.resize(N,-1);
	groupSize.resize(N,1);
	groupMax.resize(N);
	FOR(i,N) groupMax[i] = i;
	int a,b;
	FOR(i,M){
		cin>>a>>b;
		--a;--b;
		uMerge(a,b);
	}
	int currentMax = groupMax[uFind(0)];
	int current = uFind(0);
	int add = 0;
	FOR1(i,N){
		if(i <= currentMax){
			if(uFind(current) != uFind(i))++add;
			uMerge(current,i);
			currentMax = groupMax[uFind(current)];
		}
		else{
			current = uFind(i);
			currentMax = groupMax[uFind(i)];
		}
	}
	cout<<add<<'\n';

	return 0;
}