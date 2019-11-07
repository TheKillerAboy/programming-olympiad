#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

#define ll long long int

string word;

map<string,ll> scores;

set<char> alphabet;

vector<vector<vector<ll>>> stored;

ll bonus(char a, char b){
	string cur;
	cur += a;
	cur += b;
	if(scores.find(cur) != scores.end()){
		return scores[cur];
	}
	return 0;
}

ll getScore(ll prefixSize){
	ll out = 0;
	for(ll i = 0; i < prefixSize-1; i++){
		out += bonus(word[i],word[i+1]);
	}
	return out;
}

ll getBestChange(ll prefixSize, char curChar, ll left);

ll bestChange(ll prefixSize, char curChar, ll left){
	if(left == 0){
		return getScore(prefixSize);
	}
	else if(left < 0){
		return 0;
	}
	else if(prefixSize < 2){
		return 0;
	}
	ll out = 0;
	for(auto let : alphabet){
		if(let!=word[prefixSize-2]){
			out = max(out,getBestChange(prefixSize-1,let,left-1) + bonus(let,curChar));
		}
		else{
			out = max(out,getBestChange(prefixSize-1,let,left) + bonus(let,curChar));
		}
	}
	return out;
}

ll getBestChange(ll prefixSize, char curChar, ll left){
	if(stored[prefixSize][curChar-'a'][left] == -1){
		ll out = bestChange(prefixSize,curChar,left);
		stored[prefixSize][curChar-'a'][left] = out;
		return out;
	}
	return stored[prefixSize][curChar-'a'][left];
}

int main(){
	cin>>word;
	for(auto let : word){
		alphabet.insert(let);
	}
	ll left,q;
	cin>>left;
	string a,b;
	cin>>q;
	ll score;
	for(ll i = 0; i < q; i++){
		cin>>a>>b>>score;
		scores[a+b] = score;
		alphabet.insert(a[0]);
		alphabet.insert(b[0]);
	}
	stored = vector<vector<vector<ll>>>(word.length()+1,vector<vector<ll>>(26,vector<ll>(left+1,-1)));
	cout<<bestChange(word.length()+1,'_',left)<<endl;
}