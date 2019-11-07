#include <bits/stdc++.h>

using namespace std;

#define l long int

string START,END;

bool query(){
	l has = 0;
	for(int i = 0; i < START.size(); ++i){
		has |= 1<<(START[i] - 'a');
	}
	for(int i = 0; i < END.size(); ++i){
		if(has & 1<<(END[i] - 'a')){
			return true;
		}
	}
	return false;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int q;
	cin>>q;
	for(int i = 0; i < q; ++i){
		cin>>START>>END;
		cout<<(query() ? "YES" : "NO")<<'\n';
	}

	return 0;
}