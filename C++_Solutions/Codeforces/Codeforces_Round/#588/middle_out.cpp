#include <iostream>
#include <string>
#include <map>
#include <climits>

using namespace std;

#define INF INT_MAX/2

int N;
string END;
map<string,map<string,int>> dpI;

inline string swapFront(string a, int pos){
	return a[pos] + a.substr(0,pos) + a.substr(pos+1);
}

inline string swapBack(string a, int pos){
	return a.substr(0,pos) + a.substr(pos+1) + a[pos];
}

inline int score(string a){
	
}

int query(string start){
	dpI.clear();
	string changed(N,'0');
	return dp(start,changed);
}

int main(){
	string start;
	int Q;
	cin>>Q;
	for(int i = 0; i < Q; ++i){
		cin>>N;
		cin>>start>>END;
		cout<<query(start)<<'\n';
	}
	return 0;
}