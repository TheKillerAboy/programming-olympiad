#include <vector>
#include <iostream>

using namespace std;

int main(){
	int W,H;
	cin>>H>>W;
	vector<vector<int>> matrix(W,vector<int>(H,0));
	for(int i = 0; i < H; ++i){
		for(int j = 0; j < W; ++j){
			cin>>matrix[j][i];
		}
	}
	int sum = 0;
	for(int i = H-1; i>=0;--i){
		for(int j = W-1; j>=0; --j){
			if(matrix[j][i] == 0){
				matrix[j][i] = min(matrix[j+1][i],matrix[j][i+1])-1;
			}
			if(i>0 && j> 0 && matrix[j][i] <= max(matrix[j-1][i],matrix[j][i-1])){
				cout<<-1;
				return 0;
			}
			sum += matrix[j][i];
		}
	}
	cout<<sum;
	return 0;
}