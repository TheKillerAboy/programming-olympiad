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
template<typename T> void TRACEV(T* b, T* e){if(b==e){TRACEV("[]");return;}TRACED("[");TRACEV(*b);while(++b!=e){TRACED(",");TRACEV(*b);}TRACED("]");}
template<typename T> void TRACE(T t){TRACEV(t);_N;}
template<typename T,typename... Ts> void TRACE(T t,Ts... args){TRACEV(t); _T; TRACE(args...);}

#define ll long long int
#define ull unsigned long long int
#define pii pair<int,int>
#define MS (int)1e5+5

int good[MS],bad[MS];
int h[MS],p[MS];
int n,m,t;
int a,b;
int children[MS],parent[MS];
map<int,set<int>> connections;


void handle_parent(int node, set<int>& queue){
	if(parent[node]==-1){return;}
	good[parent[node]] += good[node];
	bad[parent[node]] += bad[node];
	--children[parent[node]];
	if(children[parent[node]]==0){
		queue.insert(parent[node]);
	}
}

void prepare_node(int node){
	children[node]=0;
	FORA(child,connections[node]){
		++children[node];
		parent[child] = node;
		connections[child].erase(node);
		prepare_node(child);
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin>>t;
	FORI(oo,t){
		cin>>n>>m;
		FORI(i,n){cin>>p[i];}
		FORI(i,n){cin>>h[i];}
		FORI(i,n){good[i]=0;bad[i]=0;}
		connections.clear();
		FOR(i,n-1){
			cin>>a>>b;
			connections[a].insert(b);
			connections[b].insert(a);
		}
		prepare_node(1);
		parent[1] = -1;
		set<int> queue;
		FORI(i,n){
			if(children[i]==0){
				queue.insert(i);
			}
		}
		set<int> queue_c = queue;
		queue.clear();
		bool pos = true;
		FORA(node,queue_c){
			if((p[node]+h[node])%2!=0){pos = false;}
			good[node] = (p[node]+h[node])/2;
			bad[node] = (p[node]-h[node])/2;
			if(good[node]<0||bad[node]<0){pos = false;}

			handle_parent(node,queue);
		}
		while(!queue.empty()){
			queue_c = queue;
			queue.clear();
			FORA(node, queue_c){
				bad[node] += p[node];
				int top = h[node]-good[node]+bad[node];
				if(top%2==1||top<0){pos = false;}
				bad[node] -= top/2;
				good[node] += top/2;
				if(good[node]<0||bad[node]<0){pos = false;}
				
				handle_parent(node,queue);
			}
		}
		if(!pos){cout<<"NO\n";}
		else{cout<<"YES\n";}
	}

	return 0;
}