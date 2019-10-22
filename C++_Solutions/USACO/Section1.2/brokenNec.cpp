/*
ID: annekin1
TASK: beads
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

int main(){
	ifstream fin("beads.in");
	ofstream fout("beads.out");
	int N;
	string necklace;
	fin>>N>>necklace;
	vector<char> adjRC(N);
	vector<char> adjLC(N);
	vector<int> adjR(N);
	vector<int> adjL(N);
	int start = 0;
	FOR(i,N){
		if(necklace[i] != 'w'){
			adjLC[i] = necklace[i];
			adjRC[i] = necklace[i];
			start = i;
			break;
		}
	}
	fprintf(stderr,"INIT\n" );
	FOR(i,N){
		if(necklace[(start+i)%N] == 'w'){
			adjRC[(start+i)%N] = adjRC[(start+i-1+2*N)%N];
		}
		else{
			adjRC[(start+i)%N] = necklace[(start+i)%N];
		}
		if(necklace[(start-i+2*N)%N] == 'w'){
			adjLC[(start-i+2*N)%N] = adjLC[(start-i+1+2*N)%N];
		}
		else{
			adjLC[(start-i+2*N)%N] = necklace[(start-i+2*N)%N];
		}
	}
	fprintf(stderr,"Charactar Setup\n" );
	int rS = 0,lS = 0;
	FOR(i,N){
		if(adjRC[i%N] != adjRC[(i+1)%N]){
			adjR[i%N] = 1;
			rS = i%N;
		}
		if(adjLC[i%N] != adjLC[(i-1+2*N)%N]){
			adjL[i%N] = 1;
			lS = i%N;
		}
	}
	FOR(i,N){
		if(adjR[(rS-i+2*N)%N] != 1){
			adjR[(rS-i+2*N)%N] = adjR[(rS-i+1+2*N)%N]+1;
		}
		if(adjL[(lS+i+2*N)%N] != 1){
			adjL[(lS+i+2*N)%N] = adjL[(lS+i-1+2*N)%N]+1;
		}
	}
	FOR(i,N){
		cout<<adjLC[i]<<'\t';
	}
	cout<<'\n';
	FOR(i,N){
		cout<<adjL[i]<<'\t';
	}
	cout<<'\n';
	FOR(i,N){
		cout<<adjRC[i]<<'\t';
	}
	cout<<'\n';
	FOR(i,N){
		cout<<adjR[i]<<'\t';
	}
	cout<<'\n';
	fprintf(stderr,"Direction Go\n" );
	int MAX = 0;
	FOR(i,N){
		// cout<<adjL[(i+1)%N]+adjR[i]<<'\n';
		MAX = max(MAX,adjL[i]+adjR[(i+1)%N]);
	}
	fprintf(stderr,"Found GO\n" );
	fout<<(MAX>N?N:MAX)<<'\n';

	return 0;
}