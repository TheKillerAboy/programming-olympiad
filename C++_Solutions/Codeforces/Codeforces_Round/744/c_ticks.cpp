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

int t,n,m,k;
bool board[20][20];
bool checked[20][20];

bool in_bound(int i, int j){
	return i<n && j<m;
}

int max_right_spread(int s){
	FOR(i,30){
		if(!in_bound(i,s+i)) return i-1;
		if(!board[i][s+i]) return i-1;
	}
	return -1;
}

bool is_check(int s, int r){
	FOR(i,r+1){
		if(!in_bound(i,s+i) || !in_bound(i,s+2*r-i)) return false;
		if(!board[i][s+i] || !board[i][s+2*r-i]) return false;
	}
	return true;
}

void check(int s, int r){
	FOR(i,r+1){
		checked[i][s+i] = true;
		checked[i][s+2*r-i] = true;
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		string s;
		FOR(i,n){
			cin>>s;
			FOR(j,m){
				board[i][j] = s[j]=='*';
			}
		}
		FOR(i,20)FOR(j,20) checked[i][j]=false;
		int min_r = 99;
		FOR(j, m){
			if(board[0][j] && !checked[0][j]){
				int r = max_right_spread(j);
				min_r = min(min_r,r);
				if(is_check(j,r)) check(j,r);
			}
		}
		bool pos = min_r>=k;
		FOR(i,n)FOR(j,m) pos = pos&(checked[i][j]==board[i][j]);
		cout<< (pos?"YES\n":"NO\n");
	}

	return 0;
}