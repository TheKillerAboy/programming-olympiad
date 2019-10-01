#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> prefixSum;

int getValue(int a, int b){
	if(a<0 || b<0){
		return 0;
	}
	else{
		return prefixSum[a][b];
	}
}

int getSum(int xl, int yl, int xr, int yr){
	return getValue(xr,yr) - getValue(xl-1,yr) - getValue(xr,yl-1) + getValue(xl-1,yl-1);
}

int main(){
	vector<vector<int>> grid;
	int M,N;
	cin>>N>>M;
	grid.resize(M,vector<int>(N,0));
	prefixSum.resize(M,vector<int>(N,0));
	for(int i = 0; i < N; i ++){
		for(int j = 0; j<M; j++){
			cin>>grid[j][i];
		}
	}
	for(int x = 0; x < M; x++){
		for(int y = 0; y < N; y++){
			prefixSum[x][y] = grid[x][y] + getValue(x-1,y) + getValue(x,y-1) - getValue(x-1,y-1);
		}
	}
	int MAX = 0;
	for(int xs = 1; xs <= M; xs++){
		for(int ys = 1; ys<=N;ys++){
			for(int x = 0; x<=M-xs;x++){
				for(int y = 0; y<= N-ys;y++){
					MAX = max(MAX,getSum(x,y,x+xs-1,y+ys-1));
				}
			}
		}
	}
	cout<<MAX<<endl;

	return 0;
}