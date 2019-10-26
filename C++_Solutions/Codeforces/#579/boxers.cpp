#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define FOR(i_,a_) for(ll i_=0;i_<a_;++i_)
#define FOR1(i_,a_) for(ll i_=1;i_<a_;++i_)
#define FORR(i_,a_) for(ll i_=a_-1;i_>=0;--i_)

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin>>N;
	vector<int> boxers(N);
	FOR(i,N){
		cin>>boxers[i];
	}
	sort(boxers.begin(),boxers.end());
	if(boxers[0] > 1){
		--boxers[0];
	}
	int prev = boxers[0];
	int count = 1;
	FOR1(i,N){
		if(boxers[i] == prev){
			++boxers[i];
			++count;
		}
		else if(boxers[i] > prev+1){
			--boxers[i];
			++count;
		}
		else if(boxers[i] > prev){
			++count;
		}
		else if(boxers[i] < prev){
			continue;
		}
		prev = boxers[i];
	}
	cout<<count<<'\n';

	return 0;
}