#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORR(i_,a_) for(int i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define ll long long int

int main(){
	// cin.tie(0);
	// ios::sync_with_stdio(false);
	int L,R,M;
	cin>>L>>R>>M;
	vector<int> lNodes(L);
	vector<int> rNodes(R);
	vector<set<int>> lNodesLink(L);
	vector<set<int>> rNodesLink(R);
	vector<set<int>> lNodesIDS(L);
	vector<set<int>> rNodesIDS(R);
	map<pair<int,int>,int> colors;
	vector<pair<int,int>> pairs(M); 
	int MAX = 0;
	int l,r;
	FOR(i,M){
		cin>>l>>r;
		++lNodes[l-1];
		++rNodes[r-1];
		lNodesLink[l-1].insert(r-1);
		rNodesLink[r-1].insert(l-1);
		MAX = max(MAX,lNodes[l-1]);
		MAX = max(MAX,rNodes[r-1]);
		pairs[i] = {l-1,r-1};
	}
	cout<<MAX<<'\n';
	set<tuple<int,bool,int>> queue;
	set<int> leftQueue;
	set<int> rightQueue;
	FOR(i,L){
		queue.insert({lNodes[i],0,i});
		leftQueue.insert(i);
	}
	FOR(i,R){
		queue.insert({rNodes[i],1,i});
		rightQueue.insert(i);
	}
	int nodes,id;
	bool side;
	while(!queue.empty()){
		tie(nodes,side,id) = *queue.begin();
		queue.erase(queue.begin());
		if(side == 0){
			FOR(i,MAX){
				if(lNodesIDS[id].size() >= nodes){
					break;
				}
				if(lNodesIDS[id].find(i) == lNodesIDS[id].end()){
					lNodesIDS[id].insert(i);
					for(auto connected : lNodesLink[id]){
						if(rightQueue.find(connected) != rightQueue.end() && rNodesIDS[connected].find(i) == rNodesIDS[connected].end()){
							rNodesIDS[connected].insert(i);
							// cout<<id<<' '<<connected<<'\n';
							colors[{id,connected}] = i;
							break;
						}
					}
				}
			}
			leftQueue.erase(leftQueue.find(id));
		}
		else{
			FOR(i,MAX){
				if(rNodesIDS[id].size() >= nodes){
					break;
				}
				if(rNodesIDS[id].find(i) == rNodesIDS[id].end()){
					rNodesIDS[id].insert(i);
					for(auto connected : rNodesLink[id]){
						if(leftQueue.find(connected) != leftQueue.end() && lNodesIDS[connected].find(i) == lNodesIDS[connected].end()){
							lNodesIDS[connected].insert(i);
							// cout<<connected<<' '<<id<<'\n';
							colors[{connected,id}] = i;
							break;
						}
					}
				}
			}
			rightQueue.erase(rightQueue.find(id));
		}
	}
	FOR(i,M){
		cout<<colors[pairs[i]]+1<<'\n';
	}

	return 0;
}