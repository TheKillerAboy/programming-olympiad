#include <bits/stdc++.h>

using namespace std;

#define FOR(i_,a_) for(int i_=0;i_<a_;++i_)

inline bool isVariable(string a){
	bool isVar = true;
	for(auto let : a){
		if(let>='0' && let<='9'){
			isVar = false;
			break;
		}
	}
	return isVar;
}

inline int pureValue(string a){
	return stoi(a);
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	map<string,int> variableValue;
	map<string,set<int>> variableIndexsA;
	map<string,set<int>> variableIndexsB;

	cin>>N;

	vector<string> arrayOne(N);
	vector<string> arrayTwo(N);


	FOR(i,N){
		cin>>arrayOne[i];
		if(isVariable(arrayOne[i])){
			variableValue[arrayOne[i]] = -1;
			variableIndexsA[arrayOne[i]].insert(i);
		}
	}
	FOR(i,N){
		cin>>arrayTwo[i];
		if(isVariable(arrayTwo[i])){
			variableValue[arrayTwo[i]] = -1;
			variableIndexsB[arrayTwo[i]].insert(i);
		}
	}
	bool isPos = true;
	FOR(i,N){
		if(arrayOne[i] == arrayTwo[i]){
			continue;
		}
		if(isVariable(arrayOne[i]) && isVariable(arrayTwo[i])){
			if(variableValue[arrayOne[i]] == -1 && variableValue[arrayTwo[i]] == -1){
				for(int j : variableIndexsA[arrayTwo[i]]){
					arrayOne[j] = arrayOne[i];
				}
				for(int j : variableIndexsB[arrayTwo[i]]){
					arrayTwo[j] = arrayOne[i];
				}
			}
			else if(variableValue[arrayOne[i]] == -1){
				variableValue[arrayOne[i]] = variableValue[arrayTwo[i]];
			}
			else if(variableValue[arrayTwo[i]] == -1){
				variableValue[arrayTwo[i]] = variableValue[arrayOne[i]];
			}
			else{
				if(variableValue[arrayOne[i]] != variableValue[arrayTwo[i]]){
					isPos = false;
					break;
				}
			}
		}
		else if(isVariable(arrayOne[i])){
			if(variableValue[arrayOne[i]] == -1){
				for(int j : variableIndexsA[arrayOne[i]]){
					arrayOne[j] = arrayTwo[i];
				}
				for(int j : variableIndexsB[arrayOne[i]]){
					arrayTwo[j] = arrayTwo[i];
				}
			}
			else if(variableValue[arrayOne[i]] != pureValue(arrayTwo[i])){
				isPos = false;
				break;
			}
		}
		else if(isVariable(arrayTwo[i])){
			if(variableValue[arrayTwo[i]] == -1){
				for(int j : variableIndexsA[arrayTwo[i]]){
					arrayOne[j] = arrayOne[i];
				}
				for(int j : variableIndexsB[arrayTwo[i]]){
					arrayTwo[j] = arrayOne[i];
				}
			}
			else if(variableValue[arrayTwo[i]] != pureValue(arrayOne[i])){
				isPos = false;
				break;
			}
		}
		else{
			isPos = false;
			break;
		}
	}
	cout<<(isPos?"DA":"NE")<<'\n';

	
	return 0;
}