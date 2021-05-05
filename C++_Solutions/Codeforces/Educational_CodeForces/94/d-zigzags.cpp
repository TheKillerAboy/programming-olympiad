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
#define ull unsigned long long ll
#define pii pair<ll,ll>

ll t,n;
ll arr[(ll)1e4];
ll comboarr[(ll)1e4];

map<ll,vector<ll>> locations;

void setup_locations(){
	locations.clear();
	FOR(i,n){
		locations[arr[i]].push_back(i);
	}
}

ll first(ll l, ll v){
	auto it = lower_bound(locations[v].begin(),locations[v].end(),l);
	return it==locations[v].end()?n:*it;
}

ll pref_sum(ll l, ll r, ll v){
	auto left = lower_bound(locations[v].begin(),locations[v].end(),l);
	auto right = upper_bound(locations[v].begin(),locations[v].end(),r);
	return right - left;
}

ll DP[(ll)1e4][5][2];

ll dp(ll* arr, ll size, ll i, ll amount, bool mod){
	if(size-i < amount) return 0;
	ll& out = DP[i][amount][mod];
	if(out != -1) return out;
	out = dp(arr,size,i+1,amount,mod);
	if(i%2==mod){
		if(amount==1) out += arr[i] ;
		else out += arr[i]*dp(arr,size,i+1,amount-1,!mod);
	}
	return out;
}

ll combo(ll a, ll b){
	if(a==b){
		ll amount = locations[a].size();
		if(amount>=4) return amount*(amount-1)*(amount-2)*(amount-3)/24;
		else return 0;
	}
	if(pref_sum(0,n-1,b)<2&&pref_sum(0,n-1,a)<2) return 0;
	ll a_f = first(0,a);
	ll b_f = first(0,b);
	if(b<a) swap(a,b);
	ll left = 0;
	ll total = 0;
	while(left < n){
		ll new_left = first(left,b);
		comboarr[total++] = pref_sum(left,new_left-1,a);
		left = new_left;
		swap(a,b);
	}
	if(total < 4) return 0;
	FOR(i,total) FOR(j,5) FOR(k,2) DP[i][j][k] = -1;
	// FOR(i,total) FOR(j,5) TRACE(i,j,DP[i][j]);
	return dp(comboarr,total,0,4,0)+dp(comboarr,total,0,4,1);
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n;
		FOR(i,n) cin>>arr[i];
		setup_locations();
		ll out = 0;
		FORIT(it_1, locations){
			auto it_2 = it_1;
			++it_2;
			out += combo((*it_1).first,(*it_1).first);
			for(;it_2!=locations.end();it_2++){
				out += combo((*it_1).first,(*it_2).first);
			}
		}
		cout<<out<<'\n';
	}
	return 0;
}