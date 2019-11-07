#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define INF -1

set<pair<int,int>> items;

vector<pair<int,multiset<pair<int,int>>>> store;

pair<int,multiset<pair<int,int>>> maxUtility(int spaceLeft){
	pair<int,multiset<pair<int,int>>> out = {INF,multiset<pair<int,int>>()};
	pair<int,multiset<pair<int,int>>> cur;
	for(auto item : items){
		if(item.first <= spaceLeft){
			cur = store[spaceLeft-item.first].first == INF ? maxUtility(spaceLeft-item.first) : store[spaceLeft-item.first]; 
			if(cur.first + item.second> out.first){
				out = cur;
				out.second.insert(item);
				out.first += item.second;
			}
		}
		else{
			break;
		}
	}
	store[spaceLeft] = out;
	return store[spaceLeft];
}

int main(){
	int C,K;
	cin>>C>>K;

	store.resize(C+1);
	for(int i = 0; i < C+1; i++){
		store[i] = {INF,multiset<pair<int,int>>()};
	}
	int size, ut;
	for(int i = 0; i < K; i++){
		cin>>size>>ut;
		items.insert({size,ut});
	}
	for(int i = 0; i < (*items.begin()).first-1;i++){
		store[i].first = 0;
	}
	pair<int,multiset<pair<int,int>>> maxUtil = maxUtility(C);
	cout<<maxUtil.first<<endl;
	for(auto it = maxUtil.second.rbegin(); it != maxUtil.second.rend(); it++){
		cout<<(*it).first<<' '<<(*it).second<<endl;
	}
}