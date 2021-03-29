#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(long long i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(long long i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(long long i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(long long i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(long long i_=1;i_<a_;++i_)

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

#define ll long long long long
#define ull unsigned long long long long
#define pii pair<long long,long long>
#define iii array<long long,3>
#define SSIZE (long long)1e5+5
#define BSIZE (long long)1e6+5

long long onlyOnes[5*SSIZE];
vector<pii> range;
vector<long long> rangeSize;
vector<pii> rangeSeg;
long long n, rs;
string s;

inline long long rangeIndexNext(long long l){
	return upper_bound(range.begin(),range.begin()+rs,pii{l,LLONG_MAX}) - range.begin();
}

void fillSeg(long long nl, long long nr, long long ni){
	if(nl<nr){
		long long mid = (nl+nr)>>1;
		fillSeg(nl,mid,2*ni+1);
		fillSeg(mid+1,nr,2*ni+2);
		rangeSeg[ni] = max(rangeSeg[2*ni+1],rangeSeg[2*ni+2]);
	}
	else if(nl==nr) rangeSeg[ni] = pii{rangeSize[nl],nl};
}

pii findMax(long long ql, long long qr, long long nl, long long nr, long long ni){
	if(ql<=nl&&nr<=qr) return rangeSeg[ni];
	else if(nl>qr||ql>nr) return {LLONG_MIN, -1};
	else{
		long long mid = (nl+nr)>>1;
		return max(findMax(ql,qr,nl,mid,2*ni+1),findMax(ql,qr,mid+1,nr,2*ni+2));
	}
}

long long dac(long long l, long long r){
	if(l>r) return 0;
	if(s[l]=='1'&&s[r]=='1'&&rangeIndexNext(l)-1==rangeIndexNext(r)-1) return onlyOnes[r-l+1];
	long long ql,qr;
	long long vl,vr;
	ql = rangeIndexNext(l);
	qr = s[r]=='1'?rangeIndexNext(r)-2:rangeIndexNext(r)-1;
	vl = (ql-1)>=0&&s[l]=='1'?(range[ql-1].second - l + 1):0;
	vr = (qr+1)>=0&&s[r]=='1'?(r - range[qr+1].first + 1):0;
	pii max_ = {0,-1};
	if(vl>0) max_ = max(max_, pii{vl,ql-1});
	if(vr>0) max_ = max(max_, pii{vr,qr+1});
	if(ql<=qr) max_ = max(max_, findMax(ql,qr,0,rs-1,0));
	if(max_.first == 0) return 0;
	long long mri, ml, mr;
	mri = max_.second;
	ml = max(range[mri].first,l);
	mr = min(r, range[mri].second);
	long long sl = ml - l, sr = r - mr;
	return (sl+1)*(sr+1)*(mr-ml+1) + dac(l,mr-1) + dac(ml+1,r) - onlyOnes[max(mr-ml-1,(long long)0)];
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	onlyOnes[0] = 0;
	onlyOnes[1] = 1;
	FORS(2,i,5*SSIZE) onlyOnes[i] = 2*onlyOnes[i-1] - onlyOnes[i-2] + i;
	cin>>n>>s;
	list<pii> rangeList;
	FOR(i,n){
		if(s[i]=='1'){
			if(i>0&&s[i-1]=='1') (*rangeList.rbegin()).second = i;
			else rangeList.push_back({i,i});
		}
	}
	rs = rangeList.size();
	range.resize(rs);
	long long j = 0;
	FORA(v,rangeList) range[j++] = v;
	rangeSize.resize(rs);
	FOR(i,rs) rangeSize[i] = range[i].second-range[i].first+1;
	rangeSeg.resize(4*rs);
	fillSeg(0,rs-1,0);
	cout<<dac(0,n-1);

	return 0;
}