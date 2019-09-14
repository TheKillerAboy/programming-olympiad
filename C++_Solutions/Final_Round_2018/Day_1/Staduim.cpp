#include <iostream>
#include <climits>
#include <utility>
#include <vector>
#include <array>
#include <memory>
#include <set>

using namespace std;

#define ll long long int

typedef pair<ll,ll> Coor;

#define X first
#define Y second

#define INF LLONG_MAX
#define INFCOOR Coor{INF,INF}

struct Record2{
	vector<Coor> myRecord;

	Record2(){
		myRecord = {INFCOOR,INFCOOR};
	}

	void push(Coor c,Coor a){
		if(c!=a &&a != myRecord[1]){
			myRecord[0] = myRecord[1];
			myRecord[1] = a;
		}
	}

	Coor top(){
		return myRecord[1];
	}
};

ll alignerIndex(Coor a, bool al){
	if(al == 0){
		return a.X;
	}
	return a.Y;
}

ll distance(Coor a, Coor b){
	return (a.X-b.X)*(a.X-b.X) + (a.Y-b.Y)*(a.Y-b.Y);
}

struct D2Node{
	Coor value;
	unique_ptr<D2Node> leftChild;
	unique_ptr<D2Node> rightChild;

	D2Node(Coor a){
		value = a;
	}

	void push(Coor a, bool al){
		unique_ptr<D2Node>* push_toP;
		if(alignerIndex(a,al) < alignerIndex(value,al)){
			push_toP = &leftChild;
		}
		else{
			push_toP = &rightChild;
		}
		unique_ptr<D2Node>& push_to = *push_toP;
		if(push_to){
			push_to->push(a,al+1);
		}
		else{
			push_to = unique_ptr<D2Node>(new D2Node(a));
		}
	}

	static Coor distanceMinReturnCoor(Coor p, Coor a, Coor b){
		if(distance(p,a)<distance(p,b)){
			return a;
		}
		return b;
	}

	void getClosest(array<shared_ptr<Record2>,4>& minDistance, Coor a, bool al){
		for(int i = 0; i < 4 ; i++){
			if(a == value){
				minDistance[i]->push(a,value);
			}
			if(!leftChild && !rightChild){
				minDistance[i]->push(a,value);
			}
			unique_ptr<D2Node>* push_toP;
			if(!leftChild){
				push_toP = &rightChild;
			}
			else if(!rightChild){
				push_toP = &leftChild;
			}
			else if(distance(leftChild->value,a)<distance(rightChild->value,a)){
				push_toP = &leftChild;
			}
			else{
				push_toP = &rightChild;
			}
			unique_ptr<D2Node>& push_to = *push_toP;
			push_to->getClosest(minDistance,a,al+1);
			minDistance[i]->push(a,distanceMinReturnCoor(a,minDistance[i]->top(),value));
		}
	}
};

struct D2Tree{
	unique_ptr<D2Node> root;
	D2Tree(){;}
	void push(Coor a){
		if(root){
			root->push(a,0);
		}
		else{
			root = unique_ptr<D2Node>(new D2Node(a));
		}
	}
	array<shared_ptr<Record2>,4> getClosest(Coor a){
		array<shared_ptr<Record2>,4> out;
		for(int i = 0; i < 4; i++){
			out[i] = make_shared<Record2>();
		}
		root->getClosest(out,a,0);
		return out;
	}
};

ll area(Coor a, shared_ptr<Record2> b){
	return max(abs(b->myRecord[1].X-b->myRecord[0].X),abs(b->myRecord[1].Y-b->myRecord[0].Y));
}

int main(){
	int N,W;
	cin>>N>>W;
	vector<Coor> trees;
	trees.reserve(N+4);
	set<Coor> defaults = {{0,0},{W+1,W+1},{0,W+1},{W+1,0}};
	D2Tree treesProc;
	int x,y;
	for(int i = 0; i < N; i++){
		cin>>x>>y;
		treesProc.push({x,y});
		trees.push_back({x,y});
		if(defaults.find({x,y}) == defaults.end()){
			defaults.erase(defaults.find({x,y}));
		}
	}
	for(auto def : defaults){
		trees.push_back(def);
		treesProc.push(def);
	}
	ll MAX = 0;
	for(auto loc : trees){
		auto closest = treesProc.getClosest(loc);
		for(auto record2 : closest){
			MAX = max(MAX,area(loc,record2)); 
		}
	}
	cout << MAX << endl;
	return 0;
} 