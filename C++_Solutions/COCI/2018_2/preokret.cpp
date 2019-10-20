#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORR(i_,a_) for(int i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define ll long long int

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	set<pair<int,bool>> queue;
	int A,B;
	cin>>A;
	int time;
	FOR(i,A){
		cin>>time;
		queue.insert({time,0});
	}
	cin>>B;
	FOR(i,B){
		cin>>time;
		queue.insert({time,1});
	}
	const int HALFTIME = 2*12*60;
	int halftimeScore = 0;
	bool side;
	int AScore = 0;
	int BScore = 0;
	tie(time,side) = *queue.begin();
	bool leading = side;
	int shifts = 0;
	FORA(event,queue){
		tie(time,side) = event;
		if(time <= HALFTIME){
			++halftimeScore;
		}	
		if(!side){
			++AScore;
		}
		else{
			++BScore;
		}
		if((leading && BScore < AScore) || (!leading && BScore > AScore)){
			leading=!leading;
			++shifts;
		}
	}
	cout<<halftimeScore<<'\n'<<shifts<<'\n';


	return 0;
}