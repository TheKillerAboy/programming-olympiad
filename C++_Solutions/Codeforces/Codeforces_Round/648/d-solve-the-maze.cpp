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

char maze[50][50];
bool maze_get[50][50];
int t,n,m;
pii good;

void replace_wall(int i, int j){
	if(0<=i&&i<n&&0<=j&&j<m){
		if(maze[i][j]=='.'){
			maze[i][j] = '#';
		}
	}
}

void fill_walls(){
	FOR(i,n){
		FOR(j,m){
			if(maze[i][j]=='B'){
				replace_wall(i-1,j);
				replace_wall(i+1,j);
				replace_wall(i,j-1);
				replace_wall(i,j+1);
			}
		}
	}
}

void fill_from(int i, int j){
	if(0<=i&&i<n&&0<=j&&j<m){
		if(maze[i][j]!='#'&&!maze_get[i][j]){
			maze_get[i][j] = true;
			fill_from(i-1,j);
			fill_from(i+1,j);
			fill_from(i,j-1);
			fill_from(i,j+1);
		}
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n>>m;
		good = {-1,-1};
		FOR(i,n) FOR(j,m) {
			cin>>maze[i][j];
			if(maze[i][j]=='G') good = {i,j};
		}
		if(good == pii{-1,-1}){
			cout<<"YES"<<'\n';
			continue;
		}
		fill_walls();
		FOR(i,n)FOR(j,m) maze_get[i][j]=false;
		fill_from(good.first,good.second);
		bool pos = maze_get[n-1][m-1];
		FOR(i,n)FOR(j,m)if((maze[i][j]=='B'&&maze_get[i][j])||(maze[i][j]=='G'&&!maze_get[i][j])) pos = false;
		cout<<(pos?"YES":"NO")<<'\n';
	}

	return 0;
}