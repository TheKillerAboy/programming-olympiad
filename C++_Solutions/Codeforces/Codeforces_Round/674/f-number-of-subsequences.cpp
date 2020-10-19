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
#define MOD ((ll)1e9+7)
#define SIZE (2*(int)1e5+5)

int add(int a_, int b_){
	ll a=a_,b=b_;
	return (a+b)%MOD;
}

int mul(int a_, int b_){
	if(a_ == 0) return 0;
	ll a=a_,b=b_;
	return (a*b)%MOD;
}

int neg(int a_, int b_){
	ll a=a_,b=b_;
	if(a>=b)return a-b;
	else return (a+MOD-b)%MOD;
}

int n;
string s;
int qs;
int a[SIZE];
int q[SIZE];
int ab[SIZE];
int aq[SIZE];
int qb[SIZE];
int qq[SIZE];
int abc[SIZE];
int POW3[SIZE];

#define pow3(i_) (i_>=0?POW3[i_]:0)

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>s;
	POW3[0] = 1;
	FOR1(i,SIZE) POW3[i] = mul(POW3[i-1],3);
	a[0] = 0;
	q[0] = 0;
	ab[0] = 0;
	aq[0] = 0;
	qb[0] = 0;
	qq[0] = 0;
	abc[0] = 0;
	qs = 0;
	FOR(i,n) if(s[i]=='?') qs++;
	FORI(i, n){
		a[i] = a[i-1];
		q[i] = q[i-1];
		ab[i] = ab[i-1];
		aq[i] = aq[i-1];
		qb[i] = qb[i-1];
		qq[i] = qq[i-1];
		abc[i] = abc[i-1];
		if(s[i-1] == '?'){
			qq[i] = add(qq[i],q[i]);
			aq[i] = add(aq[i],a[i]);
			q[i]++;
		}
		if(s[i-1] == 'a') a[i]++;
		if(s[i-1] == 'b'){
			ab[i] = add(ab[i],a[i]);
			qb[i] = add(qb[i],q[i]);
		}
		if(s[i-1] == 'c' || s[i-1] == '?'){
			int k = s[i-1]=='c'?0:1;
			abc[i] = add(abc[i],add(add(mul(ab[i-1],pow3(qs-k)),mul(aq[i-1],pow3(qs-k-1))),add(mul(qb[i-1],pow3(qs-k-1)),mul(qq[i-1],pow3(qs-k-2)))));
		}
	}
	cout<<abc[n]<<'\n';

	return 0;
}