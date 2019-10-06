#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<set<int>> charactorsLocs(26);
string charactors;

void update(int i, char a){
	charactorsLocs[charactors[i]-'a'].erase(charactorsLocs[charactors[i]-'a'].find(i));
	charactors[i] = a;
	charactorsLocs[a-'a'].insert(i);
}

int query(int l, int r){
	int counter = 0;
	for(int i = 0; i < 26; i++){
		auto firstOqqur =  charactorsLocs[i].lower_bound(l);
		if(firstOqqur != charactorsLocs[i].end() && l<=*firstOqqur && *firstOqqur<=r){
			counter++;
		}
	}
	return counter;
}

int main(){
	int Q;
	cin>>charactors;
	for(int i = 0; i < charactors.length(); i++){
		charactorsLocs[charactors[i]-'a'].insert(i);
	}
	cin>>Q;
	int t,l,r;
	char c;
	for(int i = 0; i < Q; i++){
		cin>>t;
		if(t == 1){
			cin>>l>>c;
			update(l-1,c);
		}
		else{
			cin>>l>>r;
			cout<<query(l-1,r-1)<<'\n';
		}
	}

	return 0;
}