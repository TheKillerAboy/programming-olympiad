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
template<typename... Args> void TRACEV(tuple<Args...> t);
template<typename l, typename r> void TRACEV(pair<l,r> t);
template<typename T> void TRACEV(T t){TRACED(t);}
template<template<typename...> class T, typename... K> void TRACEV(T<K...> t);
template<typename T,typename... Args>void TRACEUT_(T t){TRACEV(t);}
template<typename T,typename... Args>void TRACEUT_(T t, Args... args){TRACEV(t); TRACED(", "); TRACEUT_(args...);}
template<typename T,typename... Args>void TRACEUT(T t, Args... args){TRACED('('); TRACEUT_(t,args...); TRACED(")");}
template<typename Tuple, size_t... Is>void TRACET_(Tuple t, index_sequence<Is...>){TRACEUT(get<Is>(t)...);}
template<typename Tuple>void TRACET(Tuple t){TRACET_(t,make_index_sequence<tuple_size<Tuple>::value>{});}
#define TRACEP(p_) TRACED("("); TRACEV(p_.first);TRACED(", ");TRACEV(p_.second);TRACED(")");
template<typename... Args> void TRACEV(tuple<Args...> t){TRACET(t);}
template<typename l, typename r> void TRACEV(pair<l,r> t){TRACEP(t);}
template<template<typename...> class T, typename... K> void TRACEV(T<K...> t){auto it = t.begin();
TRACED("[");TRACEV(*it);for(++it;it!=t.end();++it){TRACED(", ");TRACEV(*it);}TRACED("]");}
template<typename T> void TRACE(T t){TRACEV(t);_N;}
template<typename T,typename... Ts> void TRACE(T t,Ts... args){TRACEV(t); _T; TRACE(args...);}

#define ll long long int
#define ull unsigned long long int
#define pii pair<int,int>
#define INF INT_MAX

//TEMPLATE START

template<typename T, typename CMP>
struct SegTree{
	vector<T> ST;
	CMP cmp;
	int size__;
	T DEFAULT;
	int size(){
		return size__;
	}
	void fill(vector<T>& arr, int nl, int nr, int ni){
		if(nl<nr){
			int mid = (nl+nr)>>1;
			fill(arr,nl,mid,2*ni+1);
			fill(arr,mid+1,nr,2*ni+2);
			ST[ni] = cmp(ST[2*ni+1],ST[2*ni+2]);
		}	
		else if(nl==nr){
			ST[ni] = arr[nl];
		}
	}
	SegTree(vector<T>& arr, CMP cmp_, T default_ = 0){
		ST.resize((1<<((int)ceil(log2(arr.size()))+1))-1);
		cmp = cmp_;
		size__ = arr.size();
		DEFAULT = default_;
		fill(arr,0,size()-1,0);
	}
	T query__(int ql, int qr, int nl, int nr, int ni){
		if(ql<=nl && nr<= qr){
			return ST[ni];
		}
		else if(nr<ql || nl>qr){
			return DEFAULT;
		}
		else{
			int mid = (nl+nr)>>1;
			return cmp(query__(ql,qr,nl,mid,2*ni+1),query__(ql,qr,mid+1,nr,2*ni+2));
		}
	}
	T query(int l, int r){
		return query__(l,r,0,size()-1,0);
	}
	template <typename K>
	void updateRange__(int ql, int qr, int nl, int nr, int ni, K value){
		if(!(nr<ql || nl>qr)){
			if(nl==nr){
				ST[ni] = value;
			}
			else{
				int mid = (nl+nr)>>1;
				updateRange__(ql,qr,nl,mid,2*ni+1);
				updateRange__(ql,qr,mid+1,nr,2*ni+2);
				ST[ni] = cmp(ST[2*ni+1],ST[2*ni+2]);
			}
		}
	}
	template <typename K>
	void updateRangeFunc(int l, int r, K value){
		updateRange__(l,r,0,size()-1,0,value);
	}
	void updateRange(int l, int r, T value){
		updateRange__(l,r,0,size()-1,0,[&](T& A){return value;});
	}
	void updateSingle(int i, T value){
		updateRange(i,i,value);
	}
};

//TEMPLATE END


inline int cmp(int a, int b){
	return a>b?a:b;
}
int N;
int M;
vector<int> monsters;
vector<pii> heros;
map<int,int> duration;
vector<int> strength;
SegTree<int,decltype(&cmp)> monstersSeg(monsters,cmp);
SegTree<int,decltype(&cmp)> strenghtSeg(strength,cmp);

int isPos(int l, int left, int right){
	int mid = (left + right)>>1;
	if(mid == left){
		return left;
	}
	auto start = duration.lower_bound(mid-l+1);
	if(start != duration.end()){
		if(strenghtSeg.query((*start).second,M-1) >= monstersSeg.query(l,mid)){
			return isPos(l,mid,right);
		}
	}
	return isPos(l,left,mid);
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int Q;
	cin>>Q;
	FOR(i_,Q){
		cin>>N;
		monsters.resize(N+1);
		FOR(i,N) cin>>monsters[i];
		monstersSeg = SegTree<int,decltype(&cmp)>(monsters,cmp);
		cin>>M;
		int a,b;
		heros.resize(M);
		strength.resize(M);
		duration = map<int,int>();
		FOR(i,M){
			cin>>a>>b;
			heros[i] = {b,a};
		}
		sort(heros.begin(),heros.end());
		FOR(i,M){
			if(duration.find(heros[i].first) == duration.end()) duration[heros[i].first] = i;
			strength[i] = heros[i].second;
		}
		strenghtSeg = SegTree<int,decltype(&cmp)>(strength,cmp);
		int count = 0;
		int l = 0;
		while(l < N){
			int isp = isPos(l,l-1,N);
			if(isp == l-1){
				count = -1;
				break;
			}
			else{
				l = isp + 1;
				++count;
			}
		}
		cout<<count<<'\n';
	}
	return 0;
}