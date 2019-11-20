#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int h,n;
vector<ll> heights;

int query(){
	int out = 0;
	for(int i = 1; i < n; ++i){
		if(heights[i-1] - 1  > heights[i]){
			cout<<heights[i-1]<<' '<<heights[i]<<'\n';
			++out;
		}
	}
	return out;
}


int main(){
	int q;
	cin>>q;
	for(int i = 0; i < q; ++i){
		cin>>h>>n;
		heights.resize(n);
		for(int j = 0; j < n; ++j){
			cin>>heights[j];
		}
		cout<<query()<<'\n';
	}

	return 0;
}