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
#define SSIZE (int)1e5+5
#define DSSIZE 2*(int)1e5+5
#define BSIZE (int)1e6+5

map<int,list<int>> connections;
map<int,list<int>> connections_return;
map<pii,int> weights;
int n,m;

bool finds_end(map<int,int>& parent, int threashold){
	list<int> queue;
	queue.push_back(1);
	set<int> visted;
	while(!queue.empty()){
		int cur_node = queue.front();
		queue.pop_front();
		visted.insert(cur_node);
		FORA(next_node, connections[cur_node]){
			if(weights[{cur_node,next_node}]>=threashold){
				if(visted.find(next_node)==visted.end()){
					queue.push_back(next_node);
					parent[next_node] = cur_node;
				}
			}
		}
		FORA(prev_node, connections_return[cur_node]){
			if(weights[{cur_node,prev_node}]>=threashold){
				if(visted.find(prev_node)==visted.end()){
					queue.push_back(prev_node);
					parent[prev_node] = cur_node;
				}
			}
		}
	}
	return visted.find(n)!=visted.end();
}

int max_flow(){
	int out = 0;
	list<pii> edges;
	int threashold = 1e6;
	map<int,int> parent;
	while(threashold!=0){
		while(finds_end(parent, threashold)){
			TRACE(parent,threashold);
			int min_ = INT_MAX;
			int cur_node = n;
			while(cur_node!= 1){
				min_ = min(min_,weights[{parent[cur_node],cur_node}]);
				cur_node = parent[cur_node];
			}
			cur_node = n;
			while(cur_node!= 1){
				weights[{parent[cur_node],cur_node}] -= min_;
				weights[{cur_node,parent[cur_node]}] += min_;
				cur_node = parent[cur_node];
			}
			out+=min_;
			parent.clear();
		}
		threashold/=2;
	}
	return out;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin>>n>>m;
	int v,u,w;
	FOR(i,m){
		cin>>v>>u>>w;
		connections[v].push_back(u);
		connections_return[u].push_back(v);
		weights[{v,u}] = w;
		weights[{u,v}] = 0;
	}
	TRACE(max_flow());

	return 0;
}