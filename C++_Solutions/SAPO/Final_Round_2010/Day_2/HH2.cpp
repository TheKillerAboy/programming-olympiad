#include <set>
#include <map>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

#define INF LONG_MAX
vector<set<int>> connections;
vector<int> roots;

int getLong(vector<int>& depths,int depth, int node, bool append){
	depths[node] = depth; 
	int out = depth;
	bool hasChildren = false;
	for(auto nextNode : connections[node]){
		if(depths[nextNode] == -1){
			out = max(out,getLong(depths,depth+1,nextNode,append));
			hasChildren = true;
		}
	}
	if(!hasChildren && append){
		roots.push_back(node);
	}
	return out;
}

// int getLong(int start){
// 	set<pair<int,int>> query;
// 	vector<int> dist(connections.size(),INF);
// 	query.insert({0,start});
// 	dist[start] = 0;
// 	int MAX = 0;
// 	int curDis, curLoc;
// 	while(!query.empty()){
// 		tie(curDis,curLoc) = *query.begin();
// 		MAX = max(MAX,curDis);
// 		query.erase(query.begin());
// 		for(auto nextLoc : connections[curLoc]){
// 			int nextDis = dist[nextLoc];
// 			if(nextDis > curDis + 1){
// 				if(nextDis != INF){
// 					query.erase(query.find({nextDis,nextLoc}));
// 				}
// 				dist[nextLoc] = curDis + 1;
// 				query.insert({curDis+1,nextLoc});
// 			}
// 		}
// 	}
// 	return MAX + 1;
// }

int main(){
	int Q;
	cin>>Q;
	int f,t;
	connections.resize(Q);
	for(int i = 0; i < Q-1; i++){
		cin>>f>>t;
		connections[f-1].insert(t-1);
		connections[t-1].insert(f-1);
	}
	int MAX = 0;
	vector<int> depths(Q,-1);			
	getLong(depths,0,0,true);
	for(int i = 0; i < roots.size(); i++){
		vector<int> depths(Q,-1);
		MAX = max(MAX,getLong(depths,0,roots[i],false));
	}
	cout<<MAX+1<<endl;
}

/*

7
2 6
6 5
3 7
4 6
1 5
5 3

*/