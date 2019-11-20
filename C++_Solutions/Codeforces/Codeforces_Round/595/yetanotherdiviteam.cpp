#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define FORA(e_,c_) for(auto e_:c_)

int Q,N,p;
vector<bool> teams;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>Q;
	FOR(i,Q){
		cin>>N;
		vector<int> people(N);
		FOR(j,N){
			cin>>p;
			people[j] = p;
		}
		sort(people.begin(),people.end());
		bool coll = false;
		FOR(i,N-1){
			if(people[i+1]-people[i] == 1){
				coll = true;
				break;
			}
		}
		if(coll){
			cout<<2<<'\n';
		}
		else if(N>0){
			cout<<1<<'\n';
		}
		else{
			cout<<0<<'\n';
		}
	}
	return 0;
}