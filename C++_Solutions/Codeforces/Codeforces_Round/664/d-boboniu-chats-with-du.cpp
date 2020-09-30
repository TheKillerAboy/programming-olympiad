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

int n,d,m;
int i_max_not_muzzel;
int arr[(int)1e5+5];
ll prefix[(int)1e5+5];

void setup_pref(){
	prefix[0] = arr[0];
	FOR1(i,n){prefix[i]=prefix[i-1]+arr[i];}
}

ll pref_sum(int l, int r){
	return l>r?0:(l==0?prefix[r]:prefix[r]-prefix[l-1]);
}

ll max_with_muzzels(int k){
	ll out = 0;
	int left = n - k*(d+1);
	int index = n - 1;
	out += pref_sum(index-k+1,index);
	index -= k;
	if(left > 0){
		out+=arr[index--];
		left--;
		int i_max_not_muzzel_a = min(i_max_not_muzzel,index);
		if(index>=i_max_not_muzzel){
			if(i_max_not_muzzel+1+min(d-1,index-i_max_not_muzzel)<left){
				return LLONG_MIN;
			}
		}
		else{
			if(index+1<left){
				return LLONG_MIN;
			}
		}
		out+=pref_sum(i_max_not_muzzel_a - min(left,i_max_not_muzzel_a+1) + 1,i_max_not_muzzel_a);
	}
	return out;
}

ll max_with_muzzels2(int k){
	if(k==0){
		return i_max_not_muzzel!=n-1?LLONG_MIN:pref_sum(0,n-1);
	}
	int index = n-1;
	ll out = pref_sum(index - k + 1, index);
	index -= k;
	int left = n - (k-1)*(d+1) - 1;
	if(left<0){return LLONG_MIN;}
	if(index >= i_max_not_muzzel){
		if(i_max_not_muzzel+1+min(d,index-i_max_not_muzzel)<left){
			return LLONG_MIN;
		}
		out+=pref_sum(i_max_not_muzzel - min(left,i_max_not_muzzel+1) + 1,i_max_not_muzzel);
	}
	else{
		if(index+1<left){
			return LLONG_MIN;
		}
		out+=pref_sum(index+1-left,index);
	}
	return out;

}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>d>>m;
	FOR(i,n){cin>>arr[i];}
	sort(arr,arr+n);
	setup_pref();
	i_max_not_muzzel = n-1;
	FOR(i,n){if(arr[i]>m){i_max_not_muzzel=i-1;break;}}
	ll out = 0;
	FOR(k,min(n/(1+d)+3,n-i_max_not_muzzel)){
		out = max(out, max_with_muzzels2(k));
	}
	cout<<out;

	return 0;
}