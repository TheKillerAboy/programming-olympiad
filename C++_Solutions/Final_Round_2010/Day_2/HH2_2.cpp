#include <set>
#include <map>
#include <iostream>
#include <climits>
#include <vector>
#include <cmath>

using namespace std;

#define INF LONG_MAX

#define MAXREV 9999999

vector<int> eulerPath;
vector<int> eulerPathDepths;
vector<set<int>> indexInEulerPath;
vector<int> roots;

vector<vector<pair<int,int>>> sparseTable;

vector<set<int>> connections;

void contructEulerPath(int node, int depth){
	eulerPath.push_back(node);
	eulerPathDepths.push_back(depth);
	indexInEulerPath[node].insert(eulerPath.size()-1);
	for(auto child : connections[node]){
		if(indexInEulerPath[child].empty()){
			contructEulerPath(child,depth+1);
			eulerPath.push_back(node);
			eulerPathDepths.push_back(depth);
			indexInEulerPath[node].insert(eulerPath.size()-1);
		}
	}
	if(indexInEulerPath[node].size() == 1){
		roots.push_back(node);
	}
}

void constructSparseTable(){
	int n = eulerPathDepths.size();
	for(int i = 0; i < n; i++){
		sparseTable[0][i] = {eulerPathDepths[i],i};
	}
	for(int j = 1; j < ceil(log2(n));j++){
		int curPow = pow(2,j);
		for(int i = 0; i < n - curPow + 1; i++){
			sparseTable[j][i] = min(sparseTable[j-1][i],sparseTable[j-1][i+curPow/2]);
		}
	}
}

pair<int,int> getMin(int a, int b){
	int l = b-a+1;
	int k = floor(log2(l));
	return min(sparseTable[k][a],sparseTable[k][a+l-(int)pow(2,k)]);
}

int distanceBetween(int a, int b){
	int indexA = *indexInEulerPath[a].begin();
	int indexB = *indexInEulerPath[b].begin();
	if(indexA > indexB){
		indexA = indexA ^ indexB;
		indexB = indexA ^ indexB;
		indexA = indexA ^ indexB;
	}
	int lca = eulerPath[getMin(indexA,indexB).second];
	return abs(eulerPathDepths[indexA]-eulerPathDepths[lca]) + abs(eulerPathDepths[indexB]-eulerPathDepths[lca]) + 1;
}

int main(){
	int Q;
	cin>>Q;
	int f,t;
	connections.resize(Q);
	indexInEulerPath.resize(Q);
	for(int i = 0; i < Q-1; i++){
		cin>>f>>t;
		connections[f-1].insert(t-1);
		connections[t-1].insert(f-1);
	}
	eulerPathDepths.reserve(MAXREV);
	eulerPath.reserve(MAXREV);
	indexInEulerPath.reserve(MAXREV);
	contructEulerPath(0,0);
	sparseTable = vector<vector<pair<int,int>>>((size_t)ceil(log2(eulerPathDepths.size())),vector<pair<int,int>>(eulerPathDepths.size()));
	int MAX = 0;
	constructSparseTable();
	for(int i = 0; i < roots.size(); i++){
		for(int j = i++; j < roots.size() ; j++){
			MAX = max(MAX,distanceBetween(roots[i],roots[j]));
		}
	}

	cout<<MAX<<endl;
	return 0;
}