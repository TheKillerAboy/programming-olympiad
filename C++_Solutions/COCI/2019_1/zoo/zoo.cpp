#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORR(i_,a_) for(int i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(int i_=1;i_<a_;++i_)
#define ll long long int
#define ull unsigned long long int
vector<vector<bool>> partitioned;
vector<string> animal;
int R,C;

inline bool valid(int i, int j){
	return !(i<0 || j < 0 || i>=R || j>=C);
}

void partition(int i, int j){
	partitioned[i][j] = true;
	if(valid(i+1,j) && animal[i+1][j] == animal[i][j] && !partitioned[i+1][j]){
		partition(i+1,j);
	}
	if(valid(i-1,j) && animal[i-1][j] == animal[i][j] && !partitioned[i-1][j]){
		partition(i-1,j);
	}
	if(valid(i,j+1) && animal[i][j+1] == animal[i][j] && !partitioned[i][j+1]){
		partition(i,j+1);
	}
	if(valid(i,j-1) && animal[i][j-1] == animal[i][j] && !partitioned[i][j-1]){
		partition(i,j-1);
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>R>>C;
	partitioned.resize(R,vector<bool>(C,false));
	animal.resize(R);
	FOR(i,R){
		cin>>animal[i];
	}
	int count = 0;
	FOR(i,R){
		FOR(j,C){
			if(!partitioned[i][j] && animal[i][j] != '*'){
				partition(i,j);
				++count;
			}
		}
	}
	cout<<count<<'\n';

	return 0;
}