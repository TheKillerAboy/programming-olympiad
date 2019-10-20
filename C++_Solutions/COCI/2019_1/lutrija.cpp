#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORR(i_,a_) for(int i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(int i_=1;i_<a_;++i_)
#define ll long long int
#define ull unsigned long long int

bool isPrime(ull val){
	if(val%2 == 0 && val != 2){
		return false;
	}
	for(int i = 3; i<=sqrt(val); i+=2){
		if(val%i == 0){
			return false;
		}
	}
	return true;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll A,B;
	cin>>A>>B;
	list<ll> eles = list<ll>{A,B};
	set<ll> elesIn = set<ll>{A,B};
	bool isPos = true;
	while(isPos){
		isPos = false;
		for(auto it = ++eles.begin(); it!=eles.end();++it){
			ll prev = *(--it);
			++it;
			ll newPrime = abs(*it+prev);
			if(isPrime(newPrime) && elesIn.find(newPrime) == elesIn.end()){
				isPos = true;
				eles.insert(it,newPrime);
				elesIn.insert(newPrime);
			}
		}
	}
	if(eles.size() == 2 && !isPrime(abs(A-B))){
		cout<<-1;
		return 0;
	}
	cout<<eles.size()<<'\n';
	FORA(ele,eles){
		cout<<ele<<' ';
	}

	return 0;
}