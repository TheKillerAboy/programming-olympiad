#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(long long i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(long long i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(long long i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(long long i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(long long i_=1;i_<a_;++i_)

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

#define pii pair<long long,long long>
#define iii array<long long,3>
#define SSIZE (long long)1e5+5
#define BSIZE (long long)1e6+5
#define INF LLONG_MAX/100000

long long dist[1001][1001];
list<long long> connections[1001];
map<pii,long long> weights;

long long get_weight(long long u, long long v){
	if(u>v)swap(u,v);
	return weights[{u,v}];
}
void set_weight(long long u, long long v, long long w){
	if(u>v)swap(u,v);
	weights[{u,v}] = w;
}

void dik_from(long long node){
	FOR(i,1001) dist[node][i] = INF;
	dist[node][node] = 0;
	set<pii> queue;
	queue.insert({0,node});
	while(!queue.empty()){
		long long dis, cur_node;
		tie(dis,cur_node) = *queue.begin();
		queue.erase(queue.begin());
		FORA(next_node, connections[cur_node]){
			if(dist[node][next_node] == INF){
				queue.insert({INF,next_node});
			}
			if(dis + get_weight(cur_node,next_node) < dist[node][next_node]){
				queue.erase(pii{dist[node][next_node], next_node});
				dist[node][next_node] = dis + get_weight(cur_node,next_node);
				queue.insert(pii{dist[node][next_node], next_node});
			}
		}
	}
}

long long n,m,k;
pii path[1001];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	long long u,v,w;
	FOR(i,m) {
		cin>>u>>v>>w;
		connections[u].push_back(v);
		connections[v].push_back(u);
		set_weight(u,v,w);
	}
	FOR(i,k) cin>>path[i].first>>path[i].second;
	FORI(i,n) dik_from(i); 
	long long out = INF;
	FORA(edge, weights){
		long long current = 0;
		FOR(i,k){
			long long a,b;
			tie(a,b) = path[i];
			long long x,y;
			tie(x,y) = edge.first;
			// TRACE(edge,path[i],min(dist[a][b],min(dist[a][x]+dist[y][b],dist[a][y]+dist[x][b])));
			current += min(dist[a][b],min(dist[a][x]+dist[y][b],dist[a][y]+dist[x][b]));
		}
		out = min(current,out);
	}
	cout<<out<<'\n';
	return 0;
}