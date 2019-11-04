#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(ll i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(ll i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(ll i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(ll i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(ll i_=1;i_<a_;++i_)
#define FORIT(it_,c_) for(auto it_ = c_.begin(); it_!=c_.end();++it_)

#define _ cerr<<' ';
#define _N cerr<<'\n';
#define _T cerr<<'\t';
#define TRACEV(v_) cerr<<v_;
#define TRACEP(p_) cerr<<"("<<p_.first<<", "<<p_.second<<") ";
#define TRACECE(c_,tt_) for(auto e_:c_){tt_(e_);_;}_N;
#define TRACEC(c_) TRACECE(c_,TRACEV)
#define TRACEE(v_,tt_) tt_(v_);_N;
#define TRACE(v_) TRACEE(v_,TRACEV);
#define TRACEEP(v_) TRACEE(v_,TRACEP);

#define ll long long int
#define ull unsigned long long int
#define INF LLONG_MAX

typedef pair<ll,ll> pii;

ll N;
vector<ll> k;
vector<pii> loc;
vector<ll> c;
vector<vector<ll>> weights;

inline ll man_dis(pii a, pii b){
	return abs(a.first-b.first)+abs(b.second-a.second);
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>N;
	k.resize(N);
	loc.resize(N);
	c.resize(N);
	weights.resize(N+1,vector<ll>(N+1));
	ll x,y;
	FOR(i,N){
		cin>>x>>y;
		loc[i] = {x,y};
	}
	FOR(i,N) cin>>c[i];
	FOR(i,N) cin>>k[i];
	FOR(i,N){
		FOR(j,N){
			weights[i][j] = man_dis(loc[i],loc[j]) * (k[i] + k[j]);
			weights[j][i] = weights[i][j];
		}
	}
	FOR(i,N){
		weights[i][N] = c[i];
		weights[N][i] = c[i];
	}
	set<pii> queue;
	queue.insert({0,0});
	vector<bool> found(N+1,false);
	vector<ll> distance(N+1,INF);
	vector<ll> parent(N+1,-1);
	distance[0] = 0;
	ll total = 0;
	while(!queue.empty()){
		pii current = *queue.begin();
		queue.erase(queue.begin());
		found[current.second] = true;
		total += current.first;
		FOR(i,N+1){
			if(!found[i]){
				if(weights[i][current.second] < distance[i]){
					if(distance[i] != INF){
						queue.erase(queue.find({distance[i],i}));
					}
					queue.insert({weights[i][current.second],i});
					distance[i] = weights[i][current.second];
					parent[i] = current.second;
				}
			}
		}
	}
	cout<<total<<'\n';
	ll count = 1;
	FOR1(i,N){
		if(parent[i] == N) ++count;
	}
	cout<<count<<'\n';
	cout<<parent[N]+1<<' ';
	FOR1(i,N){
		if(parent[i] == N) cout<<i+1<<' ';
	}
	cout<<'\n';
	count = 0;
	FOR1(i,N){
		if(parent[i] != N) ++count;
	}
	cout<<count<<'\n';
	FOR1(i,N){
		if(parent[i] != N) cout<<i+1<<' '<<parent[i]+1<<'\n';
	}
	return 0;
}