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
#define _T cerr<<'\t';
#define TRACEV(v_) cerr<<v_;
#define TRACEP(p_) cerr<<"("<<p_.first<<", "<<p_.second<<") ";
#define TRACECE(c_,tt_) for(auto e_:c_){tt_(e_);_;}_N;
#define TRACEC(c_) TRACECE(c_,TRACEV)
#define TRACEE(v_,tt_) tt_(v_);_N;
#define TRACE(v_) TRACEE(v_,TRACEV);
#define TRACEEP(v_) TRACEE(v_,TRACEP);

#define ll long long int
#define ull unsigned long long int

vector<pair<int,int>> edges;
map<int,set<int>> nodeEdges;
map<int,int> nodeToGroup;
map<int,int> nodeToGroupSize;
set<int> visited;
set<int> roots;

inline int uFind(int a){
	if(nodeToGroup.find(a) == nodeToGroup.end()){
		nodeToGroup[a] = -1;
		nodeToGroupSize[a] = 1;
		roots.insert(a);
	}
	int current = a;
	while(nodeToGroup[current] != -1){
		current = nodeToGroup[current];
	}
	if(current != a){
		nodeToGroup[a] = current;
	}
	return current;
}

inline void uMerge(int a, int b){
	int aP = uFind(a);
	int bP = uFind(b);
	if(aP != bP){
		if(nodeToGroupSize[aP] > nodeToGroupSize[bP]){
			nodeToGroup[bP] = aP;
			nodeToGroupSize[aP] += nodeToGroupSize[bP];
			roots.erase(roots.find(bP));
		}
		else{
			nodeToGroup[aP] = bP;
			nodeToGroupSize[bP] += nodeToGroupSize[aP];
			roots.erase(roots.find(aP));
		}
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int Q,N,a,b;
	cin>>Q;
	FOR(i,Q){
		cin>>N;
		nodeToGroup = map<int,int>();
		nodeToGroupSize = map<int,int>();
		nodeEdges = map<int,set<int>>();
		roots = set<int>();
		edges.resize(N);
		FOR(j,N){
			cin>>a>>b;
			uMerge(a,b);
			nodeEdges[a].insert(j);
			nodeEdges[b].insert(j);
			edges[j] = {a,b};
		}
		cout<<roots.size()-1<<'\n';
		while(roots.size()>1){
			int masterNode = *roots.begin();
			roots.erase(roots.begin());
			set<int> queue = {masterNode};
			while(!queue.empty() && nodeEdges[masterNode].size() != 1){
				masterNode = *queue.begin();
				queue.erase(queue.begin());
				visited.insert(masterNode);
				FORA(c,nodeEdges[masterNode]){
					int otherNode = edges[c].first == masterNode ? edges[c].second : edges[c].first;
					if(visited.find(otherNode) == visited.end()){
						queue.insert(otherNode);
					}
				}
			}
			int masterEdge = *nodeEdges[masterNode].begin();
			cout<<masterEdge+1<<' '<<masterNode<<' '<<*roots.begin()<<'\n';
		}
	}


	return 0;
}