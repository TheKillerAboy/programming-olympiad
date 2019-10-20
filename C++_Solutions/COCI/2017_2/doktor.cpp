#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin>>N;
	int rotate;
	vector<int> seq(N);
	vector<int> bestRotate(N,0);
	vector<pair<int,int>> bound(N);
	for(int i = 0; i < N; ++i){
		bound[i] = {i,i};
	}
	for(int i = 0; i < N; ++i){
		cin>>seq[i];
		rotate = seq[i] - (i+1);
		if(rotate%2 == 0){
			++bestRotate[i+rotate/2];
			if(bound[i+rotate/2].first>i){
				bound[i+rotate/2].first = i;
			}
			else if(bound[i+rotate/2].second < i){
				bound[i+rotate/2].second = i;	
			}
		}
	}
	pair<int,int> MAX = {0,-1};
	for(int i = 0; i < N; ++i){
		MAX = max(MAX,{bestRotate[i],i});
	}
	int boundSize = max(abs(MAX.second-bound[MAX.second].first),abs(MAX.second-bound[MAX.second].second));
	if(MAX.second + boundSize > N-1){
		boundSize = N-1 - MAX.second;
	}
	if(MAX.second - boundSize < 0){
		boundSize = MAX.second;
	}
	cout<<seq[MAX.second-boundSize]<<' '<<seq[MAX.second+boundSize]<<endl;
	return 0;
}