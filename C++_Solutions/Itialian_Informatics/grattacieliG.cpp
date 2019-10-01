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

long long costruisci(int N, int M, vector<long long>& H, vector<int>& A, vector<int>& B, vector<int>& C){
    n=N;
    q=M;
    heights.resize(n);
    diffrenceMax.resize(q);
    for(ll i = 0; i < n; i++){
        heights[i] = new Building();
        heights[i]->height = H[i];
    }
    for(ll i = 0; i < q; i++){
        diffrenceMax[i] = new BuildingCon(B[i],A[i],C[i]);
        heights[A[i]]->buildingCons.insert(i);
        heights[B[i]]->buildingCons.insert(i);
    }
    MAIN();
    ll sum = 0;
    for(ll i = 0; i < n; i++){
        sum += heights[i]->height;
    }
    return sum;
}
