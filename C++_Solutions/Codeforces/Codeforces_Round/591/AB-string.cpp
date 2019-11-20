#include <bits/stdc++.h>

using namespace std;

#define ll long long int

vector<vector<int>> dpI;

vector<ll> factorials(51);

void generateFactorials(){
	factorials[0] = 1;
	factorials[1] = 1;
	for(int i = 2; i < 50; i++){
		factorials[i] = factorials[i-1]*i;
	}
}

int dp(int As, int Bs){
	cout<<As<<' '<<Bs<<endl;
	if(As==1 || Bs==1){
		return 0;
	}
	else if(As == 0 && Bs == 0){
		return 1;
	}
	if(dpI[As][Bs] != -1){
		return dpI[As][Bs];
	}
	int out = 0;
	for(int i = 0; i <= As; ++i){
		for(int j = 0; j <= Bs; ++j){
			if(!(i%2 == 1 && j%2 == 1) && !(i == 0 && j == 0)){
				out += dp(As-i,Bs-j);
			}
		}
	}
	return out;
}

int main(){
	int n;
	int As = 0, Bs = 0;
	string str;
	cin>>n;
	cin>>str;
	generateFactorials();
	for(int i = 0; i < n; ++i){
		if(str[i] == 'A'){
			++As;
		}
		else{
			++Bs;
		}
	}
	dpI.resize(As+1,vector<int>(Bs+1,-1));
	cout<<dp(As,Bs)<<'\n';

	return 0;
}