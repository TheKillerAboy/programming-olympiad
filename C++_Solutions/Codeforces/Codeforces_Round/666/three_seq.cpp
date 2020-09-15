#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(int i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(int i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(int i_=1;i_<a_;++i_)
#define FORIT(it_,c_) for(auto it_ = c_.begin(); it_!=c_.end();++it_)

#define _ cerr<<' ';
#define _N cerr<<'\n';
#define _T cerr<<'\t';
#define TRACED(_v) cerr<<_v;
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
#define INF 1e17;

int n, q;
ll l,r,x;
ll arr[(int)1e5+5];
ll lazytree[(int)1e6];

void setup(int nl, int nr, int ni){
	if(nl < nr){
		int mid = (nl+nr)>>1;
		setup(nl, mid, 2*ni+1);
		setup(mid+1, nr, 2*ni+2);
		lazytree[ni] = 0;
	}
	else if(nl == nr){
		lazytree[ni] = arr[nl];
	}
}

void update_range(ll value, int ql, int qr, int nl, int nr, int ni){
	if(ql<=nl && nr<=qr){
		lazytree[ni] += value;
	}
	else if(nr < ql || qr < nl){;}
	else{
		int mid = (nl+nr)>>1;
		update_range(value,ql,qr,nl, mid, 2*ni+1);
		update_range(value,ql,qr,mid+1, nr, 2*ni+2);
	}
}

ll get_value(int qi, int nl, int nr, int ni){
	if(nl==qi && nr==qi){
		return lazytree[ni];
	}
	else if(nr < qi || qi < nl){;}
	else{
		int mid = (nl+nr)>>1;
		lazytree[2*ni+1]+=lazytree[ni];
		lazytree[2*ni+2]+=lazytree[ni];
		lazytree[ni] = 0;
		return min(get_value(qi,nl, mid, 2*ni+1), get_value(qi,mid+1, nr, 2*ni+2));
	}
	return INF;
}

ll devide2ceil(ll a){
	if(a>=0){
		return a/2 + a%2;
	}
	else{
		return a/2;
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin>>n;
	FOR(i,n){cin>>arr[i];}
	cin>>q;
	setup(0,n-1,0);
	ll delta_b = 0;
	FOR(i,n-1){
		if(arr[i+1] > arr[i]){
			delta_b += arr[i+1] - arr[i];
		}
	}
	cout<<devide2ceil(delta_b+arr[0])<<'\n';
	while(q--){
		cin>>l>>r>>x;
		l--;r--;
		bool left = false, right = false;
		if(l>0 && get_value(l,0,n-1,0) > get_value(l-1,0,n-1,0)){left=true;}
		if(r<n-1 && get_value(r+1,0,n-1,0) > get_value(r,0,n-1,0)){right=true;}
		update_range(x,l,r,0,n-1,0);
		if(l>0){
			if(left){
				if(get_value(l,0,n-1,0) > get_value(l-1,0,n-1,0)){
					delta_b += x;
				}
				else{
					delta_b -= get_value(l,0,n-1,0) - get_value(l-1,0,n-1,0) - x;
				}
			}
			else{
				if(get_value(l,0,n-1,0) > get_value(l-1,0,n-1,0)){
					delta_b += get_value(l,0,n-1,0) - get_value(l-1,0,n-1,0);
				}
			}
		}
		if(r<n-1){
			if(right){
				if(get_value(r+1,0,n-1,0) > get_value(r,0,n-1,0)){
					delta_b -= x;
				}
				else{
					delta_b -= get_value(r+1,0,n-1,0) - get_value(r,0,n-1,0) + x;
				}
			}
			else{
				if(get_value(r+1,0,n-1,0) > get_value(r,0,n-1,0)){
					delta_b += get_value(r+1,0,n-1,0) - get_value(r,0,n-1,0);
				}
			}
		}
		cout<<devide2ceil(delta_b+get_value(0,0,n-1,0))<<'\n';
	}
	return 0;
}