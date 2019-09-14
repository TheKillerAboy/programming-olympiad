#include <set>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

bool getPosition(bool* island, int m, pair<int,int> current){
  return island[(current.first-1)*m + current.second-1];
}

bool inBound(int n, int m, pair<int,int> current){
  return 0<current.first && current.first<=n && 0<current.second && current.second<=m;
}

vector<pair<int,int>> nextLoc(pair<int,int> current){
  vector<pair<int,int>> out;
  for(int i = -1; i < 2; i++){
    for(int j = -1; j < 2; j++){
      if(i!=j && -i!=j){
        out.push_back(pair{current.first+i,current.second + j});
      }
    }
  }
  return out;
}

void printCoor(pair<int,int> cur){
    cerr<<cur.first<<' '<<cur.second<<endl;
}

bool hasPath(pair<int,int> start, int n, int m, bool* island){
  set<pair<int,int>> all = {start};
  set<pair<int,int>> current = {start};
  set<pair<int,int>> current_copy;

  pair<int,int> end = {n,m};

  while(!current.empty() && *current.rbegin() != end){
    current_copy.clear();
    copy(current.begin(),current.end(),inserter(current_copy,current_copy.begin()));
    current.clear();
    for(auto loc : current_copy){
      for(auto next_loc: nextLoc(loc)){
        if(all.find(next_loc) == all.end() && current.find(next_loc) == current.end()){
          if(inBound(n,m,next_loc) && getPosition(island,m,next_loc)){
            current.insert(next_loc);
            all.insert(next_loc);
          }
        }
      }
    }
  }
  return !current.empty();
}

int main(){
  int n,m;
  cin>>n>>m;
  bool island[n*m];
  string line;
  for(int i = 0; i < n; i++){
    cin>>line;
    for(int j = 0; j < m; j++){
      island[i*m + j] = line[j] == '.';
    }
  }
  int out = 0;
  if(inBound(n,m,{1,2}) && getPosition(island,m,{1,2})){
    if(hasPath({1,2},n,m,island)){
      out += 1;
    }
  }
  if(inBound(n,m,{2,1}) && getPosition(island,m,{2,1})){
    if(hasPath({2,1},n,m,island)){
      out += 1;
    }
  }
  int out2 = (inBound(n,m,{n-1,m}) ? getPosition(island,m,{n-1,m}) : 0) + (inBound(n,m,{n,m-1}) ? getPosition(island,m,{n,m-1}) : 0);
  cout<<min(out,out2)<<endl;
}
