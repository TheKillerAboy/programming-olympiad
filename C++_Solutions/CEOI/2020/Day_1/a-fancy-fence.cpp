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
#define uint unsigned long long int
#define pii pair<int,int>
#define MOD ((ll)1e9 + 7)

int mul(int a_,int b_){
	ll a = (ll)a_;
	ll b = (ll)b_;
	return (a * b)%MOD;
}

int add(int a_, int b_){
	ll a = (ll)a_;
	ll b = (ll)b_;
	return (a+b)%MOD;
}

int neg(int a_, int b_){
	ll a = (ll)a_;
	ll b = (ll)b_;
	if(a > b){
		return a-b;
	}
	else{
		return a+MOD-b;
	}
}

int div2(int a_){
	ll a = (ll)a_;
	if(a%2==0){return a/2;}
	else{return ((a+MOD)/2)%MOD;}
}

int n;
vector<int> w,h;
vector<pair<int,int>> segtree;
vector<int> prefixsum;

void fiint_seg(int nl, int nr, int ni){
	if(nl<nr){
		int mid = (nl+nr)>>1;
		fiint_seg(nl,mid,2*ni+1);
		fiint_seg(mid+1,nr,2*ni+2);
		segtree[ni] = min(segtree[2*ni+1],segtree[2*ni+2]);
	}
	else if(nl == nr){
		segtree[ni] = pair<int,int>{h[nl],nl};
	}
}

pair<int,int> min_seg(int ql, int qr, int nl, int nr, int ni){
	if(ql<=nl && nr<= qr){
		return segtree[ni];
	}
	else if(nr<ql || qr<nl){
		return pair<int,int>{INT_MAX,-1};
	}
	else{
		int mid = (nl+nr)>>1;
		return min(min_seg(ql,qr,nl,mid,2*ni+1),min_seg(ql,qr,mid+1,nr,2*ni+2));
	}
}

void fiint_pre(){
	prefixsum[0] = w[0];
	FOR1(i,n){
		prefixsum[i] = add(prefixsum[i-1],w[i]);
	}
}

int get_pre(int l, int r){
	if(l==0){
		return prefixsum[r];
	}
	else{
		return neg(prefixsum[r],prefixsum[l-1]);
	}
}

int delta(int a){
	return div2(mul(a,add(a,1)));
}

int T(int i){
	return mul(delta(h[i]),delta(w[i]));
}

int answer(int l, int r){
	if(l<=r){
		int k = min_seg(l,r,0,n-1,0).second;
		int out = mul(get_pre(l,k),get_pre(k,r));
		out = neg(out,mul(w[k],w[k]));
		out = add(out,delta(w[k]));
		out = mul(out,delta(h[k]));
		out = add(out,answer(l,k-1));
		out = add(out,answer(k+1,r));
		return out;
	}
	else{
		return 0;
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n;
	w.resize(n);
	h.resize(n);
	prefixsum.resize(n);
	segtree.resize(5*n);
	FOR(i,5*n){segtree[i]=pair<int,int>{INT_MAX,-1};}
	FOR(i,n){cin>>h[i];}
	FOR(i,n){cin>>w[i];}
	fiint_seg(0,n-1,0);
	fiint_pre();
	cout<<answer(0,n-1)<<'\n';

	return 0;
}