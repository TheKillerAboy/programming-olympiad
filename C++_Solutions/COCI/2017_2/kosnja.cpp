#include <bits/stdc++.h>

using namespace std;

int turns(int N, int M){
	int out = 0;
	while(M > 1){
		++out;
		M^=N^=M^=N;
		--N;
	}
	return out;
}

int main(){
	int Q;
	cin>>Q;
	int N,M;
	for(int i = 0; i < Q; ++i){
		cin>>N>>M;
		cout<<min(turns(N,M),turns(M,N))<<endl;
	}
	return 0;
}