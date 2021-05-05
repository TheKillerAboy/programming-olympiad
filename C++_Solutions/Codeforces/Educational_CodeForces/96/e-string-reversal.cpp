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
#define SSIZE (ll)1e5+5
#define DSSIZE 2*(ll)1e5+5
#define BSIZE (ll)1e5+5

ll segtree[4*DSSIZE];

void fillsegtree(ll nl, ll nr, ll ni){
	if(nl<nr){
		ll mid = (nl+nr)>>1;
		fillsegtree(nl,mid,2*ni+1);
		fillsegtree(mid+1,nr,2*ni+2);
		segtree[ni] = 0;
	}
	else if(nl==nr){
		segtree[ni] = 0;
	}
}

void update_range(ll value, ll ql, ll qr, ll nl, ll nr, ll ni){
	if(ql<=nl&&nr<=qr){
		segtree[ni]+=value;
	}
	else if(nr<ql||qr<nl){

	}
	else{
		ll mid = (nl+nr)>>1;
		segtree[2*ni+1] += segtree[ni];
		segtree[2*ni+2] += segtree[ni];
		segtree[ni] = 0;
		update_range(value,ql,qr,nl,mid,2*ni+1);
		update_range(value,ql,qr,mid+1,nr,2*ni+2);
	}
}

ll get_value(ll qi, ll nl, ll nr, ll ni){
	if(nl==nr&&nl==qi){
		return segtree[ni];
	}
	else if(nr<qi||qi<nl){
		return LLONG_MAX;
	}
	else{
		ll mid = (nl+nr)>>1;
		segtree[2*ni+1] += segtree[ni];
		segtree[2*ni+2] += segtree[ni];
		segtree[ni] = 0;
		return min(get_value(qi,nl,mid,2*ni+1),get_value(qi,mid+1,nr,2*ni+2));
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	string s;
	map<char,list<ll>> closest;
	cin>>n>>s;
	FOR(i,n) closest[s[i]].push_back(i);
	fillsegtree(0,n-1,0);
	ll out = 0;
	FOR(i,n){
		char let = s[n-1-i];
		ll closest_index = closest[let].front();
		update_range(-1,closest_index+1,n-1,0,n-1,0);
		out += closest_index+get_value(closest_index,0,n-1,0);
		closest[let].pop_front();
	}
	cout<<out<<'\n';

	return 0;
}