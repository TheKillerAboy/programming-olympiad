#include <bits/stdc++.h>

using namespace std;

#define FOR(_i,_a) for(int _i = 0; _i<_a; ++_i)


int main(){
	int N;
	cin>>N;
	char prev = '*';
	char cur;
	int count = 0;
	FOR(i,N){
		cin>>cur;
		if(cur != prev){
			++count;
		}
		prev = cur;
	}
	++count;

	cout<<count<<endl;

	return 0;
}