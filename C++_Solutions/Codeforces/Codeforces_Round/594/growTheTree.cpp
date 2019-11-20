#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_ = 0; i_<a_;++i)
#define ll long long int

int main(){
	int N;
	cin>>N;
	vector<int> sticks(N);
	FOR(i,N){
		cin>>sticks[i];
	}
	sort(sticks.begin(),sticks.end(),greater<int>());
	ll bottom = 0;
	FOR(i,N-N/2){
		bottom+=sticks[i];
	}
	ll top = 0;
	for(int i = N-N/2; i < N; ++i){
		top+=sticks[i];
	}
	cout<<bottom*bottom + top*top<<'\n';
	return 0;
}