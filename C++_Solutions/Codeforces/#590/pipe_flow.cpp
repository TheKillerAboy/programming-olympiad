#include <vector>
#include <iostream>
#include <string>

using namespace std;

#define ui unsigned int

enum Direction : unsigned char{
	Left,Right,Up,Down
};

bool query(vector<vector<bool>> circuit, ui l){
	Direction curDir = Left;
	ui x = 0,y = 0;

	while(!(x == l - 1 && y==1) && y <2 && x < l){
		if(circuit[x][y] == 0 && curDir == Left){
			x++;
		}
		else if(circuit[x][y] == 1){
			if(curDir == Up || curDir == Down){
				x++;
				curDir = Left;
			}
			else if(curDir == Left){
				if(y == 0){
					y++;
					curDir = Down;
				}
				else{
					y--;
					curDir = Up;
				}
			}
		}
		else{
			return false;
		}
	}
	return x==l-1 && y == 1 &&((curDir == Down && circuit[x][y] == 1)||(curDir == Left && circuit[x][y] == 0));
}

int main(){
	 ui Q,l;
	 cin>>Q;
	 string seq;
	 vector<vector<bool>> circuit;
	 for(ui i = 0; i < Q; ++i){
	 	cin>>l;
	 	circuit.resize(l,vector<bool>(2));
	 	for(ui k = 0; k < 2; ++k){
	 		cin>>seq;
		 	for(ui j = 0; j < l; ++j){
		 		circuit[j][k] = seq[j] > '2';
		 	}
	 	}
	 	cout<<(query(circuit,l) ? "YES" : "NO")<<'\n';
	 }

	 return 0;
}