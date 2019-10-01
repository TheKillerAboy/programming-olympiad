#include <iostream>

using namespace std;

#define ll unsigned long long int

ll S,N;
ll* arr;

int main(){
	cin>>S>>N;
	arr = new ll[N];
	for(ll i = 0; i < N; i++){
		cin>>arr[i];
	}
	ll sum = 0;
	ll l = 0;ll r = 0;
	while(sum != S && r <= N){
		if(sum > S){
			sum -= arr[l++];
		}
		else if(sum < S && r < N){
			sum += arr[r++];
		}
		else{
			break;
		}
	}
	if(sum != S){
		cout<<"IMPOSSABLE"<<endl;
	}
	else{
		cout<<l+1<<' '<<r<<endl;
	}
}