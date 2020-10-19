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

int to[DSSIZE];
int from[DSSIZE];
map<int,set<int>> connections;

void fill(int* arr, int start){
	set<int> visited;
	set<int> current = {start};
	int dis = 0;
	while(!current.empty()){
		FORA(v,current){
			arr[v] = dis;
			visited.insert(v);
		}
		set<int> current_copy = current;
		current.clear();
		FORA(v,current_copy){
			FORA(u,connections[v]){
				if(visited.find(u)==visited.end()) current.insert(u);
			}
		}
		dis++;
	}
}

int n,m,k;
int arr[DSSIZE];
pii to_ordered[DSSIZE];
int sufmax[DSSIZE];
int firstorder[DSSIZE];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	int v,u;
	FOR(i,k) cin>>arr[i];
	FOR(i,m){
		cin>>v>>u;
		connections[v].insert(u);
		connections[u].insert(v);
	}
	fill(to,1);
	fill(from,n);
	FOR(i,k){
		to_ordered[i] = {to[arr[i]],from[arr[i]]};
	}
	sort(to_ordered,to_ordered+k);
	FOR(i,k) firstorder[i] = to_ordered[i].first;
	sufmax[k-1] = to_ordered[k-1].second;
	FOR1(i,k){
		sufmax[k-1-i] = max(sufmax[k-i],to_ordered[k-1-i].second);
	}
	int out = 0;
	FOR(i,k){
		int j = i+1;
		if(j<k) out = max(out, min(firstorder[i]+sufmax[j]+1,to[n]));
	}
	cout<<out;

	return 0;
}