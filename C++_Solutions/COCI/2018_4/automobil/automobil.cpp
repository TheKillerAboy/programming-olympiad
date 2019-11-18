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
template<template<typename...> class T, typename... K> void TRACEV(T<K...> t){auto it = t.begin();
TRACED("[");TRACEV(*it);for(++it;it!=t.end();++it){TRACED(", ");TRACEV(*it);}TRACED("]");}
template<typename T> void TRACE(T t){TRACEV(t);_N;}
template<typename T,typename... Ts> void TRACE(T t,Ts... args){TRACEV(t); _T; TRACE(args...);}

#define ull unsigned long long int
#define pii pair<ll,ll>
#define MOD 1000000007

inline ll add(ll a, ll b){return(a+b)%MOD;}
inline ll mul(ll a, ll b){return(a*b)%MOD;}
ll sub(ll a, ll b){ll out = a-b;while(out<0)out+=MOD;return out;}
template<typename T,typename... Args> ll mul(T t, Args... args){return mul(t,mul(args...));}
template<typename T,typename... Args> ll add(T t, Args... args){return add(t,add(args...));}
template<typename T, typename... Args> ll sub(T t, Args... args){return sub(t,add(args...));}
ll pow(ll a, ll b){if(b==0)return 1;if(b==1)return a;ll temp = pow(a,b/2);return mul(temp,temp,b%2?a:1);}
ll div(ll a, ll b){return mul(a,pow(b,(ll)(MOD-2)));}

ll RSUM;
ll CSUM;
ll N,M,K;
inline ll getRow(ll r){
	return add(RSUM,mul(r,M,M));
}
inline ll getCol(ll c){
	return add(CSUM,mul(c,N));
}
inline ll getValue(ll r, ll c){
	return add(c,(ll)1,mul(r,M));
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>N>>M>>K;
	RSUM = 0;
	ll last = 1;
	FOR(i,M){
		RSUM = add(RSUM,last);
		last = add(last,(ll)1);
	}
	last = 1;
	CSUM = 0;
	FOR(i,N){
		CSUM = add(CSUM,last);
		last = add(last,M);
	}
	vector<ll> rows(N,1);
	vector<ll> columns(M,1);
	set<ll> rowsSelected;
	set<ll> columnsSelected;
	char type;
	ll value, index;
	FOR(i,K){
		cin>>type>>index>>value;
		--index;
		if(type == 'R'){
			rowsSelected.insert(index);
			rows[index] = mul(rows[index],value);
		}
		else{
			columnsSelected.insert(index);
			columns[index] = mul(columns[index],value);
		}
	}
	ll total = 0;
	FOR(r,N) total = add(total,getRow(r));
	FORA(r,rowsSelected){
		total = add(total,mul(getRow(r),rows[r]));
		total = sub(total,getRow(r));
	}
	FORA(c,columnsSelected){
		total = add(total,mul(getCol(c),columns[c]));
		total = sub(total,getCol(c));
	}
	FORA(r,rowsSelected){
		FORA(c,columnsSelected){
			total = add(total,mul(mul(getValue(r,c),rows[r]),columns[c]));
			total = add(total,getValue(r,c));
			total = sub(total,mul(getValue(r,c),columns[c]));
			total = sub(total,mul(getValue(r,c),rows[r]));
		}
	}
	cout<<total<<'\n';
	return 0;
}