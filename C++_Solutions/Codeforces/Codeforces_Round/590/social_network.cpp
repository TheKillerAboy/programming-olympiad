#include <list>
#include <set>
#include <iostream>

using namespace std;

#define ull unsigned long long int

list<ull> connections;
set<ull> connectionsSorted;

ull k;

void add_connection(ull id){
	if(connectionsSorted.find(id) == connectionsSorted.end()){
		if(connectionsSorted.size() == k){
			ull last = connections.back();
			connections.pop_back();
			connectionsSorted.erase(connectionsSorted.find(last));
		}
		connectionsSorted.insert(id);
		connections.push_front(id);
	}
}

int main(){
	ull Q;
	cin>>Q>>k;
	ull id;
	for(int i = 0; i < Q; ++i){
		cin>>id;
		add_connection(id);
	}
	cout<<connectionsSorted.size()<<endl;
	for(auto value : connections){
		cout<<value<<' ';
	}
	return 0;
}