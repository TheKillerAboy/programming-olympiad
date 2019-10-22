/*
ID: annekin1
TASK: dualpal
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
#define ll long long int
#define ull unsigned long long int

typedef vector<char> vi;

int B;

inline int power(int a, int b){
	return b==0?1:(b==1?a:power(a,b/2)*power(a,b/2+b%2));
}

vi convert(int a){
	vi out;
	FORR(i,floor(log(a)/log(B))+1){
		int back = a/power(B,i);
		if(back>=10){
			out.push_back('A'+back-10);
		}
		else{
			out.push_back('0'+back);
		}
		a -= back*power(B,i);
	}
	return out;
}

bool isPale(vi a){
	FOR(i,a.size()){
		if(a[i]!=a[a.size()-1-i]){
			return false;
		}
	}
	return true;
}

int main(){
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");
	int N,S;
	fin>>N>>S;
	int got = 0;
	++S;
	int pales = 0;
	while(got < N){
		pales = 0;
		for(B = 2; B<=10;++B){
			if(pales==2){
				break;
			}
			if(isPale(convert(S))){
				++pales;
			}
		}
		if(pales == 2){
			fout<<S<<'\n';
			++got;
		}
		++S;
	}


	return 0;
}