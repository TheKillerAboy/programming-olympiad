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
#define SSIZE (int)1e4+5
#define DSSIZE 2*(int)1e5+5
#define BSIZE (int)1e6+5
 
vector<vector<pii>> connections;
vector<int> costs_val;
int n,m;
 
vector<int> pair_v,pair_u;
vector<int> dist;
 
bool BFS(int max_edge){
	set<int> queue;
	FORI(v,n){
		if(pair_v[v] == 0){
			dist[v] = 0;
			queue.insert(v);
		}
		else dist[v] = INT_MAX;
	}
	dist[0] = INT_MAX;
	int loop = 0;
	while(!queue.empty()){
		int v = *queue.begin();
		queue.erase(queue.begin());
		if(dist[v]<dist[0]){
			auto it = connections[v].begin();
			while(it!=connections[v].end() && (*it).first <= max_edge){
				int u = (*it).second;
				if(dist[pair_u[u]] == INT_MAX){
					dist[pair_u[u]] = dist[v] + 1;
					queue.insert(pair_u[u]);
				}
				it++;
			}
		}
		loop++;
	}
	return dist[0] != INT_MAX;
}
 
bool DFS(int v, int max_edge){
	if(v!=0){
		auto it = connections[v].begin();
		while(it!=connections[v].end() && (*it).first <= max_edge){
			int u = (*it).second;
			if(dist[pair_u[u]] == dist[v]+1){
				if(DFS(pair_u[u], max_edge)){
					pair_u[u] = v;
					pair_v[v] = u;
					return true;
				}
			}
			it++;
		}	
		dist[v] = INT_MAX;
		return false;
	}
	return true;
}
 
int loop = 0;
 
int hopcroft_karp_algorithm(int max_edge){
	FORI(i,n) pair_v[i] = 0;
	FORI(i,n) pair_u[i] = 0;
	int matchings = 0;
	while(BFS(max_edge)){
		FORI(v,n){
			if(pair_v[v]==0){
				if(DFS(v,max_edge)) matchings+=1;
			}
		}
		if(matchings==n) break;
	}
	return matchings;
}
 
int bs(int l, int r){
	int mid = (l+r)>>1;
	// if(n==9999){
	// 	TRACE(l,r,mid);
	// 	if(loop == 7) return r;
	// 	loop++;
	// }
	if(l+1==r)return r;
	if(hopcroft_karp_algorithm(costs_val[mid])==n) return bs(l,mid);
	else return bs(mid,r);
}
 
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	int v,u,c;
	connections.resize(n+1);
	costs_val.resize(m);
	pair_v.resize(n+1);
	pair_u.resize(n+1);
	dist.resize(n+1);
	FOR(i,m){
		cin>>v>>u>>c;
		connections[v].push_back({c,u});
		costs_val[i] = c;
	}
	FORI(v,n) sort(connections[v].begin(),connections[v].end());
	sort(costs_val.begin(),costs_val.end());
	// TRACE(max_flow(costs_val[m-1]));
	// TRACE(hopcroft_karp_algorithm(costs_val[m-1]));
	if(hopcroft_karp_algorithm(costs_val[m-1])==n) cout<<costs_val[bs(-1,m-1)]<<'\n';
	else cout<<-1<<'\n';
 
	return 0;
}