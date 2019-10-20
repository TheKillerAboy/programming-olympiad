#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> Coor;

#define INF INT_MAX

#define X first
#define Y second

vector<pair<vector<Coor>,int>> shapes = {
	{{{0,0},{0,1},{1,1},{1,0}},0},//Square
	{{{0,0},{1,0},{2,0},{3,0}},1},//Straight
	{{{0,0},{0,1},{0,2},{0,3}},1},//Straight
	{{{2,0},{0,1},{1,1},{1,0}},2},//Sque 1
	{{{0,0},{0,1},{1,1},{1,2}},2},//Sque 1
	{{{0,2},{0,1},{1,1},{1,0}},3},//Sque 2
	{{{0,0},{2,1},{1,1},{1,0}},3},//Sque 2
	{{{2,1},{0,1},{1,1},{1,0}},4},//Mid
	{{{1,2},{0,1},{1,1},{1,0}},4},//Mid
	{{{0,0},{0,1},{1,1},{0,2}},4},//Mid
	{{{0,0},{2,0},{1,1},{1,0}},4}//Mid
};

void centralize_shape(vector<Coor>& shape){
	int minX = INF, minY = INF;
	for(auto block: shape){
		minX = min(minX,block.X);
		minY = min(minY,block.Y);
	}
	for(int i = 0; i < 4; ++i){
		shape[i].X-=minX;
		shape[i].Y-=minY;
	}
}

bool shapesEqu(vector<Coor>& a, vector<Coor>& b){
	bool hasBlock;
	for(int i = 0; i < 4; ++i){
		hasBlock = false;
		for(int j = 0; j < 4; ++j){
			if(a[i] == b[j]){
				hasBlock = true;
				break;
			}
		}
		if(!hasBlock){
			return false;
		}
	}
	return true;
}

int figureType(vector<Coor> shape){
	centralize_shape(shape);
	for(auto S : shapes){
		if(shapesEqu(S.first,shape)){
			return S.second;
		}
	}
}