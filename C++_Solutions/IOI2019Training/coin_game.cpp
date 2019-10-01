#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void query(vector<int>& arr, int n){
	if(n < 3){
		cout<<"IMPOSSIBLE"<<endl;
		return;
	}
	int out = 0;
	while(prev_permutation(arr.begin(),arr.end())){
		out+=4;
	}
	cout<<out<<endl;
}

int main(){
	int Q;
	cin>>Q;
	int N;
	vector<int> arr;
	for(int i = 0; i < Q; i++){
		cin>>N;
		arr.resize(N);
		for(int j = 0; j < N; j++){
			cin>>arr[j];
		}
		query(arr,N);
	}
	return 0;
}