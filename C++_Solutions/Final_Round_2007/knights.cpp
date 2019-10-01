#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <tuple>

using namespace std;

typedef pair<int,int> Coor;

vector<Coor> OFFSETS = {{2,1},{2,-1},{-1,2},{1,2},{-2,1},{-2,-1},{-1,-2},{1,-2}};
Coor END = {0,0};

Coor add(Coor a, Coor b){
	return {a.first+b.first,a.second+b.second};
}

int shortestMoves(Coor from){
	set<Coor> all;
	set<pair<int,Coor>> queue = {{0,from}};
	Coor current;
	int curDis;
	while(all.find(END) == all.end()){
		tie(curDis,current) = *queue.begin();
		queue.erase(queue.begin());
		all.insert(current);
		for(auto OFFSET : OFFSETS){
			Coor next = add(OFFSET,current);
			if(all.find(next) == all.end() && queue.find({curDis,next}) == queue.end() && queue.find({curDis+1,next}) == queue.end()){
				queue.insert({curDis+1,next});
			}
		}
	}
	return curDis;
}

int main(){
	int N;
	cin>>N;
	int x,y;
	int total = 0;
	for(int i = 0; i < N; i++){
		cin>>x>>y;
		total+=shortestMoves({x,y});
	}
	cout<<total<<endl;
	return 0;
}