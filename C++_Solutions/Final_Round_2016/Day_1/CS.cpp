#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define ll unsigned long long int

vector<ll> factors(ll N){
	vector<ll> out;
	while(N%2 == 0){
		out.push_back(2);
		N/=2;
	}
	for(ll i = 3; i < sqrt(N); i+=2){
		while(N%i==0){
			out.push_back(i);
			N/=i;
		}
	}
	if(N>2){
		out.push_back(N);
	}
	return out;
}

ll sumInRange(ll S, ll T){
	return (((T+1)*T)>>1) - (((S-1)*S)>>1);
}

int main(){
	ll N;
	cin>>N;

	vector<ll> factorsN = factors(8*N);
	ll A = 1;
	ll C = 1;
	for(auto val: factorsN){
		if(val == 2){
			A*=2;
		}
		else{
			C*=val;
		}
	}
	ll B = C;
	while(A%4 == 0){
		B*=2;
		A/=2;
		ll k = (B+A)/2;

		ll S = (1+(ll)ceil(sqrt(k*k-8*N)))/2;
		ll T = ((ll)ceil(sqrt(1+4*S*S-4*S+8*N)) - 1)/2;
		if(S!=T && sumInRange(S,T) == N){
			cout<<S<<' '<<T<<endl;
			return 0;
		}
	}
	cout<<-1;


	return 0;
}