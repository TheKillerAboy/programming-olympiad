#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(ll i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(ll i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(ll i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(ll i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(int i_=1;i_<a_;++i_)
#define FORIT(it_,c_) for(auto it_ = c_.begin(); it_!=c_.end();++it_)

#define _ cerr<<' ';
#define _N cerr<<'\n';
#define _T cerr<<'\t';
#define TRACED(_v) cerr<<_v;
void TRACEV(string a){TRACED(a);}
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

#define ll long long int
#define ull unsigned long long int
#define pii pair<ll,ll>
#define INF LLONG_MAX

list<ll> FACTOR(ll a){
	list<ll> out;
	if(a%2 == 0){
		out.push_back(2);
		while(a%2 == 0) a/=2;
	}
	for(int i = 3; i <= sqrt(a); i+=2) if(a%i == 0){
		out.push_back(i);
		while(a%i == 0) a/= i;
	}
	if(a > 1) out.push_back(a);
	return out;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N;
	cin>>N;
	vector<ll> boxes(N);
	FOR(i,N) cin>>boxes[i];
	ll boxesAmount = 0;
	FOR(i,N) boxesAmount += boxes[i];
	list<ll> factors = FACTOR(boxesAmount);
	if(factors.empty()){
		cout<<-1<<'\n';
		return 0;
	}
	ll minCost = INF;
	FORA(factor,factors){
		ll index = 0;
		ll amount = 0;
		ll cost = 0;
		vector<ll> indeces(factor);
		int i = 0;
		bool changed = true;
		while(i<N){
			TRACE(i);
			if(boxes[i] > 0 && changed){
				indeces[index++] = i;
				amount+=boxes[i];
			}
			changed = false;
			if(amount >= factor){
				ll amount_ = 0;
				int I = i;
				FOR(j,index){
					amount_ += boxes[indeces[j]];
					I = indeces[j];
					if(amount_ >= factor/2) break;
				}
				FOR(j,index-1){
					cost += boxes[indeces[j]]*abs(indeces[j]-I);
				}
				if(amount > factor){
					index = 1;
					indeces[0] = i;
					amount = amount - factor;
					TRACE("d",i,(boxes[i]-amount)*abs(i-I));
					cost += (boxes[i]-amount)*abs(i-I);
				}
				else{
					index = 0;
					amount = 0;
					TRACE("n",i,(boxes[i]-amount)*abs(i-I));
					cost += (boxes[i]-amount)*abs(i-I);
					++i;changed=true;
				}
			}
			else {++i;changed=true;}
		}
		minCost = min(minCost,cost);
	}
	cout<<minCost<<'\n';
	return 0;
}