#include <set>
#include <iostream>

using namespace std;

set<unsigned int> primes = {2,3,5};
unsigned int lastcheck  =5;

void primes_upto(unsigned int n){
	if(lastcheck>=n){
		return;
	}
	bool isPrime;
	for(unsigned int i = lastcheck + 2; i <= n; i++){
		isPrime = true;
		for(unsigned int prime : primes){
			if(i%prime == 0){
				isPrime = false;
				break;
			}
		}
		if(isPrime){
			primes.insert(i);
		}
	}
	lastcheck = n + n%2 - 1;
}

bool isPrime(unsigned int p){
	primes_upto(p);
	return primes.find(p) != primes.end();
}

unsigned int nth_prime(unsigned int n){
	while(primes.size() < n){
		primes_upto(lastcheck+2);
	}
	return *next(primes.begin(),n-1);
}

bool isRTPrime(string p, unsigned int depth){
	if(depth <= 0){
		return true;
	}
	if(isPrime(stoi(p))){
		return isRTPrime(p.substr(0,p.length()-1),depth -1);
	}
	return false;
}

unsigned int nth_RTPrime(unsigned int n){
	set<unsigned int> RTPrimes = {2,3,5};
	while(RTPrimes.size() < n){
		if(isPrime(lastcheck+2)){
			string p = to_string(lastcheck);
			if(isRTPrime(p,p.length())){
				RTPrimes.insert(lastcheck);
			}
		}	
	}
	return *next(RTPrimes.begin(),n-1);
}

int main(){
	unsigned int N;
	cin>>N;
	cout<<nth_RTPrime(N)<<endl;

	return 0;
}