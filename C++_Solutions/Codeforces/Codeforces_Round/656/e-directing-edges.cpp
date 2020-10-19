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

vector<set<int>> connections;
set<pii> connections_remaining;
map<pii,int> directions;

pii sort_pii(pii a){
	if(a.first>a.second) return {a.second,a.first};
	return a;
}

void set_direction(int u, int v, int d){
	directions[sort_pii(pii{u,v})] = d;
}

int get_direction(int u, int v){
	return directions[sort_pii(pii{u,v})];
}

int t,n,m;
bool dir;

void remove_leaves(){
	while(!connections_remaining.empty()&&(*connections_remaining.begin()).first<2){
		int i = (*connections_remaining.begin()).second;
		connections_remaining.erase(pii{connections[i].size(),i});
		if((*connections_remaining.begin()).first>0){
			int node = *connections[i].begin();
			connections_remaining.erase(connections_remaining.find({connections[node].size(),node}));
			connections[node].erase(i);
			connections_remaining.insert(pii{connections[node].size(),node});
		}
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		connections.clear();
		connections_remaining.clear();
		directions.clear();
		cin>>n>>m;
		connections.resize(n);
		TRACE("H");
		int u,v;
		FOR(i,m){
			cin>>dir>>u>>v;
			u--;v--;
			connections[u].insert(v);
			connections[v].insert(u);
			set_direction(u,v,dir?u:-1);
		}
		FOR(i,n) connections_remaining.insert(pii{connections[i].size(),i});
		remove_leaves();
		TRACE(connections_remaining);
	}
	return 0;
}