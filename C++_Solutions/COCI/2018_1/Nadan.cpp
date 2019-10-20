#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int K,N;
	cin>>K>>N;
	FOR(i,N-1){
		cout<<i+1<<'\n';
		K-=i+1;
	}
	cout<<K;
	return 0;
}