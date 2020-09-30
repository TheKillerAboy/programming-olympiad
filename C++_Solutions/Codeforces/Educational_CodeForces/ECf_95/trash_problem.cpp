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
template<typename T> void TRACE(T t){TRACEV(t);_N;}
template<typename T,typename... Ts> void TRACE(T t,Ts... args){TRACEV(t); _T; TRACE(args...);}

#define ull unsigned long long int
#define pii pair<int,int>
#define ll long long int

int n,q;
int t,x;
set<ll> piles;
multiset<ll> diffrences;

auto prev_piles(int x){
	if(piles.find(x) == piles.begin()){
		return piles.end();
	}
	return prev(piles.find(x));
}

int main(){
	// cin.tie(0);
	// ios::sync_with_stdio(false);

	cin>>n>>q;
	int val;
	FOR(i,n){cin>>val;piles.insert(val);}
	auto it = piles.begin();
	FOR(i,n-1){diffrences.insert(*(it++)-*it);}
	if(piles.size()<=2){
		cout<<"0\n";
	}
	else{
		cout<<*piles.rbegin() - *piles.begin() + *diffrences.begin()<<'\n';
	}
	while(q--){
		cin>>t>>x;
		if(t==1){
			piles.insert(x);
			auto p_k_it = prev_piles(x), p_k_2_it = ++piles.find(x);
			ll p_k, p_k_2;
			if(p_k_it!=piles.end()){
				p_k = *p_k_it;
				diffrences.insert(p_k-x);
			}
			if(p_k_2_it!=piles.end()){
				p_k_2 = *p_k_2_it;
				diffrences.insert(x-p_k_2);
			}
			if(p_k_it!=piles.end()&&p_k_2_it!=piles.end()){
				diffrences.erase(diffrences.find(p_k-p_k_2));
			}
		}
		else{
			auto p_k_n1_it = prev_piles(x), p_k_1_it = ++piles.find(x);
			piles.erase(x);
			ll p_k_n1, p_k_1;
			if(p_k_1_it!=piles.end()){
				p_k_1 = *p_k_1_it;
				diffrences.erase(diffrences.find(x-p_k_1));
			}
			if(p_k_n1_it!=piles.end()){
				p_k_n1 = *p_k_n1_it;
				diffrences.erase(diffrences.find(p_k_n1-x));
			}
			if(p_k_1_it!=piles.end()&&p_k_n1_it!=piles.end()){
				diffrences.insert(p_k_n1-p_k_1);
			}
		}
		if(piles.size()<=2){
			cout<<"0\n";
		}
		else{
			cout<<*piles.rbegin() - *piles.begin() + *diffrences.begin()<<'\n';
		}
	}

	return 0;
}