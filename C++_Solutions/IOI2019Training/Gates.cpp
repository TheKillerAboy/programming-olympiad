#include <iostream>
#include <set>

using namespace std;

set<int> notdocked;

bool dock(int max){
	auto it = notdocked.upper_bound(max);
	if(it == notdocked.begin()){
		return false;
	}
	notdocked.erase(prev(it,1));
	return true;
}

int main(){
	int Q,N;
	cin>>N>>Q;
	int cur;
	int count = 0;
	bool able = true;
	for(int i = 0; i < N; i++){
		notdocked.insert(i+1);
	}
	for(int i = 0; i < Q; i++){
		cin>>cur;
		if(able){
			count++;
			if(!dock(cur)){
				able=false;
				count--;
			}
		}
	}
	cout<<count<<endl;
	return 0;
}