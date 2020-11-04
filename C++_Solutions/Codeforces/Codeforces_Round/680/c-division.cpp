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

map<long long,long long> all_factors;
list<long long> all_divisors;

void make_all_factors(long long a){
	all_factors.clear();
	FORS(2,i,floor(sqrt(a))+1){
		while(a%i==0){
			if(all_factors.find(i)==all_factors.end()) all_factors[i] = 0;
			a/=i;
			++all_factors[i];
		}
	}
	if(a>1){
		if(all_factors.find(a)==all_factors.end()) all_factors[a] = 0;
		++all_factors[a];
	}
}

void make_all_divisors(long long a){
	all_divisors.clear();
	long long n = all_factors.size()+1;
	vector<long long> factors(n);
	vector<long long> max_factors(n);
	FOR(i,n) factors[i] = 0;
	long long j = 0;
	FORA(factor, all_factors){
		while(a%factor.first==0){
			a/=factor.first;
			max_factors[j]++;
		}
		j++;
	}
	max_factors[n-1] = 2;
	while(factors[n-1]==0){
		long long current = 1;
		j = 0;
		FORA(factor, all_factors){
			FOR(k,factors[j]) current*=factor.first;
			j++;
		}
		all_divisors.push_back(current);
		factors[0]++;
		FOR(i,n){
			if(factors[i]>max_factors[i]){
				factors[i]=0;
				factors[i+1]++;
			}
		}
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	long long t;
	long long a,b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		if(a%b==0){
			long long max_ = 0;
			make_all_factors(b);
			make_all_divisors(a);
			FORA(divisor, all_divisors) {
				long long x = divisor;
				if(x%b!=0 && a%x==0) max_ = max(max_, x);
				x = a/divisor;
				if(x%b!=0 && a%x==0) max_ = max(max_, x);
			}
			cout<<max_<<'\n';
		}
		else cout<<a<<'\n';
	}

	return 0;
}