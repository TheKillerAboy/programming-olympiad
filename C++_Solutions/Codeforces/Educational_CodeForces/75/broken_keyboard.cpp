#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)
#define FORS(s_,i_,a_) for(int i_=s_;i_<a_;++i_)
#define FORR(i_,a_) for(int i_=a_-1;i_>=0;--i_)
#define FORI(i_,a_) for(int i_=1;i_<=a_;++i_)
#define FORA(i_,a_) for(auto i_:a_)
#define FOR1(i_,a_) for(int i_=1;i_<a_;++i_)
#define ll long long int
#define ull unsigned long long int

string query(string a){
	vector<bool> mal(26,true);
	int i = 0;
	while(i < a.size()){
		if(i+1 < a.size() && a[i] == a[i+1]){
			i += 2;
		}
		else{
			mal[a[i]-'a'] = false;
			i += 1;
		}
	}
	string out;
	FOR(i,26){
		if(!mal[i]){
			out+=i+'a';
		}
	}
	return out;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int Q;
	string line;
	cin>>Q;
	FOR(i,Q){
		cin>>line;
		cout<<query(line)<<'\n';
	}


	return 0;
}