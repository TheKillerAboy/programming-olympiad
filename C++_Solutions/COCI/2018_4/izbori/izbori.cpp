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
template<template<typename...> class T, typename... K> void TRACEV(T<K...> t){auto it = t.begin();
TRACED("[");TRACEV(*it);for(++it;it!=t.end();++it){TRACED(", ");TRACEV(*it);}TRACED("]");}
template<typename T> void TRACE(T t){TRACEV(t);_N;}
template<typename T,typename... Ts> void TRACE(T t,Ts... args){TRACEV(t); _T; TRACE(args...);}

#define ll long long int
#define ull unsigned long long int
#define pii pair<int,int>
#define INF INT_MAX

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N,M,K;
	cin>>N>>M>>K;
	--K;
	vector<vector<int>> votes(N,vector<int>(M));
	vector<int> Kvotes(N);
	FOR(i,N){
		FOR(j,M){
			cin>>votes[i][j];
			--votes[i][j];
			if(votes[i][j] == K){
				Kvotes[i] = j;
			}
		}
	}
	vector<int> q1(M,0);
	FOR(i,N){
		++q1[votes[i][0]];
	}
	pii q1B = {-1,-1};
	FOR(i,M){
		if(q1[i] > q1B.first) q1B = {q1[i],i};
	}
	cout<<q1B.second+1<<'\n';
	int very_best = INF;
	FOR(v,1<<M){
		q1 = vector<int>(M,0);
		FOR(i,N){
			FOR(j,M){
				if((1<<(votes[i][j]) & v) == 0){
					++q1[votes[i][j]];
					break;
				}
			}
		}
		pii q1B = {-1,-1};
		FOR(i,M){
			if(q1[i] > q1B.first) q1B = {q1[i],i};
		}
		if(q1B.second == K) very_best = min(very_best,__builtin_popcount(v));
	}
	cout<<very_best<<'\n';
	return 0;
}