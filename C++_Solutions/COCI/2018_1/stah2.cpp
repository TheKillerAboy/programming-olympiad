#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORR(i_,a_) for(int i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define ll long long int

vector<vector<int>> breakR(2001,vector<int>(2001));
vector<vector<int>> breakC(2001,vector<int>(2001));
// vector<vector<vector<vector<ll>>>> DP(2001,vector<vector<vector<ll>>>(2001,vector<vector<ll>>(2001,vector<ll>(2001))));
vector<vector<bool>> hasWeed(2001,vector<bool>(2001));
int N,M;

inline int nextBreakR(int i, int j){
	// printf("R %i %i %i\n",i,j,breakR[i][j]);
	return breakR[i][j];
}

inline int nextBreakC(int i, int j){
	// printf("C %i %i %i\n",i,j,breakC[i][j]);
	return breakC[i][j];
}

ll dp(int i, int j, int is, int js);

ll getdp(int i, int j, int is, int js){
	// if(DP[i][j][is][js] == -1){
	// 	DP[i][j][is][js] = dp(i,j,is,js);
	// }
	ll k = dp(i,j,is,js);

	// printf("%i %i %i %i %lld\n",i,j,is,js,k );
	return k;
}

ll dp(int i, int j, int is, int js){
	if(js <= 0 || is <= 0){
		return 0;
	}
	int cis = nextBreakR(i,j) - i;
	int cjs = nextBreakC(i,j) - j;
	if(js == 1){
		return min(cis,is);
	}
	else if(is == 1){
		return min(cjs,js);
	}
	if(is > cis || js > cjs){
		return getdp(i,j,min(is,cis),min(js,cjs));
	}
	if(is < cis && js < cjs){
		return getdp(i,j,cis,cjs) - getdp(i+is+1,j+js+1,cis-is,cjs-js);
	}
	else if(is < cis){
		return getdp(i,j,cis,js) - getdp(i+is+1,j,cis-is,js);
	}
	else if(js < cjs){
		return getdp(i,j,is,cjs) - getdp(i,j+js+1,is,cjs-js);
	}
	else{
		return getdp(i+1,j,is-1,js) + getdp(i,j+1,is,js-1) - getdp(i+1,j+1,is-1,js-1) + 1;
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>N>>M;
	string line;
	FOR(i,N){
		cin>>line;
		FOR(j,M){
			hasWeed[i][j] = line[j] == '#';
		}
	}
	FOR(i,N){
		breakR[i][M] = M;
	}
	FOR(j,M){
		breakC[N][j] = N;
	}
	FORR(i,N){
		FORR(j,M){
			if(hasWeed[i][j]){
				breakR[i][j] = j;
				breakC[i][j] = i;
			}
			else{
				breakC[i][j] = breakC[i+1][j];
				breakR[i][j] = breakR[i][j+1];
			}
		}
	}
	ll sum = 0;
	FOR(i,N){
		FOR(j,M){
			printf("%i %i %lld\n", i,j,getdp(i,j,N,M));
			sum+=getdp(i,j,N,M);
		}
	}
	cout<<sum<<'\n';

	return 0;
}