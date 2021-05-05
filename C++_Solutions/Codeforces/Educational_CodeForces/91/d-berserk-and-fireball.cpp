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

// #define ll long long long long
// #define ull unsigned long long long long
#define pii pair<long long,long long>
#define iii array<long long,3>
#define SSIZE (long long)1e5+5
#define BSIZE (long long)1e6+5
#define NINF LLONG_MIN

long long n,m;
long long x,y,k;
long long arr[2*SSIZE];
long long arr2[2*SSIZE];
pii arr_sorted[2*SSIZE];

long long best_moves(long long l, long long r, long long min_max){
	list<long long> lst;
	FORS(l,i,r+1) lst.push_back(arr[i]);
	auto it = lst.begin();
	long long out = 0;
	while(it!=lst.end()){
		if(*it>min_max){
			// if(x/k>=y){
			// 	long long max_ = 0;
			// 	if(next(it)!=lst.end()) max_ = max(max_, *next(it));
			// 	if(it!=lst.begin()) max_ = max(max_, *prev(it));
			// 	if(max_>*it){
			// 		it = lst.erase(it);
			// 		out+=y;
			// 		continue;
			// 	}
			// }
			if(lst.size()>=k){
				long long delted = 0;
				while(delted<k){
					if(it!=lst.end()){
						it = lst.erase(it);
					}
					else{
						lst.erase(prev(it));
					}
					delted++;
				}	
			}
			else{
				return NINF;
			}
			out += x;
		}
		else ++it;
	}
	;
	out += min(lst.size()*y,(lst.size()/k)*x+(lst.size()%k)*y);
	return out;
}

#define get_index(val) (*lower_bound(arr_sorted,arr_sorted+n,pii{val,0})).second

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	cin>>x>>k>>y;
	FOR(i,n) cin>>arr[i];
	FOR(i,m) cin>>arr2[i];
	FOR(i,n) arr_sorted[i] = {arr[i],i};
	sort(arr_sorted,arr_sorted+n);
	long long cur = -1;
	bool pos = true;
	FOR(i,m){
		long long next = get_index(arr2[i]);
		if(next>cur) cur = next;
		else pos = false;
	}
	if(!pos){
		cout<<-1<<'\n';
	}
	else{
		long long out = 0;
		if(get_index(arr2[0])!=0){
			long long cur_best = best_moves(0,get_index(arr2[0])-1,arr[get_index(arr2[0])]);
			if(cur_best == NINF) pos = false;
			else out += cur_best;
		}
		if(get_index(arr2[m-1])!=n-1){
			long long cur_best = best_moves(get_index(arr2[m-1])+1,n-1,arr[get_index(arr2[m-1])]);
			if(cur_best == NINF) pos = false;
			else out += cur_best;
		}
		FOR(i,m-1){
			long long cur_pos = get_index(arr2[i]);
			long long next_pos = get_index(arr2[i+1]);
			long long cur_best = best_moves(cur_pos+1,next_pos-1,max(arr[cur_pos],arr[next_pos]));
			if(cur_best == NINF) pos = false;
			else out += cur_best;
		}
		if(!pos) cout<<-1<<'\n';
		else cout<<out<<'\n';
	}


	return 0;
}
