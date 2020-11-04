#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(int i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(int i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(int i_=1;i_<a_;++i_)

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
#define iii array<int,3>
#define SSIZE (int)1e5+5
#define BSIZE (int)1e6+5

set<int> connections[SSIZE];
set<int> connectionsCurrent[SSIZE];
int person[SSIZE];
int n;

int main(){
	// cin.tie(0);
	// ios::sync_with_stdio(false);
	cin>>n;
	int u,v;
	FOR(i,n-1){
		cin>>u>>v;
		connections[u].insert(v);
		connections[v].insert(u);
		connectionsCurrent[u].insert(v);
		connectionsCurrent[v].insert(u);
	}
	set<pii> degrees;
	FORI(i,n) degrees.insert({connectionsCurrent[i].size(),i});
	FORI(i,n) person[i] = i;
	int out = 0;
	while(!degrees.empty()){
		// TRACE(degrees);
		int size, node;
		tie(size, node) = *degrees.begin();
		degrees.erase(degrees.begin());
		if(person[node] == node){
			out += 2;
			if(connectionsCurrent[node].size()>0){
				bool found = false;
				FORA(other,connectionsCurrent[node]){
					if(person[other]==other){
						swap(person[other],person[node]);
						found = true;
						break;
					}
				}
				if(!found){
					FORA(other,connectionsCurrent[node]){
						swap(person[other],person[node]);
						break;
					}	
				}
			}
			else{
				// TRACE(node,"NONE");
				FORA(other,connections[node]){
					swap(person[other],person[node]);
					break;
				}	
			}
		}
		FORA(other,connectionsCurrent[node]){
			if(degrees.find({connectionsCurrent[other].size(),other})!=degrees.end()){
				degrees.erase(degrees.find({connectionsCurrent[other].size(),other}));
				connectionsCurrent[other].erase(node);
				degrees.insert({connectionsCurrent[other].size(),other});
			}
		}
	}
	cout<<out<<'\n';
	FORI(i,n) cout<<person[i]<<' ';

	return 0;
}