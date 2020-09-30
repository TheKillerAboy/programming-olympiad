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
#define MOD 998244353
#define MAXS 3*(int)1e5+5

int mul(int a_, int b_){
	ll a = a_,b = b_;
	return (a*b)%MOD;
}
int add(int a_, int b_){
	ll a = a_,b = b_;
	return (a+b)%MOD;
}
int neg(int a_, int b_){
	if(a_>b_){return a_-b_;}
	return a_-b_+MOD;
}
int FAC[MAXS];

int n,k;
int l,r;

int gcdExtended(int a, int b, int *x, int *y) 
{ 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    int x1, y1; 
    int gcd = gcdExtended(b%a, a, &x1, &y1); 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
    return gcd; 
} 
int modInverse(int b) 
{ 
    int x, y;
    int g = gcdExtended(b, MOD, &x, &y); 
    if (g != 1) 
        return -1; 
    return (x%MOD + MOD) % MOD; 
} 
  
int modDivide(int a, int b) 
{ 
    a = a % MOD; 
    int inv = modInverse(b); 
    if(inv<0){
    	inv += ((-inv)/MOD+1)*MOD;
    }
    return mul(inv,a); 
} 

int combo(int s, int k){
	if(s<k){return 0;}
	return modDivide(FAC[s],mul(FAC[k],FAC[s-k]));
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	FAC[0]=1;
	FAC[1]=1;
	FORS(2,i,MAXS){
		FAC[i] = mul(FAC[i-1],i);
	}
	cin>>n>>k;
	map<int,set<pii>> queue;	
	FOR(i,n){
		cin>>l>>r;
		queue[l].insert(pii{i,0});
		queue[r+1].insert(pii{i,1});
	}
	set<int> on;
	int out = 0;
	FORA(events, queue){
		int pre = on.size();
		FORA(event, events.second){
			if(event.second==0){
				on.insert(event.first);
			}
			else{
				on.erase(event.first);
				pre--;
			}
		}
		if(pre<on.size()){
			out = add(out,neg(combo(on.size(),k),combo(pre,k)));
		}
	}
	cout<<out;



	return 0;
}