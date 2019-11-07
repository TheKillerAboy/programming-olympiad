#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <utility>
#include <tuple>

using namespace std;

#define INF 99

int getBegin(set<int>& s){
	if(s.begin() == s.end()){
		return INF;
	}
	else{
		return *s.begin();
	}
}

int N;
vector<int> initial;

void get_fastest(){
	set<vector<set<int>>> found;
	list<pair<int,vector<set<int>>>> queue;
	vector<set<int>> ini(N);
	for(int i = 0; i < N; i++){
		ini[i] = set<int>{initial[i]};
	}
	queue.push_back({0,ini});
	found.insert(ini);

	int curDur;
	vector<set<int>> curConv;
	while(!queue.empty()){
		tie(curDur,curConv) = *queue.begin();
		queue.pop_front();
		bool canExit = true;
		for(int i = 0; i < N; i++){
			if(getBegin(curConv[i]) != i+1){
				canExit=false;
				break;
			}
		}
		if(canExit){
			cout<<curDur<<endl;
			return;
		}

		// left-most
		if(getBegin(curConv[0]) != INF && getBegin(curConv[0])<getBegin(curConv[1])){
			vector<set<int>> copyConv = curConv;
			copyConv[1].insert(*copyConv[0].begin());
			copyConv[0].erase(copyConv[0].begin());
			if(found.find(copyConv) == found.end()){
				found.insert(copyConv);
				queue.push_back({curDur+1,copyConv});
			}
		}

		// right-most
		if(getBegin(curConv[N-1]) != INF && getBegin(curConv[N-1])<getBegin(curConv[N-2])){
			vector<set<int>> copyConv = curConv;
			copyConv[N-2].insert(*copyConv[N-1].begin());
			copyConv[N-1].erase(copyConv[N-1].begin());
			if(found.find(copyConv) == found.end()){
				found.insert(copyConv);
				queue.push_back({curDur+1,copyConv});
			}
		}

		//other
		for(int i = 1; i < N-1; i++){
			if(getBegin(curConv[i]) != INF && getBegin(curConv[i])<getBegin(curConv[i+1])){
				vector<set<int>> copyConv = curConv;
				copyConv[i+1].insert(*copyConv[i].begin());
				copyConv[i].erase(copyConv[i].begin());
				if(found.find(copyConv) == found.end()){
					found.insert(copyConv);
					queue.push_back({curDur+1,copyConv});
				}
			}
			if(getBegin(curConv[i]) != INF && getBegin(curConv[i])<getBegin(curConv[i-1])){
				vector<set<int>> copyConv = curConv;
				copyConv[i-1].insert(*copyConv[i].begin());
				copyConv[i].erase(copyConv[i].begin());
				if(found.find(copyConv) == found.end()){
					found.insert(copyConv);
					queue.push_back({curDur+1,copyConv});
				}
			}
		}
	}
	cout<<"IMPOSSIBLE"<<endl;
}

int main(){
	int Q;
	cin>>Q;
	for(int i = 0; i < Q; i++){
		cin>>N;
		initial.resize(N);
		for(int j = 0; j < N; j++){
			cin>>initial[j];
		}
		get_fastest();
	}
	return 0;
}