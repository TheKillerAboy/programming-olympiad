/*
ID: annekin1
TASK: milk2
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
#define INF INT_MAX

int main(){
	ifstream fin("milk2.in");
	ofstream fout("milk2.out");
	int N;
	fin>>N;
	multiset<pair<int,bool>> queue;
	int a,b;
	FOR(i,N){
		fin>>a>>b;
		queue.insert({a,0});
		queue.insert({b,1});
	}
	int size = 0;
	int Mabsent = 0;
	int Mpresent = 0;
	int stopMilking = INF;
	int startMilking = 0;
	int time;
	bool type;
	while(!queue.empty()){
		tie(time,type) = *queue.begin();
		queue.erase(queue.begin());
		if(type == 0){
			if(size == 0){
				cout<<"Absence "<<stopMilking<<' '<<time<<' '<<time-stopMilking<<'\n';
				Mabsent = max(Mabsent,time-stopMilking);
				startMilking = time;
			}
			++size;
		}
		else if(type == 1){
			if(size > 0){
			--size;
			}
			if(size == 0){
				cout<<"Prensent "<<startMilking<<' '<<time<<' '<<time-startMilking<<'\n';
				stopMilking = time;
				Mpresent = max(Mpresent,time-startMilking);
			}
		}
		cout<<"Time Check: "<<time<<' '<<size<<'\n';
	}
	fout<<Mpresent<<' '<<Mabsent<<'\n';

	return 0;
}