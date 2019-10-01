#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define ll long long int

ll n,q;

struct Building
{
	ll height;
	set<ll> buildingCons;
};

vector<Building*> heights;

struct BuildingCon{
	ll left, right, MAX, lastCalc;
	BuildingCon(ll l, ll r, ll M){
		left = l;
		right = r;
		MAX = M;
	}
	ll calcPro(){
		lastCalc = (heights[left]->height - heights[right]->height) - MAX;
		return lastCalc;
	}
};
vector<BuildingCon*> diffrenceMax;

void MAIN(){
	set<pair<ll,ll>> queue;
	for(ll i = 0; i < q; i++){
		queue.insert({diffrenceMax[i]->calcPro(),i});
	}
	while((*queue.rbegin()).first > 0){
		ll curBuildSub = (*queue.rbegin()).first;
		ll curBuildCon = (*queue.rbegin()).second;
		queue.erase(prev(queue.end(),1));
		heights[diffrenceMax[curBuildCon]->left]->height -= curBuildSub;
		for(ll buildingCon : heights[diffrenceMax[curBuildCon]->left]->buildingCons){
			if(buildingCon != curBuildCon){
				queue.erase(queue.find({diffrenceMax[buildingCon]->lastCalc,buildingCon}));
			}
			queue.insert({diffrenceMax[buildingCon]->calcPro(),buildingCon});	
		}
	}
}

int main(){
	cin>>n>>q;
	heights.resize(n);
	diffrenceMax.resize(q);
	ll h;
	for(ll i = 0; i < n; i++){
		cin>>h;
		heights[i] = new Building();
		heights[i]->height = h;
	}
	ll a,b,c;
	for(ll i = 0; i < q; i++){
		cin>>a>>b>>c;
		diffrenceMax[i] = new BuildingCon(b,a,c);
		heights[a]->buildingCons.insert(i);
		heights[b]->buildingCons.insert(i);
	}
	MAIN();
	ll sum = 0;
	for(ll i = 0; i < n; i++){
		sum += heights[i]->height;
	}
	cout<<sum;
}