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
#define piiINF pii{INT_MAX/2,INT_MAX/2}
#define SIZE (int)1e5+5
pii swappii(pii loc) {
	return pii{loc.second,loc.first};
}

int n,m;
pii start, finish;
pii tele[SIZE];
int telexOx[SIZE];
int telexOy[SIZE];
int teleyOy[SIZE];
int teleyOx[SIZE];
set<pair<int,pii>> queue_;	
map<pii,int> distance_;

int dis_tele(pii a, pii b){
	return min(abs(a.first-b.first),abs(a.second-b.second));
}
int dis_normal(pii a, pii b){
	return abs(a.first-b.first)+abs(a.second-b.second);
}

void sort_tele(){
	sort(tele,tele+m);
	FOR(i,m){
		telexOx[i] = tele[i].first;
		telexOy[i] = tele[i].second;
	}
	FOR(i,m) tele[i] = swappii(tele[i]);
	sort(tele,tele+m);
	FOR(i,m){
		teleyOx[i] = tele[i].first;
		teleyOy[i] = tele[i].second;
	}
}

pii left(pii a){
	int i_f = lower_bound(telexOx,telexOx+m,a.first)-telexOx-1;
	if(i_f<0||i_f>=m) return piiINF;
	int i_b = lower_bound(telexOx,telexOx+m,telexOx[i_f])-telexOx;
	int j_ir = lower_bound(telexOy+i_b,telexOy+i_f+1,a.second)-telexOy;
	int j_l = j_ir - 1;
	pii one = piiINF;
	if(i_b<=j_ir<=i_f) one = {telexOx[i_b],telexOy[j_ir]};
	pii two = piiINF;
	if(i_b<=j_l<=i_f) two = {telexOx[i_b],telexOy[j_l]};
	pii out = piiINF;
	if(dis_tele(a,one)<dis_tele(a,out))out=one;
	if(dis_tele(a,two)<dis_tele(a,out))out=two;
	return out;
}
pii up(pii a){
	int i_f = lower_bound(teleyOy,teleyOy+m,a.second)-teleyOy-1;
	if(i_f<0||i_f>=m) return piiINF;
	int i_b = lower_bound(teleyOy,teleyOy+m,teleyOy[i_f])-teleyOy;
	int j_ir = lower_bound(teleyOx+i_b,teleyOx+i_f+1,a.first)-teleyOx;
	int j_l = j_ir - 1;
	pii one = piiINF;
	if(i_b<=j_ir<=i_f) one = {teleyOx[j_ir],teleyOy[i_b]};
	pii two = piiINF;
	if(i_b<=j_l<=i_f) two = {teleyOx[j_l],teleyOy[i_b]};
	pii out = piiINF;
	if(dis_tele(a,one)<dis_tele(a,out))out=one;
	if(dis_tele(a,two)<dis_tele(a,out))out=two;
	return out;
}
pii right(pii a){
	int i_b = upper_bound(telexOx,telexOx+m,a.first)-telexOx;
	if(i_b<0||i_b>=m) return piiINF;
	int i_f = upper_bound(telexOx,telexOx+m,telexOx[i_f])-telexOx-1;
	int j_ir = lower_bound(telexOy+i_b,telexOy+i_f+1,a.second)-telexOy;
	int j_l = j_ir - 1;
	pii one = piiINF;
	if(i_b<=j_ir<=i_f) one = {telexOx[i_b],telexOy[j_ir]};
	pii two = piiINF;
	if(i_b<=j_l<=i_f) two = {telexOx[i_b],telexOy[j_l]};
	pii out = piiINF;
	if(dis_tele(a,one)<dis_tele(a,out))out=one;
	if(dis_tele(a,two)<dis_tele(a,out))out=two;
	return out;
}
pii down(pii a){
	int i_b = upper_bound(teleyOy,teleyOy+m,a.first)-teleyOy;
	if(i_b<0||i_b>=m) return piiINF;
	int i_f = upper_bound(teleyOy,teleyOy+m,teleyOy[i_f])-teleyOy-1;
	int j_ir = lower_bound(teleyOx+i_b,teleyOx+i_f+1,a.first)-teleyOx;
	int j_l = j_ir - 1;
	pii one = piiINF;
	if(i_b<=j_ir<=i_f) one = {teleyOx[j_ir],teleyOy[i_b]};
	pii two = piiINF;
	if(i_b<=j_l<=i_f) two = {teleyOx[j_l],teleyOy[i_b]};
	pii out = piiINF;
	if(dis_tele(a,one)<dis_tele(a,out))out=one;
	if(dis_tele(a,two)<dis_tele(a,out))out=two;
	return out;
}

void improve(pii loc, pii ne, bool real){
	int new_dis = distance_[loc] + (real?dis_normal(loc,ne):dis_tele(loc,ne));
	if(new_dis<distance_[ne]){
		queue_.erase({distance_[ne],ne});
		distance_[ne] = new_dis;
		queue_.insert({distance_[ne],ne});
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	cin>>start.first>>start.second;
	cin>>finish.first>>finish.second;
	int x,y;
	FOR(i,m){
		cin>>x>>y;
		tele[i] = pii{x,y};
	}
	sort_tele();
	distance_[start] = 0;
	distance_[piiINF] = 0;
	FOR(i,m){
		distance_[tele[i]] = dis_tele(start,tele[i]);
		queue_.insert({distance_[tele[i]],tele[i]});
	}
	distance_[finish] = dis_normal(start,finish);
	queue_.insert({distance_[finish],finish});
	while(!queue_.empty()){
		int dis; pii loc;
		tie(dis,loc) = *queue_.begin();
		queue_.erase(queue_.begin());
		if(loc==finish) break;
		improve(loc,finish,true);
		improve(loc,up(loc),false);
		improve(loc,right(loc),false);
		improve(loc,down(loc),false);
		improve(loc,left(loc),false);
	}
	cout<<distance_[finish]<<'\n';

	return 0;
}