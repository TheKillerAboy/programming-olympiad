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

#define ll long long int
#define ull unsigned long long int

#define INF INT_MAX/1000

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int Q;
	cin>>Q;
	int N,k;
	string line;
	FOR(i,Q){	
		cin>>N>>k;
		cin>>line;
		set<pair<int,int>> queue;
		int count = 0;
		FOR(j,N){
			if(line[j] == '0' && count > 0){
				queue.insert({j-1,count});
				count = 0;
			}
			else{
				++count;
			}
		}
		if(line[N-1] == '1') queue.insert({N-1,count});
		int fC,fI,sC,sI;
		while(k > 0){
			tie(fI,fC) = *queue.begin();
			queue.erase(queue.begin());
			if(queue.size() > 0){
			tie(sI,sC) = *queue.begin();
			}
			else{
				if(fI != N-1){
					sI = N-1, sC = 0;
				}
				else{
					queue.insert({fI,fC});
					break;
				}
			}
			int dis = sI - sC- fI;
			if(dis*fC <= k){
				if(queue.size() > 0){
					queue.erase(queue.begin());
				}
				queue.insert({sI,fC+sC});
				k -= dis*fC;
			}
			else{
				int D1 = k%fC;
				int DIS = k/fC;
				queue.insert({fI + DIS - D1,fC-D1});
				queue.insert({fI+DIS+1,D1});
				k = 0;
			}
		}
		int ind = 0;
		while(ind<N){
			// TRACE(((*queue.begin()).first - (*queue.begin()).second + 1))
			if(queue.empty() || ind != (*queue.begin()).first - (*queue.begin()).second + 1){
				cout<<0;
				ind++;
			}
			else{
				ind = (*queue.begin()).first + 1;
				FOR(j,(*queue.begin()).second) cout<<1;
				queue.erase(queue.begin());
			}
		}
		cout<<'\n';
	}


	return 0;
}