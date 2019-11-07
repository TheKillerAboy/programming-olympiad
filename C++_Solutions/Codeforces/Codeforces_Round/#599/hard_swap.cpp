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

inline int adj(int a){return (a+1)%2;}

int main(){
	// cin.tie(0);
	// ios::sync_with_stdio(false);
	int Q;
	cin>>Q;
	int N;
	string S,T;
	FOR(_i,Q){
		cin>>N>>S>>T;
		vector<int> cnt(26,0);
		map<char,array<set<int>,2>> chars; 
		set<int> wrong;
		FOR(i,N){
			if(S[i] != T[i]){
				++cnt[S[i]-'a'];
				++cnt[T[i]-'a'];
				chars[S[i]][0].insert(i);
				chars[T[i]][1].insert(i);
				wrong.insert(i);
			}
		}
		bool isPos = true;
		FOR(i,26){
			if(cnt[i]%2 == 1){
				isPos = false;
				break;
			}
		}
		if(isPos){
			vector<pair<int,int>> queue;
			while(!wrong.empty()){
				int i = *wrong.begin();
				wrong.erase(wrong.begin());
				if(S[i] != T[i]){
					chars[S[i]][0].erase(chars[S[i]][0].begin());
					if(chars[S[i]][0].empty()){
						if(wrong.empty()) {cout<<"NO\n";return 0;}
						int nextWrong = *wrong.begin();
						int index = *chars[S[i]][1].begin();
						chars[S[i]][1].erase(chars[S[i]][1].begin());
						chars[T[i]][1].erase(chars[T[i]][1].begin());
						chars[S[nextWrong]][0].erase(chars[S[nextWrong]][0].begin());
						queue.push_back({nextWrong+1,index+1});
						T[index] = S[nextWrong];
						S[nextWrong] = T[i];
						queue.push_back({nextWrong+1,i+1});
						chars[T[index]][1].insert(index);
						chars[S[nextWrong]][0].insert(nextWrong);
					}
					else{
						int index = *chars[S[i]][0].begin();
						chars[S[i]][0].erase(chars[S[i]][0].begin());
						queue.push_back({index+1,i+1});
						chars[T[i]][1].erase(chars[T[i]][1].begin());
						chars[T[i]][0].insert(index);
						S[index] = T[i];
					}
				}
				else{
					if(chars[S[i]][0].find(i) != chars[S[i]][0].end())
					chars[S[i]][0].erase(chars[S[i]][0].find(i));
					if(chars[T[i]][1].find(i) != chars[T[i]][1].end())
					chars[T[i]][1].erase(chars[T[i]][1].find(i));
				}
			}
			cout<<"YES\n";
			cout<<queue.size()<<'\n';
			FORA(ele,queue){
				cout<<ele.first<<' '<<ele.second<<'\n';
			}
		}
		else{
			cout<<"NO\n";
		}
	}


	return 0;
}