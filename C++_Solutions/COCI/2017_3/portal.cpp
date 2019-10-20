#include <bits/stdc++.h>

using namespace std;

#define FOR1(_i,_a) for(int _i = 1; _i<_a; ++_i)
#define FOR(_i,_a) for(int _i = 0; _i<_a; ++_i)
#define FORR(_i,_a) for(int _i = _a - 1; _i>=0; --_i)
#define FORR1(_i,_a) for(int _i = _a - 2; _i>=0; --_i)

#define INF 1000000

typedef pair<int,int> Coor;

vector<vector<int>> leftMostWall;
vector<vector<int>> rightMostWall;
vector<vector<int>> upMostWall;
vector<vector<int>> downMostWall;

vector<vector<bool>> walls;

vector<vector<int>> dpI;

set<pair<int,Coor>> que;

int R,C;

int endX,endY;
int beginX,beginY;

inline bool isWall(int i, int j){
	if(i < 0 || i > C - 1 || j < 0 || j > R - 1){
		return true;
	}
	return walls[j][i];
}

void subDo(int prefix, int i, int j){
	if(isWall(i,j)){
		dpI[j][i] = INF;
		return;
	}
	if(dpI[j][i] == -1){
		dpI[j][i] = prefix+1;
		que.insert({prefix+1,{i,j}});
	}
}

int main(){
	cin>>R>>C;
	leftMostWall.resize(R,vector<int>(C));
	rightMostWall.resize(R,vector<int>(C));
	upMostWall.resize(R,vector<int>(C));
	downMostWall.resize(R,vector<int>(C));
	walls.resize(R,vector<bool>(C));
	dpI.resize(R,vector<int>(C,-1));

	string line;
	FOR(i,R){
		cin>>line;
		FOR(j,C){
			walls[i][j] = line[j] == '#';
			if(line[j] == 'C'){
				beginX = j;
				beginY = i;
			}
			else if(line[j] == 'F'){
				endX = j;
				endY = i;
			}
		}
	}
	FOR(i,R){
		leftMostWall[i][0] = 0;
		rightMostWall[i][C-1] = C-1;
		FOR1(j,C){
			if(walls[i][j]){
				leftMostWall[i][j] = j;
			}
			else{
				leftMostWall[i][j] = leftMostWall[i][j-1];
			}
		}
		FORR1(j,C){
			if(walls[i][j]){
				rightMostWall[i][j] = j;
			}
			else{
				rightMostWall[i][j] = rightMostWall[i][j+1];
			}
		}
	}
	FOR(j,C){
		upMostWall[0][j] = 0;
		downMostWall[R-1][j] = R-1;
		FOR1(i,R){
			if(walls[i][j]){
				upMostWall[i][j] = i;
			}
			else{
				upMostWall[i][j] = upMostWall[i-1][j];
			}
		}
		FORR1(i,R){
			if(walls[i][j]){
				downMostWall[i][j] = i;
			}
			else{
				downMostWall[i][j] = downMostWall[i+1][j];
			}
		}
	}
	dpI[beginY][beginX] = 0;
	que.insert({0,{beginX,beginY}});
	int curDis;
	int x,y;
	Coor curPos;
	while(!que.empty()){
		tie(curDis,curPos) = *que.begin();
		tie(x,y) = curPos;
		que.erase(que.begin());
		subDo(curDis,x,y+1);
		subDo(curDis,x,y-1);
		subDo(curDis,x-1,y);
		subDo(curDis,x+1,y);
		if(isWall(x-1,y) || isWall(x+1,y) || isWall(x,y-1) || isWall(x,y+1)){
			subDo(curDis,x,downMostWall[y][x]-1);
			subDo(curDis,x,upMostWall[y][x]+1);
			subDo(curDis,leftMostWall[y][x]+1,y);
			subDo(curDis,rightMostWall[y][x]-1,y);
		}
	}
	cout<<dpI[endY][endX]<<endl;

	return 0;
}