/*
ID: annekin1
TASK: palsquare
LANG: C++                 
*/
#include <bits/stdc++.h>

using namespace std;
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(int i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(int i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(int i_=1;i_<a_;++i_)
#define ll long long int
#define ull unsigned long long int
#define TRACE(x_) cout<<x_<<'\n';
#define TRACEVI(x_) for(auto v_:x_){cout<<v_;};cout<<'\n';
typedef vector<char> vi;

int B;

int power(int a, int b){
	int out = 1;
	FOR(i,b){
		out*=a;
	}
	return out;
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
	cin.tie(0);
	ios::sync_with_stdio(false);
	fin>>B;
	FORI(i,300){
		if(isPale(convert(i*i))){
			FORA(e,convert(i)){
				fout<<e;
			}
			fout<<' ';
			FORA(e,convert(i*i)){
				fout<<e;
			}
			fout<<'\n';
		}
	}


	return 0;
}