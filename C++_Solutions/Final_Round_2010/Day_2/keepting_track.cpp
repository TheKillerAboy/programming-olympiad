#include <iostream>
#include <climits>
#include <utility>

using namespace std;

#define INF LONG_MAX

#define ll unsigned long long int

ll* ps;
ll* arr;
ll N,S;	

void fillPrefixSum(){
	ps = new ll[N];
	ps[0] = arr[0];
	for(ll i = 1; i < N; i++){
		ps[i] = ps[i-1]+arr[i];
	}
}

ll getSum(ll l, ll r){
	if(l == 0){
		return ps[r];
	}
	return ps[r]-ps[l-1];		
}

ll getSize(ll li, ll l, ll r, ll value){
	if(value == 0){
		return l-li;
	}
	else if(l<r){
		ll mid = (l+r)>>1;
		ll left = getSum(l,mid);
		if(left <= value){
			return getSize(li,mid+1,r,value-left);
		}
		else{
			return getSize(li,l,mid,value);
		}
	}
	else if(l==r){
		if((ll)arr[l] == value){
			return l+1-li;
		}
	}
	return INF;
}

int main(){
	cin>>S>>N;
	arr = new ll[N];
	for(ll i = 0; i < N; i++){
		cin>>arr[i];
	}
	fillPrefixSum();
	pair<ll,ll> MIN;
	for(ll i = 0; i < N; i++){
		MIN = {getSize(i,i,N-1,S),i};
		if(MIN.first != INF){
			cout<<MIN.second+1<<' '<<MIN.second+MIN.first<<endl;
			return 0;
		}
	}
	cout<<"IMPOSSABLE"<<endl;
	return 0;
}