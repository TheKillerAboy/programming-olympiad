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
int Q;
int N;
int p,c;
vector<set<int>> children;
vector<int> parents;
vector<int> totalChildren;

void makeParent(int node){
	FORA(child, children[node]){
		children[child].erase(node);
		parents[child] = node;
		makeParent(child);
	}
}

int countChildren(int node){
	int out = 1;
	FORA(child, children[node]){
		out += countChildren(child);
	}
	totalChildren[node] = out;
	return out;
}

int maxTreeIfRemove(int node){
	int maxV = 0;
	FORA(child, children[node]){
		maxV = max(maxV, totalChildren[child]);
	}
	if(parents[node] != -1){
		maxV = max(maxV, N - totalChildren[node]);
	}
	return maxV;
}

bool connected(int a, int b){
	bool out = false;
	FORA(child, children[a]){
		if(child == b){ return true;}
		if(connected(child,b)){
			out = true;
		}
	}
	return out;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>Q;
	while(Q--){
		cin>>N;
		children.resize(N+1);
		parents.resize(N+1);
		totalChildren.resize(N+1);
		FOR(i,N+1){
			children[i].clear();
			parents[i] = -1;
			totalChildren[i] = 0;
		}
		FOR(i,N-1){
			cin>>p>>c;
			children[p].insert(c);
			children[c].insert(p);
		}
		makeParent(1);
		countChildren(1);
		list<int> cents;
		int minV = INT_MAX;
		FORI(i,N){
			int val = maxTreeIfRemove(i);
			if(val < minV){
				minV = val;
				cents.clear();
				cents.push_back(i);
			}
			else if(val == minV){
				cents.push_back(i);
			}
		}
		if(cents.size() > 1){
			int arr[2];
			int j = 0;
			FORA(v,cents){if(j==2){break;}arr[j++]=v;}
			if(connected(arr[0],arr[1])){
				swap(arr[0],arr[1]);
			}
			int childV;
			FORA(child, children[arr[0]]){
				if(!connected(child, arr[1])){
					childV = child;
					break;
				}
			}
			cout<<arr[0]<<' '<<childV<<'\n';
			cout<<arr[1]<<' '<<childV<<'\n';
		}
		else{
			int cent = *cents.begin();
			int child = *children[cent].begin();
			cout<<cent<<' '<<child<<'\n';
			cout<<cent<<' '<<child<<'\n';
		}
	}
	return 0;
}