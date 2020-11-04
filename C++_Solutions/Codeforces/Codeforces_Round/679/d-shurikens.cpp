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
#define pci pair<char,int>
#define iii array<int,3>
#define SSIZE (int)1e5+5
#define BSIZE (int)1e6+5

pci events[2*SSIZE];
int seq[SSIZE];
int n;

bool always_enough(){
	int amount = 0;
	FOR(i,2*n){
		if(events[i].first=='+') ++amount;
		else{
			if(amount==0) return false;
			else --amount;
		}
	}
	return true;
}

bool order_currect(){
	set<int> current;
	int j = 0;
	FOR(i,2*n){
		if(events[i].first=='+') current.insert(seq[j++]);
		else{
			int min_ = *current.begin();
			if(min_ != events[i].second) return false;
			current.erase(current.begin());
		}
	}
	return true;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n;
	char type;
	int val;
	FOR(i,2*n){
		cin>>type;
		if(type=='+') val = -1;
		else cin>>val;
		events[i] = {type,val};
	}
	if(always_enough()){
		list<int> indexs;
		int j = 0;
		FOR(i,2*n){
			if(events[i].first=='+') indexs.push_back(j++);
			else{
				seq[indexs.back()] = events[i].second;
				indexs.pop_back();
			}
		}
		if(order_currect()){
			cout<<"YES\n";
			FOR(i,n) cout<<seq[i]<<' '; 
		}
		else cout<<"NO";
	}
	else cout<<"NO";


	return 0;
}