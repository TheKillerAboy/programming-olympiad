#include <bits/stdc++.h>

using namespace std;

int main(){
	int deck[12] = {0,0,4,4,4,4,4,4,4,4,12,4};
	int N;
	cin>>N;
	int card;
	int X = 21;
	for(int i = 0; i < N; ++i){
		cin>>card;
		--deck[card];
		X-=card;
	}
	int sum = 0;
	for(int i = 2; i <= X; ++i){
		sum += deck[i];
	}
	if(sum > 52 - sum - N){
		cout<<"VUCI";
	}
	else{
		cout<<"DOSTA";
	}
	return 0;
}