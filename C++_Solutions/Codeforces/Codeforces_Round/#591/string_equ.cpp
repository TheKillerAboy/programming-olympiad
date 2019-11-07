#include <bits/stdc++.h>

using namespace std;

bool qeury(string s, string t){
	set<char> sChars(s.begin(),s.end());
	for(auto let : t){
		if(sChars.find(let) != sChars.end()){
			return true;
		}
	}
	return false;
}

int main(){
	int q;
	cin>>q;
	string s,t;
	for(int i = 0; i < q; ++i){
		cin>>s>>t;
		cout<<(qeury(s,t) ? "YES" : "NO")<<'\n';
	}

	return 0;
}