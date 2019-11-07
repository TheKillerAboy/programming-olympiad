#include <iostream>
#include <set>
#include <vector>
#include <array>
#include <map>
#include <tuple>

using namespace std;

typedef pair<int,int> Coor;

#define X first
#define Y second

#define INF 999999

vector<vector<char>> CAVE;
int N,M,K;
Coor END,START;

array<Coor,4> OFFSETS = array<Coor,4>{Coor{1,0},Coor{0,1},Coor{0,-1},Coor{-1,0}};

bool inBound(Coor a){
  return 0<=a.X && a.X<M && 0<=a.Y && a.Y<N;
}

char getLoc(Coor a){
  return CAVE[a.Y][a.X];
}

Coor add(Coor a, Coor b){
  return Coor{a.X+b.X,a.Y+b.Y};
}

void printCoor(Coor a){
  cout<<'('<<a.X<<", "<<a.Y<<')'<<endl;
}

vector<Coor> adjacent(Coor cur){
  vector<Coor> out;
  out.reserve(4);
  for(auto offset : OFFSETS){
    auto newLoc = add(offset,cur);
    if(inBound(newLoc)){
      out.push_back(add(offset,cur));
    }
  }
  return out;
}

int getMinDistance(){
  // dinamte, distance, loc
  set<tuple<int,int,Coor>> queue;
  map<Coor,pair<int,int>> dist;

  queue.insert(tuple<int,int,Coor>{0,0,START});
  dist[START] = pair<int,int>{0,0};

  Coor currentLoc;
  int currentDyn,currentDis;

  Coor bestEnd = {K+1,INF};

  while(!queue.empty()){
    if(dist.find(END) != dist.end()){
      Coor curEnd = dist[END];
      if(bestEnd.second > curEnd.second){
        bestEnd = curEnd;
      }
    }
    tie(currentDyn,currentDis,currentLoc) = *queue.begin();
    queue.erase(queue.begin());
    for(auto nextLoc : adjacent(currentLoc)){
      pair<int,int> newDist;
      if(getLoc(nextLoc) == '#'){
        if(dist[currentLoc].first < K){
          newDist = add(dist[currentLoc],Coor{1,1});
        }
        else{
          continue;
        }
      }
      else{
        newDist = add(dist[currentLoc],Coor{0,1});
      }
      auto distNextLocit = dist.find(nextLoc);
      pair<int,int> distNextLoc;
      if(distNextLocit == dist.end()){
        distNextLoc = pair<int,int>{K,INF};
      }
      else{
        distNextLoc = distNextLocit->second;
      }
      if(distNextLoc > newDist){
        dist.erase(nextLoc);
        if(distNextLoc != pair<int,int>{K,INF}){
          queue.erase(queue.find(tuple<int,int,Coor>{distNextLoc.first,distNextLoc.second,nextLoc}));
        }
        dist[nextLoc] = newDist;
        queue.insert(tuple<int,int,Coor>{newDist.first,newDist.second,nextLoc});
      }
    }
  }
  return (bestEnd == Coor{K+1,INF} ? -1 : bestEnd.second);
}

int main(){
  cin>>N>>M>>K;
  CAVE.resize(N);
  string line;
  for(int i = 0; i < N; i++){
    CAVE[i].resize(M);
    cin>>line;
    for(int j = 0; j < M; j++){
      if(line[j] == 'S'){
        START = Coor{j,i};
      }
      else if(line[j] == 'E'){
        END = Coor{j,i};
      }
      CAVE[i][j] = line[j];
    }
  }
  cout<<getMinDistance()<<endl;
}
