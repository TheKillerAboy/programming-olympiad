#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <array>

using namespace std;

typedef int Coor;
typedef pair<int,int> LocProp;

#define DIS first
#define DYS second

#define INF 999999

int N,M,K;
string CAVE;

Coor START,END;

bool inBound(Coor a){
  return 0<=a && a < M*N;
}

vector<Coor> adjacent(Coor a){
  vector<Coor> out;
  out.reserve(4);
  if(a%M != 0){
    out.push_back(a-1);
  }
  if(a%M != M-1){
    out.push_back(a+1);
  }
  if(inBound(a+M)){
    out.push_back(a+M);
  }
  if(inBound(a-M)){
    out.push_back(a-M);
  }
  return out;
}

char getLoc(Coor a){
  return CAVE[a];
}

int minDistance(){
  set<pair<LocProp,Coor>> queue;
  vector<map<int,int>> dist(N*M);

  queue.insert({LocProp{0,0},START});
  dist[START][0] = 0;

  LocProp curProp;
  int curDis, curDyn, curLoc;

  while(!queue.empty()){
    tie(curProp,curLoc) = *queue.begin();
    tie(curDis,curDyn) = curProp;

    queue.erase(queue.begin());

    for(Coor nextLoc : adjacent(curLoc)){
      int nextDyn = getLoc(nextLoc) == '#' ? curDyn + 1 : curDyn;
      if(nextDyn > K){continue;}

      int nextDis = INF;
      if(dist[nextLoc].find(nextDyn) != dist[nextLoc].end()){
        nextDis = dist[nextLoc][nextDyn];
      }
      if(nextDis > curDis + 1){
        if(nextDis != INF){
          queue.erase(queue.find({LocProp{nextDis,nextDyn},nextLoc}));
        }
        dist[nextLoc][nextDyn] = curDis + 1;
        queue.insert({LocProp{curDis + 1,nextDyn},nextLoc});
      }
    }
  }
  int minDis = INF;
  for(auto keyValue : dist[END]){
    minDis = min(minDis,keyValue.second);
  }
  return minDis == INF ? -1 : minDis;
}

int main(){
  cin>>N>>M>>K;
  string line;
  for(int i = 0; i < N; i++){
    cin>>line;
    for(int j = 0; j < M; j++){
      if(line[j] == 'S'){
        START = i*M+j;
      }
      else if(line[j] == 'E'){
        END = i*M+j;
      }
    }
    CAVE+=line;
  }

  printf("%i\n", minDistance());

  return 0;
}
