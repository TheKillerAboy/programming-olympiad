#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(int i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(int i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(int i_=1;i_<a_;++i_)
#define ll long long int
#define ull unsigned long long int

vector<string> pals;
int N;

int query(){
	int ones = 0, zeros = 0;
	vector<int> sizes(N);
	int odds = 0;
	FOR(i,N){
		FOR(j,pals[i].size()){
			if(pals[i][j] == '1'){++ones;}
			else{++zeros;}
		}
		sizes[i] = pals[i].size();
		if(sizes[i]%2 == 1){
			++odds;
		}
	}
	sort(sizes.begin(),sizes.end());
	int sones = ones,szeros = zeros;

	FOR(i,N){
		// cout<<i<<' '<<sizes[i]<<' '<<ones<<' '<<zeros<<'\n';
		while(sizes[i] > 0){
			if(ones > zeros){
				if(sizes[i] == 1){--ones;--sizes[i];}
				else{ones-=2;sizes[i]-=2;}
			}
			else{
				if(sizes[i] == 1){--zeros;--sizes[i];}
				else{zeros-=2;sizes[i]-=2;}
			}
			if(zeros > 0 && ones > 0){
				if(ones%2 == 1 && zeros%2 == 1 && odds > 0){
					if(ones < sones){
						++ones;
						--zeros;
					}
					else{
						++zeros;
						--ones;
					}
					--odds;
				}
			}
			// cout<<zeros<<' '<<ones<<' '<<i<<'\n';
			if(zeros < 0 || ones < 0){
				return i;
			}
		}
	}
	return N;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int Q;
	cin>>Q;
	FOR(i,Q){
		cin>>N;
		pals.resize(N);
		FOR(j,N){
			cin>>pals[j];
		}
		cout<<query()<<'\n';
	}


	return 0;
}