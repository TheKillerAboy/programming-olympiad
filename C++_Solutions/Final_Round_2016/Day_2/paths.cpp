#include <set>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <iostream>

using namespace std;

typedef int City;
typedef int Distance;

vector<map<pair<City,City>,Distance>> stored;

#define INF 9999999

map<pair<City,City>,City> pathsWeights;
map<int,set<int>> paths;

map<City,set<pair<City,City>>> invalidPaths;

Distance getDistance(City a, City b){
	if(a>b){
		return getDistance(b,a);
	}
	auto it = pathsWeights.find(pair<int,int>{a,b});
	if(it == pathsWeights.end()){
		return INF;
	}
	return it->second;
}

bool isValid(City next, City current, City prev){
	if(invalidPaths.find(next) != invalidPaths.end()){
		return invalidPaths[next].find(pair<int,int>{prev,current}) == invalidPaths[next].end();
	}
	return false;
}

void fillStored(){
	set<tuple<Distance,City,pair<City,City>>> query;
	query.insert(tuple<Distance,City,pair<City,City>>{0,0,pair<int,int>{-1,-1}});
	stored[0][pair<City,City>{-1,-1}] = 0;
	int curDis, curCity;
	pair<int,int> prevCities;
	while(!query.empty()){
		tie(curDis,curCity,prevCities) = *query.begin();
		query.erase(query.begin());
		for(auto nextLoc : paths[curCity]){
			int nextDis = INF;
			int prevCity = prevCities.second;
			if(isValid(nextLoc,curCity,prevCity)){
				if(stored[nextLoc].find({prevCity,curCity}) != stored[nextLoc].end()){
					nextDis = stored[nextLoc][{prevCity,curCity}];
				}
				int newNextDis = curDis + getDistance(curCity,nextLoc);
				if(newNextDis < nextDis){
					if(nextDis != INF){
						query.erase({nextDis,nextLoc,{prevCity,curCity}});
					}
					stored[nextLoc][{prevCity,curCity}] = newNextDis;
					query.insert({newNextDis,nextLoc,{prevCity,curCity}});
				}
			}
		}
	}
}

void pathFill(vector<City>& path, int next, int cur){
	if(next == 0){
		path.push_back(0);
		return;
	}
	pair<Distance,City> prev = {INF,-1};
	for(auto keyValue : stored[next]){
		if(keyValue.first.second == cur){
			prev = min(prev,{keyValue.second,keyValue.first.first});
		}
	}
	pathFill(path,cur,prev.second);
	path.push_back(next);
}

int main(){
	int N,M,K;
	cin>>N>>M>>K;
	stored.resize(N);
	int a,b,c;
	for(int i = 0; i < M; i++){
		cin>>a>>b>>c;
		pathsWeights[pair<int,int>{a-1,b-1}] = c-1;
		paths[a-1].insert(b-1);
		paths[b-1].insert(a-1);
	}
	for(int i = 0; i < K; i++){
		cin>>a>>b>>c;
		invalidPaths[c-1].insert(pair<int,int>{a-1,b-1});
	}

	fillStored();

	int MIN = INF;
	int prev;
	for(auto keyValue : stored[N-1]){
		if(keyValue.second < MIN){
			MIN = keyValue.second;
			prev = keyValue.first.second;
		}
	}
	if(MIN == INF){
		cout<<-1<<endl;
		return 0;
	}
	cout<<MIN<<endl;
	vector<City> bestPath;
	pathFill(bestPath,N-1,prev);
	for(auto loc : bestPath){
		if()
		cout<<loc+1<<' ';
	}
}