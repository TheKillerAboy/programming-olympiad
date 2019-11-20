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
#define TRACEV(v_) cerr<<v_;
#define TRACEP(p_) cerr<<"("<<p_.first<<", "<<p_.second<<") ";
#define TRACECE(c_,tt_) for(auto e_:c_){tt_(e_);_;}_N;
#define TRACEC(c_) TRACECE(c_,TRACEV)
#define TRACEE(v_,tt_) tt_(v_);_N;
#define TRACE(v_) TRACEE(v_,TRACEV);
#define TRACEEP(v_) TRACEE(v_,TRACEP);
template<typename T>void TRACEU(T t) {TRACE(t)}
template<typename T,typename... Args>void TRACEU(T t, Args... args){TRACEV(t) _ TRACEU(args...);}
template<typename T,typename... Args>void TRACEUT_(T t){TRACEV(t)}
template<typename T,typename... Args>void TRACEUT_(T t, Args... args){TRACEV(t) TRACEV(", ") TRACEUT_(args...);}
template<typename T,typename... Args>void TRACEUT(T t, Args... args){TRACEV('(') TRACEUT_(t,args...); TRACE(")");}
template<typename Tuple, size_t... Is> void TRACET_(Tuple t, index_sequence<Is...>){TRACEUT(get<Is>(t)...);}
template<size_t N, typename Tuple>void TRACET(Tuple t){TRACET_(t,make_index_sequence<N>{});}

#define ll long long int
#define ull unsigned long long int
#define pii pair<int,int>
#define INF INT_MAX

#define minmaxP(a,b) pii{min(a,b),max(a,b)}

vector<int> groups;
vector<int> groupSizes;
set<int> heads;

int uFind(int a){
	int current = a;
	while(groups[current] != -1){
		current = groups[current];
	}
	if(current != a){
		groups[a] = current;
	}
	return current;
}

void uMerge(int a, int b){
	int aP = uFind(a), bP = uFind(b);
	if(aP != bP){
		if(groupSizes[bP] > groupSizes[aP]) aP^=bP^=aP^=bP;
		heads.erase(heads.find(bP));
		groups[bP] = aP;
		groupSizes[aP] += groupSizes[bP];
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N,M;
	cin>>N>>M;
	groups.resize(N,-1);
	groupSizes.resize(N,1);
	map<int,set<int>> weights;
	int a,b;
	FOR(i,N) heads.insert(i);
	FOR(i,N) weights[i].insert(INF);
	FOR(i,M){
		cin>>a>>b;
		--a;--b;
		weights[a].insert(b);
		weights[b].insert(a);
	}
	FORA(ele,weights){
		int current = ele.first-1;
		bool breakK = false;
		FORA(val,ele.second){
			while(current < val && current < N){
				if(uFind(current) != uFind(ele.first)){
					uMerge(current,ele.first);
					breakK = true;
					break;
				}
				++current;
			}
			if(breakK) break;
			++current;
			if(current >= N) break;
		}

	}
	cout<<heads.size()-1<<'\n';

	return 0;
}