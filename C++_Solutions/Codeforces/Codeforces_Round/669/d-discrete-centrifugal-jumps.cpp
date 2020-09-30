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
#define SIZE 4*(ll)1e5+5

int n;
int arr[SIZE];
int arr_[SIZE];
int forward_max_middle[SIZE];
int forward_min_middle[SIZE];
int backward_max_middle[SIZE];
int backward_min_middle[SIZE];


vector<map<int,int>> peaks;
vector<map<int,int>> valleys;
bool peak;

vector<map<int,int>>& current_slope(){
	return peak?peaks:valleys;
}

void slope_change(){
	peak = !peak;
	current_slope().emplace_back();
}

void first_lesser_method(int* arr, int* out){
	FORI(i,n) out[i] = i;
	peaks.clear();
	valleys.clear();
	peak = false;
	slope_change();
	FORI(i,n){
		current_slope().back()[arr[i]]=i;
		if(arr[i-1]<arr[i] && arr[i]>arr[i+1]) slope_change();
		if(arr[i-1]>arr[i] && arr[i]<arr[i+1]) slope_change();
	}
	TRACE(peaks,valleys);
	int k = min(peaks.size(),valleys.size());
	FOR(i,k){
		FORA(p,peaks[i]){
			auto it = valleys[i].lower_bound(p.first);
			if((*it).first==p.first){
				out[p.second] = (*it).second;
			}
			else if(it!=valleys[i].begin()){
				--it;
				out[p.second] = (*it).second;
			}
		}
	}
}

void reverse(int* arr){
	FOR(i,n+2) arr_[i]=arr[i];
	FOR(i,n+2) arr[n+1-i]=arr_[i];
}

void inverse(){
	FOR(i,n+2) arr[i] = INT_MAX - arr[i];
}

void inverseIndex(int* arr){
	FORI(i,n) arr[i] = n-arr[i];
}

void print(int* arr){TRACEV(arr+1,arr+n+1);_N}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n;
	FORI(i,n) cin>>arr[i];
	arr[0]=0;
	arr[n+1]=0;
	first_lesser_method(arr,forward_max_middle);
	inverse();
	first_lesser_method(arr,forward_min_middle);
	inverse();
	reverse(arr);
	first_lesser_method(arr,backward_max_middle);
	reverse(backward_max_middle);
	inverseIndex(backward_max_middle);
	inverse();
	first_lesser_method(arr,backward_min_middle);
	reverse(backward_min_middle);
	inverseIndex(backward_min_middle);
	print(forward_max_middle);
	print(forward_min_middle);
	print(backward_max_middle);
	print(backward_min_middle);

	return 0;
}