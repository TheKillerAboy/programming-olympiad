#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> nodeOut;
vector<vector<char>> grid;

int M,N;

void updateNode(int x, int y){
	if(x < 0 || y< 0){
		return;
	}
	if(y-1 >= 0){
		if(x-1 >= 0 && grid[x-1][y-1] == '\\'){
			nodeOut[x-1][y-1] = nodeOut[x][y];
			updateNode(x-1,y-1);
		}
		if(grid[x][y-1] == '.'){
			nodeOut[x][y-1] = nodeOut[x][y];
			updateNode(x,y-1);
		}
		if(x+1 < N && grid[x+1][y-1] == '/'){
			nodeOut[x+1][y-1] = nodeOut[x][y];
			updateNode(x+1,y-1);
		}
	}
}

void updateNodeC(int x, int y, char c){
	grid[x][y] = c;
	if(c == '\\'){
		nodeOut[x][y] = nodeOut[x+1][y+1];
	}
	else if(c == '.'){
		nodeOut[x][y] = nodeOut[x][y+1];
	}
	else if(c == '/'){
		nodeOut[x][y] = nodeOut[x-1][y+1];
	}
	updateNode(x,y);
}

void fillGrid(){
	for(int i = 0; i < N; i++){
		nodeOut[i][M-1] = i;
		updateNode(i,M-1);
	}
}

int main(){
	int P;
	cin>>M>>N>>P;
	nodeOut.resize(N,vector<int>(M,-1));
	grid.resize(N,vector<char>(M,'.'));
	string line;
	for(int i = 0; i < M; i++){
		cin>>line;
		for( int j = 0; j < N; j++){
			grid[j][i] = line[j];
		}
	}
	fillGrid();
	char Q,R;
	int x,y;
	for(int i = 0; i < P; i++){
		cin>>Q;
		if(Q == 'Q'){
			cin>>x;
			cout<<nodeOut[x-1][0]+1<<endl;
		}
		else if(Q == 'U'){
			cin>>R>>y>>x;
			updateNodeC(x-1,y-1,R);
		}
	}
	return 0;
}