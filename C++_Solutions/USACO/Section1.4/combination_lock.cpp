/*
ID: annekin1
TASK: combo
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

#define _ cerr<<' ';
#define _N cerr<<'\n';
#define TRACEV(v_) cerr<<v_;
#define TRACEP(p_) cerr<<"("<<p_.first<<", "<<p_.second<<") ";
#define TRACECE(c_,tt_) for(auto e_:c_){tt_(e_);_;}_N;
#define TRACEC(c_) TRACECE(c_,TRACEV)
#define TRACEE(v_,tt_) tt_(v_);_N;
#define TRACE(v_) TRACEE(v_,TRACEV);
#define TRACEEP(v_) TRACEE(v_,TRACEP);

#define ll long long int
#define ull unsigned long long int

int N;

inline int UNION(int a, int b){
	set<int> setA;
	for(int i = a-2; i <= a+2; ++i){
		setA.insert((i+N)%N);
	}
	set<int> setB;
	for(int i = b-2; i <= b+2; ++i){
		setB.insert((i+N)%N);
	}
	int count = 0;
	FORA(ele,setA){
		if(setB.find(ele) != setB.end()){
			++count;
		}
	}
	return count;
}

inline int power3(int a){
	return a*a*a;
}

int main(){
	ifstream fin("combo.in");
	ofstream fout("combo.out");
	fin>>N;
	vector<int> J(3),M(3);
	FOR(i,3){
		fin>>J[i];
	}
	FOR(i,3){
		fin>>M[i];
	}
	int mul = 1;
	FOR(i,3){
		mul *= UNION(J[i],M[i]);
	}
	fout<<2*power3(min(5,N))-mul<<'\n';


	return 0;
}