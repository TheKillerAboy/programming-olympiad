#include <bits/stdc++.h>

using namespace std;

#define FOR1(_i,_a) for(int _i = 1; _i<_a; ++_i)
#define FOR(_i,_a) for(int _i = 0; _i<_a; ++_i)

int R,S;
int xMPos;	
vector<string> board;
vector<vector<pair<int,int>>> bestChild;

pair<char,int> getBest(int prefix, int i, int j);

void partialBest(int prefix,int newPrefix, pair<char,int>& MAX,char prefixChar, int i_, int j_,int i, int j){
	char cur;
	int curSuffix;
	tie(cur,curSuffix) = getBest(newPrefix,i_,j_);
	if(curSuffix > 0){
		return;
	}
	if(newPrefix + curSuffix == 0){
		if(prefixChar != 255){
			if(min(MAX.first,prefixChar) == prefixChar){
				if(bestChild[j][i] == pair<int,int>{-1,-1} || min(prefixChar,board[bestChild[j][i].second][bestChild[j][i].first]) == prefixChar){
					MAX = {prefixChar, curSuffix+(newPrefix-prefix)};
					bestChild[j][i] = {i_,j_};
				}
			}
		}
		if(min(MAX.first,cur) == cur){
			if(bestChild[j][i] == pair<int,int>{-1,-1} || min(cur,board[bestChild[j][i].second][bestChild[j][i].first]) == cur){
				MAX = {cur, curSuffix};
				bestChild[j][i] = bestChild[j_][i_];
			}
		}
	}
}

pair<char,int> getBest(int prefix, int i, int j){
	if(prefix < 0 || j < 0 || board[j][i] == '*'){
		return {255,0};
	}
	int newPrefix = prefix;
	char prefixChar = 255;
	pair<char,int> MAX = {255,0};
	if(board[j][i] == '('){ ++newPrefix;
		prefixChar = board[j][i];}
	else if(board[j][i] == ')'){ --newPrefix;
		prefixChar = board[j][i];}
	if(i-1>=0){
		partialBest(prefix,newPrefix,MAX,prefixChar,i-1,j-1,i,j);
	}
	partialBest(prefix,newPrefix,MAX,prefixChar,i,j-1,i,j);	
	if(i+1<S){
		partialBest(prefix,newPrefix,MAX,prefixChar,i+1,j-1,i,j);
	}
	return MAX;
}

int main(){
	cin>>R>>S;
	board.resize(R);
	bestChild.resize(R,vector<pair<int,int>>(S,{-1,-1}));
	FOR(i,R){
		cin>>board[i];
		FOR(j,S){
			if(board[i][j] == 'M'){
				xMPos = j;
			}
		}
	}
	getBest(0,xMPos,R-1);
	pair<int,int> loc = {xMPos,R-1};
	string exp = "";
	while(loc != pair<int,int>{-1,-1}){
		exp+=board[loc.second][loc.first];
		loc = bestChild[loc.second][loc.first];
	}
	cout<<exp<<endl;
	return 0;
}