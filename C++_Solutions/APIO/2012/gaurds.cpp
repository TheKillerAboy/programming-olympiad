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
template<typename T,typename... Args>void TRACEU(T t, Args... args){TRACEV(t) TRACEV(", ") TRACEU(args...);}
template<typename T,typename... Args>void TRACEUT_(T t){TRACEV(t)}
template<typename T,typename... Args>void TRACEUT_(T t, Args... args){TRACEV(t) TRACEV(", ") TRACEUT_(args...);}
template<typename T,typename... Args>void TRACEUT(T t, Args... args){TRACEV('(') TRACEUT_(t,args...); TRACE(")");}
template<typename Tuple, size_t... Is>void RACET_(Tuple t, index_sequence<Is...>){TRACEUT(get<Is>(t)...);}
template<size_t N, typename Tuple>void TRACET(Tuple t){TRACET_(t,make_index_sequence<N>{});}

#define ll long long int
#define ull unsigned long long int
#define pii pair<int,int>

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	multiset<tuple<int,bool,bool>> queue; //pos, isThere, isEnd
	int N,M,K;
	cin>>N>>K>>M;
	int a,b,c;
	FOR(i,M){
		cin>>a>>b>>c;
		queue.insert({a,c==1,0});
		queue.insert({b,c==1,1});
	}
	int cntThere =0,cntNotThere = 0;
	int currentPos;
	bool isThere,isEnd;
	bool hasNotThere = false;
	int firstStart = -1;

	while(!queue.empty()){
		currentPos = get<0>(*queue.begin());
		hasNotThere = false;
		while(get<0>(*queue.begin()) == currentPos){
			tie(currentPos,isThere,isEnd) = *queue.begin();
			queue.erase(queue.begin());
			if(isThere) cntThere += (isEnd?-1:1);
			else cntNotThere += (isEnd?-1:1);

			if(isEnd && !isThere) hasNotThere = true;
			if(firstStart == -1 && isThere) firstStart = currentPos;
			else if(cntThere == 0) firstStart = -1;
		}
		TRACEU(currentPos,hasNotThere,cntNotThere,cntThere,firstStart);
	}


	return 0;
}