#include <utility>
#include <iostream>
#include <map>
#include <set>
#include <memory>

#define ui unsigned int
#define ll long long

using namespace std;

typedef pair<ui,ui> Coor;

#define X first
#define Y second

ui getIndexed(Coor a, bool b){
  return b == 0 ? a.X : a.Y;
}

ui distance(Coor a, Coor b){
  return abs((ll)a.X-(ll)b.X) + abs((ll)a.Y-(ll)b.Y);
}

class D2Node{
public:
  Coor value;
  shared_ptr<D2Node> leftC;
  shared_ptr<D2Node> rightC;
  D2Node(Coor loc){
    value = loc;
  }
  void push(Coor loc, bool indSc){
    if(loc == value){
      return;
    }
    if(getIndexed(loc,indSc) >= getIndexed(value,indSc)){
      if(rightC){
        rightC->push(loc,indSc+1);
      }
      else{
        rightC = make_shared<D2Node>(loc);
      }
    }
    else{
      if(leftC){
        leftC->push(loc,indSc+1);
      }
      else{
        leftC = make_shared<D2Node>(loc);
      }
    }
  }
  ui getMin(Coor loc, bool indSc){
    ui distanceS = distance(loc,value);
    if(getIndexed(loc,indSc) >= getIndexed(value,indSc)){
      if(rightC){
        distanceS = min(distanceS,rightC->getMin(loc,indSc+1));
      }
    }
    else{
      if(leftC){
        distanceS = min(distanceS,leftC->getMin(loc,indSc+1));
      }
    }
    return distanceS;
  }
  D2Node();
};

class D2Tree{
public:
  shared_ptr<D2Node> root;
  void push(Coor loc){
    if(root){
      root->push(loc,0);
    }
    else{
      root = make_shared<D2Node>(loc);
    }
  }
  ui getMin(Coor loc){
    return root->getMin(loc,0);
  }
  D2Tree(){;};
};

map<ui,pair<set<Coor>,shared_ptr<D2Tree>>> constulations;
ui D;
ui current = 0;

ui addStar(Coor loc){
  set<ui> constConnect;
  for(auto constl : constulations){
      if(constl.second.second->getMin(loc) <= D){
        constConnect.insert(constl.first);
      }
    }
  if(!constConnect.empty()){
    auto curConstl = constConnect.begin();
    ui firstConstl = *curConstl;
    constulations[firstConstl].first.insert(loc);
    constulations[firstConstl].second->push(loc);
    advance(curConstl,1);
    while(curConstl != constConnect.end()){
      for(auto star : constulations[*curConstl].first){
        constulations[firstConstl].second->push(star);
        constulations[firstConstl].first.insert(star);
      }
      constulations.erase(*curConstl);
      advance(curConstl,1);
    }
    return constulations[firstConstl].first.size();
  }
  else{
    constulations[current++].first.insert(loc);
    constulations[current-1].second = make_shared<D2Tree>();
    constulations[current-1].second->push(loc);
    return constulations[current-1].first.size();
  }
}

int main(){
  ui n;
  cin>>n>>D;
  Coor loc;
  for(ui i = 0; i < n ; i++){
    cin>>loc.X>>loc.Y;
    cout<<addStar(loc)<<endl;
  }

  return 0;
}
