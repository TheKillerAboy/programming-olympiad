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
int R,C,K;
inline pii posToCoor(int i){
	int r = i/C , c = i%C;
	if(r%2==0) return {r,c};
	else return {r,C-1-c};
}

void nextChar(char& cur){
	if(cur == 'z') cur = 'A';
	else if(cur == 'Z') cur = '0';
	else ++cur;
}
void prevChar(char& cur){
	if(cur == 'A') cur = 'z';
	else if(cur == '0') cur = 'Z';
	else --cur;
}

int main(){
	// cin.tie(0);
	// ios::sync_with_stdio(false);
	int Q;
	cin>>Q;
	vector<string> field;
	vector<vector<char>> output;
	FOR(i_,Q){
		cin>>R>>C>>K;
		field.resize(R);
		output = vector<vector<char>>(R,vector<char>(C));
		FOR(i,R) cin>>field[i];
		int countRise = 0;
		FOR(r,R) FOR(c,C) if(field[r][c] == 'R') ++countRise;
		int upper = countRise%K;
		int current = 0;
		int r,c;
		char curChar = 'a';
		int curInd = 0;
		FOR(i,R*C){
			tie(r,c) = posToCoor(i);
			if(curInd == K) {prevChar(curChar);--curInd;}
			if(field[r][c] == 'R') ++current;
			output[r][c] = curChar;
			if(upper > 0){
				if(current == countRise/K + 1){
					current = 0;
					nextChar(curChar);
					++curInd;
					--upper;
				}
			}
			else if(current == countRise/K){
				current = 0;
				nextChar(curChar);
				++curInd;
			}
		}
		FOR(r,R){
			FOR(c,C){
				cout<<output[r][c];
			}
			cout<<'\n';
		}
	}
	return 0;
}