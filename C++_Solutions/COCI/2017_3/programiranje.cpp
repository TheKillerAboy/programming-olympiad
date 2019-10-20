#include <bits/stdc++.h>

using namespace std;

#define FOR1(_i,_a) for(int _i = 1; _i<_a; ++_i)
#define FOR(_i,_a) for(int _i = 0; _i<_a; ++_i)

vector<vector<int>> prefixSum;

vector<int> queryGet(int a, int b){
	if(a > 0){
		vector<int> out = prefixSum[b];
		FOR(i,26){
			out[i]-=prefixSum[a-1][i];
		}
		return out;
	}
	return prefixSum[b];
}

int main(){
	string S;
	cin>>S;
	prefixSum.resize(S.size(), vector<int>(26,0));
	++prefixSum[0][S[0]-'a'];
	FOR1(i,S.size()){
		prefixSum[i] = prefixSum[i-1];
		++prefixSum[i][S[i]-'a'];
	}
	int Q;
	cin>>Q;
	int A,B,C,D;
	FOR(i,Q){
		cin>>A>>B>>C>>D;
		if(queryGet(A-1,B-1) == queryGet(C-1,D-1)){
			cout<<"DA\n";
		}
		else{
			cout<<"NE\n";
		}
	}
	return 0;
}