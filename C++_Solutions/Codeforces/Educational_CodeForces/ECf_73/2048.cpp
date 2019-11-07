#include <bits/stdc++.h>

using namespace std;

#define FOR(ii,aa) for(int ii = 0; ii < aa; ++ii)
#define FORI(ii,aa) for(int ii = 1; ii <= aa; ++ii)
#define ull unsigned long long int

vector<vector<bool>> possible;
vector<ull> arr;

int main(){
	int Q;
	cin>>Q;
	int N;
	FOR(i,Q){
		cin>>N;
		possible.clear();
		possible.resize(N+1,vector<bool>(2049,false));
		arr.resize(N);
		FOR(j,N){
			cin>>arr[j];
		}
		FOR(j,N+1){
			possible[j][0] = true;
		}
		FORI(j,N){
			FOR(k,2049){
				possible[j][k] = possible[j-1][k];
				if(arr[j-1] <= k){
					possible[j][k] = possible[j][k] | possible[j-1][k-arr[j-1]];
				}
			}
		}
		cout<<(possible[N][2048]?"YES":"NO")<<'\n';
	}
	return 0;
}