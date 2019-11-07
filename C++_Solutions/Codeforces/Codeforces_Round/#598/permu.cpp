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
#define pii pair<int,int>

inline void swap(int& a, int& b){a^=b^=a^=b;}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int Q,N;
	vector<int> permu;
	vector<int> pos;	
	cin>>Q;
	FOR(_i,Q){
		cin>>N;
		permu.resize(N);
		vector<bool> used(N-1,false);
		pos.resize(N);
		FOR(i,N){
			cin>>permu[i];
			--permu[i];
			pos[permu[i]] = i;
		}
		// FOR(i,N){
		// 	while(pos[i] > i && !used[pos[i]-1]){
		// 		used[pos[i]-1] = true;
		// 		int curPos = pos[i];
		// 		swap(permu[curPos],permu[curPos-1]);
		// 		pos[permu[curPos]] = curPos;
		// 		pos[permu[curPos-1]] = curPos - 1;
		// 	}
		// }
		FOR(i,N-1){
			if(!used[i]){
				pii MIN = {permu[i],i};
				FORS(i,j,N-1){
					if(used[j]) break;
					else{
						MIN = min(MIN,{permu[j+1],j+1});
					}
				}
				if(MIN == pii{permu[i],i}) continue;
				else{
					for(int j=MIN.second;j>i;--j){
						used[j-1] = true;
						swap(permu[j],permu[j-1]);
						pos[permu[j]] = j;
						pos[permu[j-1]] = j - 1;
					}
				}
			}
		}
		FOR(i,N){
			cout<<permu[i]+1<<' ';
		}
		cout<<'\n';
	}

	return 0;
}