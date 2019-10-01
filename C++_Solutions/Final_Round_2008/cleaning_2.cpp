#include <iostream>
#include <vector>

using namespace std;

#define ll long long int

int main(){
	ll N;
	cin>>N;
	vector<ll> arr(N);
	for(ll i = 0; i < N; i++){
		cin>>arr[i];
	}
	ll detonations = 0;

	ll MAX = arr[0];
	for(ll i = 1; i < N; i++){
		if(arr[i] < MAX){
			detonations+=MAX-arr[i];
			detonations%=1000000;
		}
		MAX = arr[i];
	}
	detonations+=MAX;
	detonations%=1000000;
	cout<<detonations<<endl;

	return 0;
}