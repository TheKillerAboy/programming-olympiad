#include <iostream>
#include <utility>
#include <climits>
#include <vector>

using namespace std;

#define ll long long int

#define NINF LLONG_MIN

int main(){
	string word;
	cin>>word;
	vector<ll> lastSeen(20,NINF);
	pair<ll,ll> currentRange;
	currentRange = {0,-1};
	ll MAX = 0;
	for(int i = 0; i < word.length(); i++){
		if(lastSeen[word[i]-'a'] >= currentRange.first){
			currentRange.first = lastSeen[word[i]-'a']+1;
		}
		currentRange.second = i;
		lastSeen[word[i]-'a'] = i;
		MAX = max(MAX,currentRange.second-currentRange.first+1);
	}
	cout<<MAX;
	return 0;
}