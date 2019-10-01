#include <stack>
#include <vector>
#include <iostream>

using namespace std;

bool isPossiable(vector<int> arr, int n){
	stack<int> branch;
	int get = 1;
	int i = n-1;
	while(i>=0){
		if(arr[i] == get){
			get++;
			i--;
		}
		else if(!branch.empty() && get == branch.top()){
			get++;
			branch.pop();

		}
		else{
			branch.push(arr[i--]);
		}
	}
	while(!branch.empty() && get == branch.top()){
			get++;
			branch.pop();
	}
	return branch.empty();
}

int main(){
	int Q;
	cin>>Q;
	vector<int> pro;
	for(int i = 0; i < Q; i++){
		int n;
		cin>>n;
		pro.resize(n);
		for(int j = 0; j < n; j++){
			cin>>pro[j];
		}
		cout<<(isPossiable(pro,n) ? 'Y' : 'N')<<endl;
	}

	return 0;
}