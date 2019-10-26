/*
ID: annekin1
TASK: crypt1
LANG: C++                 
*/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(int i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(int i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(int i_=1;i_<a_;++i_)
#define TRACEC(c_) for(auto e_:c_){cout<<e_<<' ';}cout<<'\n';
#define ll long long int
#define ull unsigned long long int


set<int> top;
set<int> bottom;	
vector<int> allowed;
int N;
set<int> allowedS;

inline int sizeI(int a){
	return floor(log10(a))+1;
}
bool inAllowed(int b){
	int cb = b;
	FOR(i,sizeI(b)){
		if(allowedS.find(cb%10) == allowedS.end()){
			return false;
		}
		cb/=10;
	}
	return true;
}

int main(){
	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");
	fin>>N;
	allowed.resize(N);
	FOR(i,N){
		fin>>allowed[i];
	}
	allowedS = set<int>(allowed.begin(), allowed.end());
	vector<int> sub(4,0);
	while(sub[3] == 0){
		FOR(i,3){
			if(sub[i] == N){
				sub[i]=0;
				++sub[i+1];
			}
		}
		top.insert(allowed[sub[0]]*100+allowed[sub[1]]*10+allowed[sub[2]]);
		++sub[0];
	}
	sub = vector<int>(3,0);
	while(sub[2] == 0){
		FOR(i,2){
			if(sub[i] == N){
				sub[i]=0;
				++sub[i+1];
			}
		}
		bottom.insert(allowed[sub[0]]*10+allowed[sub[1]]);
		++sub[0];
	}
	int amount = 0;
	FORA(t,top){
		FORA(b,bottom){
			int e = b%10, d = (b/10)%10;
			if(sizeI(e*t) == 3 && inAllowed(e*t) && sizeI(d*t) == 3 && inAllowed(d*t) && sizeI(b*t) == 4 && inAllowed(b*t)){
				++amount;
			}
		}
	}
	fout<<amount<<'\n';

	return 0;
}