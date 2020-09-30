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

int arr[2*(int)1e5+5];
pii segtree[8*(int)1e5+5];
int t,n;

void setup_seg(int nl, int nr, int ni){
	if(nl<nr){
		int mid = (nl+nr)>>1;
		setup_seg(nl,mid,2*ni+1);
		setup_seg(mid+1,nr,2*ni+2);
		segtree[ni] = max(segtree[2*ni+1],segtree[2*ni+2]);
	}
	else if(nl==nr){
		segtree[ni] = pii{arr[nl],nl};
	}
	else{
		segtree[ni] = pii{INT_MIN,-1};
	}
}

pii max_seg(int ql, int qr, int nl, int nr, int ni){
	if(ql<=nl&&nr<=qr){
		return segtree[ni];
	}
	else if(nr<ql||qr<nl){
		return pii{INT_MIN,-1};
	}
	else{
		int mid = (nl+nr)>>1;
		return max(max_seg(ql,qr,nl,mid,2*ni+1),max_seg(ql,qr,mid+1,nr,2*ni+2));
	}
}

ll fill(int left, int right, int value){
	if(left==right){
		return value - arr[left];
	}
	else if(left<right){
		int k = max_seg(left,right,0,n-1,0).second;
		return fill(left,k-1,arr[k])+fill(k+1,right,arr[k])+value - arr[k];
	}
	return 0;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n;
		FOR(i,n){cin>>arr[i];}
		setup_seg(0,n-1,0);
		arr[n]=INT_MAX;
		int last_max = 0;
		ll out = 0;
		FOR1(i,n+1){
			if(arr[i]>=arr[last_max]){
				// TRACE(last_max,i);
				int start = last_max+1, end = i-1;	
				out += fill(start,end,arr[last_max]);
				last_max = i;
			}
		}
		cout<<out<<'\n';
	}

	return 0;
}