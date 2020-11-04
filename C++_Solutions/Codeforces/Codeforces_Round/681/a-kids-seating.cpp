#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(int i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(int i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(int i_=1;i_<a_;++i_)

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
#define iii array<int,3>
#define SSIZE (int)1e5+5
#define BSIZE (int)1e6+5

bool is_prime[500];

void set_primes(){
	FOR(i,500) is_prime[i] = true;
	is_prime[0] = is_prime[1] = false;
	FOR(i,floor(sqrt(500))+1){
		if(is_prime[i]){
			int j = i*i;
			while(j<500){
				is_prime[j] = false;
				j+=i;
			}
		}
	}
}

int gcd(int a, int b){
	if(b>a)return gcd(b,a);
	if(b==0) return a;
	return gcd(b,a%b);
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int t,n;
	set_primes();
	cin>>t;
	while(t--){
		cin>>n;
		list<int> out;
		FORI(s,4*n){
			if(s%2==1) continue;
			FORS(s,i,4*n+1){
				if(i%2==1) continue;
				bool pos = true;
				FORA(other, out) pos = pos&(gcd(i,other)%other>1);
				pos = pos&(!is_prime[i]);
				// TRACE(out);
				if(pos) out.push_back(i);
			}
			if(out.size()>=n) break;
			out.clear();
		}
		if(out.size()>=n){
			int i = 0;
			auto it = out.begin();
			while(i<n){
				cout<<*it<<' ';
				i++;
				it++;
			}
			cout<<'\n';
		}
		else cout<<n<<'\n';
	}

	return 0;
}