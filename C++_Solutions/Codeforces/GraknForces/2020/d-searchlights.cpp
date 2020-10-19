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

pii searchlighs[2000];
pii criminals[2000];
pii updom[2002*2002];
int maxy[2002*2002];
int updomx[2002*2002];
int n,m,uds;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	FOR(i,n) cin>>criminals[i].first>>criminals[i].second;
	FOR(i,m) cin>>searchlighs[i].first>>searchlighs[i].second;
	uds = 0;
	FOR(i,n){
		FOR(j,m){
			if(searchlighs[j].first-criminals[i].first>=0&&searchlighs[j].second-criminals[i].second+1>=0)
			updom[uds++] = pii{searchlighs[j].first-criminals[i].first,searchlighs[j].second-criminals[i].second+1};
		}
	}
	sort(updom,updom+uds);
	FOR(i,uds) updomx[i] = updom[i].first;
	maxy[uds-1] = updom[uds-1].second;
	FOR1(i,uds){
		maxy[uds-1-i] = max(maxy[uds-i],updom[uds-1-i].second);
	}
	int out = INT_MAX;
	FOR(i,(int)1e6+1){
		int j = lower_bound(updomx,updomx+uds,i)-updomx;
		if(j>=0) out = min(out,i+(j<uds?maxy[j]:0));
	}
	cout<<out<<'\n';


	return 0;
}