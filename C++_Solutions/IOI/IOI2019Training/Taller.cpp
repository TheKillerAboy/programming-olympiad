#include <map>
#include <set>
#include <iostream>

using namespace std;

map<int,set<int>> heights;

void append(int x, int y){
	heights[y].insert(x);
}

bool hasNode(int cN, int wN){
	auto& cNH = heights[cN];
	if(cNH.find(wN) == cNH.end()){
		for(auto c : cNH){
			if(hasNode(c,wN)){
				return true;
			}
		}
		return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	int N, Q;
	cin>>N>>Q;
	int x,y;
	for(int i = 0; i < Q; i++){
		cin>>x>>y;
		append(x,y);
	}
	cin>>x>>y;
	if(hasNode(x,y)){
		cout<<"no";
	}
	else if(hasNode(y,x)){
		cout<<"yes";
	}
	else{
		cout<<"unknown";
	}
	return 0;
}