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
#define SIZE 2*(ll)1e5+5
#define get(arr,l,r) (r<l?0:(l==0?arr[r]:arr[r]-arr[l-1]))

ll t,n;
ll arr[SIZE];

void normalize(list<ll>& lst){
	auto it = lst.begin();
	while(next(it)!=lst.end()){
		ll a = *it;
		ll b = *next(it);
		if((a>=0&&b>=0)||(a<0&&b<0)){
			*it = a+b;
			lst.erase(next(it));
		}
		else{
			it++;
		}
	}
}

ll largest(list<ll>& lst){
	ll cur = 0;
	ll out = 0;
	if(lst.front()<0) lst.pop_front();
	FORA(v,lst){
		if(cur+v<0) cur = 0;
		else cur+=v;
		out = max(out,cur);
	}
	return out;
}

int main(){
	// cin.tie(0);
	// ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n;
		list<ll> evenstart,oddstart;
		FOR(i,n) cin>>arr[i];
		FOR(i,n){
			if(2*i+1<n) evenstart.push_back(arr[2*i+1]-arr[2*i]);
			if(2*i+2<n) oddstart.push_back(arr[2*i+1]-arr[2*i+2]);
		}
		ll even = 0;
		FOR(i,n) if(i%2==0) even += arr[i];
		// TRACE(evenstart,oddstart);
		normalize(evenstart);
		normalize(oddstart);
		cout<<(even+max(largest(evenstart),largest(oddstart)))<<'\n';
	}

	return 0;
}