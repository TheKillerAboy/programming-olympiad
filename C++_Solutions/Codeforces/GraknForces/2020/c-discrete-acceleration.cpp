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
template<typename T, size_t S> void TRACEV(array<T,S> t){TRACEV("[");TRACEV(t[0]);FOR1(i,S){TRACEV(",");TRACEV(t[i]);}TRACEV("]");}
template<typename T,typename... Args>void TRACEUT_(T t){TRACEV(t);}
template<typename T,typename... Args>void TRACEUT_(T t, Args... args){TRACEV(t); TRACED(","); TRACEUT_(args...);}
template<typename T,typename... Args>void TRACEUT(T t, Args... args){TRACED('('); TRACEUT_(t,args...); TRACED(")");}
template<typename Tuple, size_t... Is>void TRACET_(Tuple t, index_sequence<Is...>){TRACEUT(get<Is>(t)...);}
template<typename Tuple>void TRACET(Tuple t){TRACET_(t,make_index_sequence<tuple_size<Tuple>::value>{});}
#define TRACEP(p_) TRACED("("); TRACEV(p_.first);TRACED(",");TRACEV(p_.second);TRACED(")");
template<typename... Args> void TRACEV(tuple<Args...> t){TRACET(t);}
template<typename l, typename r> void TRACEV(pair<l,r> t){TRACEP(t);}
template<template<typename...> class T, typename... K> void TRACEV(T<K...> t){if(t.empty()){TRACEV("[]");return;}auto it = t.begin();
TRACED("[");TRACEV(*it);for(++it;it!=t.end();++it){TRACED(",");TRACEV(*it);}TRACED("]");}
template<typename T> void TRACEV(T* b, T* e){if(b==e){TRACEV("[]");return;}TRACED("[");TRACEV(*b);while(++b!=e){TRACED(",");TRACEV(*b);}TRACED("]");}
template<typename T> void TRACE(T t){TRACEV(t);_N;}
template<typename T,typename... Ts> void TRACE(T t,Ts... args){TRACEV(t); _T; TRACE(args...);}

#define ll long long int
#define ull unsigned long long int
#define pii pair<int,int>
#define pfi pair<double,int>
#define SIZE (int)1e5+5

int t,n,l;
double arr[SIZE];
pfi car1[SIZE],car2[SIZE];

int main(){
	cin.tie(0);
	cout.precision(17);
	ios::sync_with_stdio(false);
	cin>>t;
	FORI(oo,t){
		cin>>n>>l;
		arr[0]=0;
		FOR1(i,n+1) cin>>arr[i];
		arr[n+1] = l;
		car1[0] = pfi{0,1};
		FOR1(i,n+2){
			car1[i] = pfi{car1[i-1].first+(double)(arr[i]-arr[i-1])/car1[i-1].second,car1[i-1].second+1};
		}
		car2[n+1] = pfi{0,1};
		FORR(i,n+1){
			car2[i] = pfi{car2[i+1].first+(double)(arr[i+1]-arr[i])/car2[i+1].second,car2[i+1].second+1};
		}
		double min_ = DBL_MAX;
		FOR(i,n+1){
			pfi car1_ = car1[i];
			pfi car2_ = car2[i+1];
			if(car1_.first<=car2_.first){
				double car1loc = arr[i]+(car2_.first-car1_.first)*car1_.second;
				if(car1loc<=arr[i+1]){
					min_ = min(min_,car2_.first+(double)(arr[i+1]-car1loc)/(car1_.second+car2_.second));
				}
			}
			else{
				double car2loc = arr[i+1]+(car2_.first-car1_.first)*car2_.second;
				if(arr[i]<=car2loc){
					min_ = min(min_,car1_.first+(double)(car2loc-arr[i])/(car1_.second+car2_.second));
				}

			}
		}
		cout<<fixed<<min_<<'\n';

	}

	return 0;
}