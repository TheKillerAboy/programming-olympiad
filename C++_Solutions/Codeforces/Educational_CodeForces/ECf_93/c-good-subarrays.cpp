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
template<typename T> void TRACE(T t){TRACEV(t);_N;}
template<typename T,typename... Ts> void TRACE(T t,Ts... args){TRACEV(t); _T; TRACE(args...);}

#define ll long long int
#define ull unsigned long long int
#define pii pair<int,int>

ll arr[(int)1e5+5];
ll prefixsum[(int)1e5+5];
ll suffixsum[(int)1e5+5];
string sarr;
int t,n;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n;
		cin>>sarr;
		map<int,vector<int>> nums;
		ll total = 0;
		FOR(i,n){arr[i]=sarr[i]-'0';total+=arr[i];}
		prefixsum[0] = 0;
		suffixsum[n+1] = 0;
		FOR1(i,n+1){
			prefixsum[i] = prefixsum[i-1] + arr[i-1];
			suffixsum[n+1-i] = suffixsum[n+2-i] + arr[n-i];
		}
		FOR1(i,n+1){
			// TRACE(i,suffixsum[i+1]);
			nums[suffixsum[i+1]+i].push_back(i);
		}
		ll out = 0;
		ll need;
		FOR1(l,n+1){
			need = total + l - 1 - prefixsum[l-1];
			if(nums.find(need) != nums.end()){
				ll new_ = nums[need].end() - lower_bound(nums[need].begin(),nums[need].end(), l);
				// TRACE(l,need,nums[need],new_);
				out += new_;
			}
		}
		cout<<out<<'\n';
	}
	return 0;
}