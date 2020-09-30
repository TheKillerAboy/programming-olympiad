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
template<typename T, size_t S> void TRACEV(array<T,S> t){TRACEV("[");TRACEV(t[0]);FOR1(i,S){TRACEV(",");TRACEV(t[i]);}TRACEV("]");}
template<typename T,typename... Args>void TRACEUT_(T t){TRACEV(t);}
template<typename T,typename... Args>void TRACEUT_(T t, Args... args){TRACEV(t); TRACED(","); TRACEUT_(args...);}
template<typename T,typename... Args>void TRACEUT(T t, Args... args){TRACED('('); TRACEUT_(t,args...); TRACED(")");}
template<typename Tuple, size_t... Is>void TRACET_(Tuple t, index_sequence<Is...>){TRACEUT(get<Is>(t)...);}
template<typename Tuple>void TRACET(Tuple t){TRACET_(t,make_index_sequence<tuple_size<Tuple>::value>{});}
#define TRACEP(p_) TRACED("("); TRACEV(p_.first);TRACED(",");TRACEV(p_.second);TRACED(")");
template<typename... Args> void TRACEV(tuple<Args...> t){TRACET(t);}
template<typename l, typename r> void TRACEV(pair<l,r> t){TRACEP(t);}
template<template<typename...> class T, typename... K> void TRACEV(T<K...> t){if(t.empty()){TRACEV("[]");return;}auto it = t.begin();
TRACED("[");TRACEV(*it);for(++it;it!=t.end();++it){TRACED(",");TRACEV(*it);}TRACED("]");}
template<typename T> void TRACEV(T* b, T* e){if(b==e){TRACEV("[]");return;}TRACED("[");TRACEV(*b);while(++b!=e){TRACED(",");TRACEV(*b);}TRACED("]");}
template<typename T> void TRACE(T t){TRACEV(t);TRACEV(",");}
template<typename T,typename... Ts> void TRACE(T t,Ts... args){TRACEV(t);TRACEV(","); TRACE(args...);}

#define ull unsigned long long ll
#define pii pair<ll,ll>
#define iii tuple<ll,ll,ll>

ll t,n,S;
ll v,u,w,c;
set<ll> children[(ll)1e5+5];
map<pii,ll> weights;
map<pii,ll> costs;
ll parent[(ll)1e5+5];
ll leaves[(ll)1e5+5];

void make_root(ll node){
	FORA(child,children[node]){
		children[child].erase(node);
		parent[child] = node;
		make_root(child);
	}
}

ll get_leaves(ll node){
	ll& out = leaves[node];
	FORA(child,children[node]){
		out+=get_leaves(child);
	}
	if(children[node].empty()) out = 1;
	return out;
}

ll get_weight(ll a, ll b){
	if(a>b) swap(a,b);
	return weights[pii{a,b}];
}

void set_weight(ll a, ll b, ll v){
	if(a>b) swap(a,b);
	weights[pii{a,b}] = v;
}

ll get_cost(ll a, ll b){
	if(a>b) swap(a,b);
	return costs[pii{a,b}];
}

void set_cost(ll a, ll b, ll v){
	if(a>b) swap(a,b);
	costs[pii{a,b}] = v;
}

ll get_sum(ll node, ll value){
	ll out = 0;
	FORA(child,children[node]){
		out += get_sum(child,value+get_weight(node,child));
	}
	if(children[node].empty()){
		out = value;
	}
	return out;
}

ll get_child(ll a, ll b){
	return parent[a]==b?a:b;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>t;
	FORI(oo,t){
		cin>>n>>S;
		weights.clear();
		costs.clear();
		FORI(i,n){
			parent[i] = -1;
			leaves[i] = 0;
			children[i].clear();
		}
		FOR(i,n-1){
			cin>>v>>u>>w>>c;
			children[v].insert(u);
			children[u].insert(v);
			set_weight(v,u,w);
			set_cost(v,u,c);
		}
		make_root(1);
		get_leaves(1);
		map<float,multiset<iii>,greater<ll>> prio_wei;
		FORA(edge, weights){
			tie(u,v) = edge.first;
			prio_wei[(float)leaves[get_child(u,v)]*(edge.second-edge.second/2)/get_cost(u,v)].insert(iii{get_cost(u,v),leaves[get_child(u,v)],edge.second});
		}
		ll value = get_sum(1,0);
		ll out = 0;
		ll cost,lvs,wei;
		int size__ = prio_wei.size();
		while(value > S){
			auto& start = *prio_wei.begin();
			multiset<iii>& info = start.second;
			tie(cost,lvs,wei) = *info.begin();
			info.erase(info.begin());
			if(info.empty()){prio_wei.erase(prio_wei.begin());}
			value -= lvs*(wei-wei/2);
			wei = wei/2;
			prio_wei[(float)lvs*(wei-wei/2)/cost].insert(iii{cost,lvs,wei});
			out+=cost;
		}
		cout<<out<<'\n';

	}
	return 0;
}