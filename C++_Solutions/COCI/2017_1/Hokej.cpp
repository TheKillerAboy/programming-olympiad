#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main(){
	int N,M;
	cin>>M>>N;
	vector<pair<int,int>> players(N);
	vector<pair<int,int>> playersSorted(N); //value, index
	for(int i = 0; i < N; ++i){
		cin>>players[i].first>>players[i].second;
		playersSorted[i] = {players[i].first,i};
	}
	sort(playersSorted.begin(),playersSorted.end(),greater<pair<int,int>>());
	set<tuple<int,int,int>> playersCur; //time gone; time start; mul
	int t = 0;
	int end,start,id;
	unsigned ll sum = 0;
	for(int i = 0; i < 6; i++){
		id = playersSorted[i].second;
		playersCur.insert({players[id].second,1,id});
	}
	int curlate = 6;
	while(t < M){
		tie(end,start,id) = *playersCur.begin();
		t = end;
		if(t < M){
			playersCur.erase(playersCur.begin());
			sum += (end-start+1) * players[id].first;
			int id2 = playersSorted[curlate++].second;
			playersCur.insert({players[id2].second+t,t+1,id2});
		}
	}
	for(auto player : playersCur){
		tie(end,start,id) = player;
		cout<<id<<endl;
		sum += (M-start+1) * players[id].first;
	}
	cout<<sum;

	return 0;
}