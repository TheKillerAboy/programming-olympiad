#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
#include <set>

using namespace std;

int N,M;
vector<int> NVec;
list<int> MList;
list<int> NList;

bool cmpITL(const pair<int,list<int>::iterator>& a, const pair<int,list<int>::iterator>& b){
	return a.first < b.first;
}

bool cmpITG(const pair<int,list<int>::iterator>& a, const pair<int,list<int>::iterator>& b){
	return a.first > b.first;
}

int calculate_best(vector<int> arr, int N){
	vector<int> dp(N);
	vector<int> maxToEnd(N);
	dp[N-1] = arr[N-1];
	maxToEnd[N-1] = dp[N-1];
	dp[N-2] = arr[N-2];
	maxToEnd[N-2] = max(dp[N-2],maxToEnd[N-1]);
	for(int i = N-3; i>=0;i--){
		dp[i] = max(dp[i+1],maxToEnd[i+2]+arr[i]);
		maxToEnd[i] = max(dp[i],maxToEnd[i+1]);
	}
	return dp[0];
}

int best(vector<int> alreadyIn, list<int> putIn, int N){
	if(putIn.size() == 0){
		return calculate_best(alreadyIn,N);
	}
	int out = 0;
	for(int i = 0; i <= N; i++){
		auto copyIn = alreadyIn;
		copyIn.insert(copyIn.begin()+i,putIn.front());
		auto copyPut = putIn;
		copyPut.pop_front();
		out = max(out,best(copyIn,copyPut,N+1));
	}
	return out;
}

int best_ov(){
	int brl;
	vector<int> br(M+N);
	for(int i = 0; i < N; i++){
		br.push_back(NVec[i]);
	}
	for(auto value : MList){
		br.push_back(value);
	}
	sort(br.begin(),br.end());
	brl = br[((M+N)>>1)-1];

	list<int> NList;
	set<pair<int,list<int>::iterator>,decltype(&cmpITG)> queue(cmpITG);
	for(auto it = NList.begin(); it != NList.end(); it++){
		queue.insert({*it,it});
	}
	set<pair<int,list<int>::iterator>,decltype(&cmpITL)> insertQueue(cmpITL);
	for(auto it = MList.begin(); it != MList.end(); it++){
		queue.insert({*it,it});
	}
	while(!insertQueue.empty()){
		auto curNIt = (*queue.begin()).second;
		auto qcurNIt = queue.begin();
		int iqB = (*insertQueue.rbegin()).first;
		if(*curNIt < iqB){
			bool foundP = false;
			for(auto it = NList.begin(); it != NList.end(); it++){
				if(next(it,1) != NList.end() && *it < brl && *next(it,1) < brl){
					NList.insert(next(it,1),iqB);
					queue.insert({iqB,next(it,1)});
					insertQueue.erase(prev(insertQueue.end(),1));
					foundP = true;
					break;
				}
			}
			if(!foundP){
				bool foundP2 = false;
				for(auto it = NList.begin(); it != NList.end(); it++){
					if(*it < brl){
						if(*prev(it,1) > iqB && *next(it,1) < *prev(it,1)){
							NList.insert(it,iqB);
							queue.insert({iqB,prev(it,1)});
							insertQueue.erase(prev(insertQueue.end(),1));
						}
						else{
							NList.insert(next(it,1),iqB);
							queue.insert({iqB,next(it,1)});
							insertQueue.erase(prev(insertQueue.end(),1));
						}
						foundP2 = true;
						break;
					}
				}
				if(!foundP2){
					if(NList.front() > NList.back()){
						NList.push_back(iqB);
						queue.insert({iqB,prev(NList.end(),1)});
						insertQueue.erase(prev(insertQueue.end(),1));
					}
					else{
						NList.push_front(iqB);
						queue.insert({iqB,NList.begin()});
						insertQueue.erase(prev(insertQueue.end(),1));
					}
				}
			}
		}
		else{
			if(*next(curNIt,1) > brl){
				NList.insert(next(curNIt,1),(*insertQueue.begin()).first);
				insertQueue.erase(insertQueue.begin());
			}
			else if(*prev(curNIt,1) > brl){
				NList.insert(curNIt,(*insertQueue.begin()).first);
				insertQueue.erase(insertQueue.begin());
			}
			else{
				queue.erase(qcurNIt);
			}
		}
	}
	NVec.resize(N+M);
	int i = 0;
	for(auto value : NList){
		NVec[i++] = value;
	}
	return calculate_best(NVec,N+M);
}

int main(){
	cin>>N;
	NVec.resize(N);
	for(int i = 0; i < N; i++){
		cin>>NVec[i];
	}
	for(int i = 0; i < N; i++){
		NList.push_back(NVec[i]);
	}
	cin>>M;
	int g;
	for(int i = 0; i < M; i++){
		cin>>g;
		MList.push_back(g);
	}
	cout<<best_ov();
	return 0;
}