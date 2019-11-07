#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORA(e_,c_) for(auto e_:c_)

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N,K;
	cin>>N>>K;
	set<tuple<int,bool,int>> queue;
	vector<pair<int,int>> planks(N); 
	int a,b;
	FOR(i,N){
		cin>>a>>b;
		planks[i] = {a,b};
		queue.insert({a,0,i});
		queue.insert({b,1,i});
	}
	set<int> remove;
	set<pair<int,int>,greater<pair<int,int>>> current;
	int loc,num;
	bool type;
	while(!queue.empty()){
		tie(loc,type,num) = *queue.begin();
		queue.erase(queue.begin());
		if(type == 0){
			current.insert({planks[num].second,num});
		}
		else if(current.find({loc,num}) != current.end()){
			current.erase(current.find({loc,num}));
		}
		if(current.size() > K){
			remove.insert((*current.begin()).second);
			current.erase(current.begin());
		}
	}
	cout<<remove.size()<<'\n';
	FORA(ele,remove){
		cout<<ele+1<<' ';
	}
	return 0;
}