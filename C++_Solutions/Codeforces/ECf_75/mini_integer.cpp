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

string integer;
int N;

void query(){
	string evens;
	evens.reserve(N);
	string odds;
	odds.reserve(N);
	FOR(i,N){
		if((integer[i]-'0')%2 == 0){
			evens+=integer[i];
		}
		else{
			odds+=integer[i];
		}
	}
	int i = 0, j = 0;
	int I = evens.size(), J = odds.size();
	FOR(k,N){
		if(i<I && j<J){
			if(evens[i] < odds[j]){
				integer[k]=evens[i++];
			}
			else{
				integer[k]=odds[j++];
			}
		}
		else if(i<I){
			integer[k]=evens[i++];
		}
		else{
			integer[k]=odds[j++];
		}
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int Q;
	cin>>Q;
	FOR(i,Q){
		cin>>integer;
		N = integer.size();
		query();
		cout<<integer<<'\n';
	}

	return 0;
}