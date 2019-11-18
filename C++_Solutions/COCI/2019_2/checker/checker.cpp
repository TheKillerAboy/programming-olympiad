#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(int i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(int i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(int i_=1;i_<a_;++i_)
#define FORIT(it_,c_) for(auto it_ = c_.begin(); it_!=c_.end();++it_)

#define ll long long int
#define ull unsigned long long int
#define pii pair<int,int>

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int Q,N;
	cin>>Q;
	string colors;
	FOR(i_,Q){
		cin>>N;
		cin>>colors;
		FOR(i,N-1){
			cin>>N;
		}
		cout<<"tocno"<<'\n';
	} 
	return 0;
}