#include <bits/stdc++.h>

using namespace std;
#define ll long long int

#define FOR(i_,a_) for(ll i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(ll i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(ll i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(ll i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(ll i_=1;i_<a_;++i_)
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

#define ull unsigned long long ll
#define pii pair<ll,ll>
#define SIZE 2*(int)1e5+5

ll parent[SIZE];
vector<ll> children[SIZE];
ll arr[SIZE];
ll n;
set<ll> used;
set<ll> roots;
list<ll> path;

void move(ll node, ll& out){
	out += arr[node];
	if(parent[node]!=-1) arr[parent[node]] += arr[node];
	used.insert(node);
	path.push_back(node);
}

ll max_pos(ll node){
	ll out = 0;
	FORA(child, children[node]){
		out += max_pos(child);
	}
	if(arr[node]>0) move(node, out);
	return out;
}

ll min_neg(ll node){
	ll out = 0;
	if(used.find(node)==used.end()) move(node, out);
	FORA(child, children[node]){
		out += min_neg(child);
	}
	return out;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n;
	FOR(i,n) cin>>arr[i];
	FOR(i,n){
		cin>>parent[i];
		if(parent[i]!=-1){
			parent[i]--;
			children[parent[i]].push_back(i);
		}
		else roots.insert(i);
	}
	ll ans = 0;
	FORA(root,roots){
		ans += max_pos(root);
	}
	FORA(root,roots){
		ans += min_neg(root);
	}
	cout<<ans<<'\n';
	FORA(node,path){
		cout<<node+1<<' ';
	}
	cout<<'\n';

	return 0;
}