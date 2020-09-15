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

#define ll long long int
#define ull unsigned long long int
#define pii pair<int,int>

int Q;
int N;
int pos[5];
int neg[5];
int posmax,negmax;
int arr[(int)1e5+5];
int out[5];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>Q;
	while(Q--){
		FOR(i,5){pos[i]=0;}
		FOR(i,5){neg[i]=0;}
		posmax = 0;
		negmax = 0;
		cin>>N;
		FOR(i,N){cin>>arr[i];}
		sort(arr,arr+N);
		FOR(i,5){
			if(i<N && arr[i]<0){
				neg[i] = arr[i];
				negmax++;
			}
		}
		FOR(i,5){
			if(N-1-i >= 0 && arr[N-1-i] >= 0){
				pos[i] = arr[N-1-i];
				posmax++;
			}
		}
		ll maxV = LLONG_MIN;
		if(posmax==0){
			ll val = 1;
			FOR(i,5){
				val *= arr[N-1-i];
			}
			maxV = max(maxV, val);
		}
		else{
			FOR(p,6){
				if(p <= posmax && 5-p <= negmax){
					ll val = 1;
					FOR(i,p){
						val*=pos[i];
					}
					FOR(i,5-p){
						val*=neg[i];
					}
					maxV = max(maxV,val);
				}
			}
		}
		cout<<maxV<<'\n';
	}


	return 0;
}