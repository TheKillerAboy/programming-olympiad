#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORR(i_,a_) for(int i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define ll long long int

vector<vector<int>> weedFilled;
vector<vector<bool>> hasWeed;
int N,M;

inline int weedInRect(int i, int j, int is, int js){
	if(i == 0 && j == 0){
		return weedFilled[i+is-1][j+js-1];
	}
	else if(j == 0){
		return weedFilled[i+is-1][j+js-1] - weedFilled[i-1][j+js-1];
	}
	else if(i == 0){
		return weedFilled[i+is-1][j+js-1] - weedFilled[i+is-1][j-1];
	}
	else{
		return weedFilled[i+is-1][j+js-1] - weedFilled[i-1][j+js-1] - weedFilled[i+is-1][j-1] + weedFilled[i-1][j-1];
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>N>>M;
	hasWeed.resize(N,vector<bool>(M));
	weedFilled.resize(N,vector<int>(M));

	string line;
	FOR(i,N){
		cin>>line;
		FOR(j,M){
			hasWeed[i][j] = line[j] == '#';
		}
	}

	FOR(i,N){
		FOR(j,M){
			if(i == 0 && j == 0){
				weedFilled[i][j] = hasWeed[i][j];
			}
			else if(j == 0){
				weedFilled[i][j] = weedFilled[i-1][j] + hasWeed[i][j];
			}
			else if(i == 0){
				weedFilled[i][j] = weedFilled[i][j-1] + hasWeed[i][j];
			}
			else{
				weedFilled[i][j] = weedFilled[i][j-1] + weedFilled[i-1][j] - weedFilled[i-1][j-1] + hasWeed[i][j];
			}
		}
	}
	ll total = 0;
	FOR(i,N){
		FOR(j,M){
			FORI(is,N - i){
				FORI(js,M - j){
					if(weedInRect(i,j,is,js) == 0){
						total += is*js;
					}
					else{
						break;
					}
				}
			}
		}
	}
	cout<<total<<'\n';

	return 0;
}