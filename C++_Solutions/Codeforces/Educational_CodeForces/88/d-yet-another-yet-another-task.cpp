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
#define SSIZE (int)1e5+5
#define DSSIZE 2*(int)1e5+5
#define BSIZE (int)1e5+5

int prefixSum[DSSIZE];
int suffixSum[DSSIZE];
int prefixSumSeg[4*DSSIZE];
int suffixSumSeg[4*DSSIZE];
map<int,vector<int>> locs;
int arr[DSSIZE];
int n;

void fillseg(int* arr, int* seg, int nl, int nr, int ni){
	if(nl<nr){
		int mid = (nl+nr)>>1;
		fillseg(arr,seg,nl,mid,2*ni+1);
		fillseg(arr,seg,mid+1,nr,2*ni+2);
		seg[ni] = max(seg[2*ni+1],seg[2*ni+2]);
	}
	else if(nl==nr){
		seg[ni] = arr[nl];
	}
}

int get_max(int* seg, int ql, int qr, int nl, int nr, int ni){
	if(ql<=nl&&nr<=qr){
		return seg[ni];
	}
	else if(nr<ql||qr<nl){
		return INT_MIN;
	}
	else{
		int mid = (nl+nr)>>1;
		return max(get_max(seg,ql,qr,nl,mid,2*ni+1),get_max(seg,ql,qr,mid+1,nr,2*ni+2));
	}
}

int next_bigger(int i){
	int out = n;
	auto it = locs.find(arr[i]);
	it++;
	while(it!=locs.end()){
		vector<int>& v = (*it).second;
		auto it2 = upper_bound(v.begin(),v.end(),i);
		if(it2!=v.end()){
			out = min(out,*it2);
		}
		it++;
	}
	return out;
}

int prev_bigger(int i){
	int out = -1;
	auto it = locs.find(arr[i]);
	it++;
	while(it!=locs.end()){
		vector<int>& v = (*it).second;
		auto it2 = upper_bound(v.begin(),v.end(),i);
		if(it2!=v.begin()){
			if(it2==v.end()){
				out = max(out,*v.rbegin());
			}
			else{
				it2--;
				out = max(out,*it2);
			}
		}
		it++;
	}
	return out;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n;
	FOR(i,n) cin>>arr[i];
	prefixSum[0] = arr[0];
	FOR1(i,n) prefixSum[i] = prefixSum[i-1] + arr[i];
	suffixSum[n-1] = arr[n-1];
	FOR1(i,n) suffixSum[n-1-i] = suffixSum[n-i] + arr[n-1-i];
	fillseg(prefixSum,prefixSumSeg,0,n-1,0);
	fillseg(suffixSum,suffixSumSeg,0,n-1,0);
	FOR(i,n) locs[arr[i]].push_back(i);
	int out = 0;
	FOR(i,n){
		int left_bigger = prev_bigger(i)+1;
		int right_bigger = next_bigger(i)-1;
		int cur = 0;
		if(left_bigger!=i){
			int add = get_max(suffixSumSeg,left_bigger,i-1,0,n-1,0) - suffixSum[i];
			if(add>0) cur+=add;
		}
		if(right_bigger!=i){
			int add = get_max(prefixSumSeg,i+1,right_bigger,0,n-1,0) - prefixSum[i];
			if(add>0) cur+=add;
		}
		out = max(out,cur);
	}
	cout<<out<<'\n';

	return 0;
}