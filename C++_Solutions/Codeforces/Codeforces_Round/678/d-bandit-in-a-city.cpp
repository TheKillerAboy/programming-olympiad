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

// #define ll long long long long
// #define ull unsigned long long long long
#define pii pair<long long,long long>
#define iii array<long long,3>
#define SSIZE (long long)1e5+5
#define BSIZE (long long)1e6+5
#define ceil(a_,b_) (a_/b_ + ((a_%b_)>0))

long long total_people[2*SSIZE];
long long total_ep[2*SSIZE];
long long people[2*SSIZE];
map<long long,set<long long>> connections;
long long n;

void root(long long node){
	FORA(child, connections[node]){
		connections[child].erase(node);
		root(child);
	}
}

void total_people_calc(long long node){
	FORA(child, connections[node]) total_people_calc(child);
	total_people[node] = people[node];
	FORA(child, connections[node]) total_people[node] += total_people[child];
}

void total_ep_calc(long long node){
	FORA(child, connections[node]) total_ep_calc(child);
	total_ep[node] = connections[node].empty();
	FORA(child, connections[node]) total_ep[node] += total_ep[child];
}

void best_dist(long long node){
	long long max_upper = 0;
	FORA(child, connections[node]){
		max_upper = max(max_upper, ceil(total_people[child],total_ep[child]));
	}
	FORA(child, connections[node]){
		long long additional = max_upper*total_ep[child] - total_people[child];
		additional = min(additional, people[node]);
		people[node] -= additional;
		people[child] += additional;
	}

	long long esum = 0;
	FORA(child, connections[node]) esum += total_ep[child];
	if(esum>0){
		long long a = people[node]/esum;
		FORA(child,connections[node]){
			people[node] -= total_ep[child]*a;
			people[child] += total_ep[child]*a;
		}
	}
	FORA(child,connections[node]){
		long long additional = total_ep[child];
		additional = min(additional, people[node]);
		people[node] -= additional;
		people[child] += additional;
	}
	FORA(child,connections[node]) best_dist(child);
}

long long max_people(){
	long long out = 0;
	FORI(node, n){
		if(connections[node].empty()) out = max(out, people[node]);
	}
	return out;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n;
	long long val;
	FOR(i,n-1){
		cin>>val;
		connections[i+2].insert(val);
		connections[val].insert(i+2);
	}
	FORI(i,n) cin>>people[i];
	root(1);
	total_ep_calc(1);
	total_people_calc(1);
	best_dist(1);
	cout<<max_people();

	return 0;
}