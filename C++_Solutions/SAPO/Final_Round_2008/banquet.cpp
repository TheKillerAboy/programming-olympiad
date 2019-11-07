#include <vector>
#include <iostream>
#include <climits>
#include <map>

using namespace std;

#define ll long long int

vector<ll> arr;
ll N;

vector<vector<map<int,ll>>> dp;

ll best(ll index, ll left, bool out);

ll getBest(ll index, ll left, bool out){
	if(index >= N){
		return 0;
	}
	if(dp[index][out].find(left) == dp[index][out].end()){
		dp[index][out][left] = best(index,left,out);
	}
	return dp[index][out][left];
}

ll best(ll index, ll left, bool out){
	if(!out){
		if(left == 0){
			return getBest(index+1,0,false)+arr[index];
		}
		return arr[index]+max(getBest(index+1,left-1,true),getBest(index+1,left,false));
	}
	return max(getBest(index,left,false),getBest(index+1,left,true));
}

int main(){
	ll L;
	cin>>N>>L;
	arr.resize(N);
	for(ll i = 0; i < N; i++){
		cin>>arr[i];
	}
	dp.resize(N,vector<map<int,ll>>(2));
	cout<<max(getBest(0,L,false),getBest(0,L-1,true));
}