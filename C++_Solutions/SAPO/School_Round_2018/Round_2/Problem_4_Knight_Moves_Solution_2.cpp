#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Coor{
public:
  int x,y;
  Coor(const int& _x,const int& _y){
    x = _x;
    y = _y;
  }
  bool operator==(const Coor& other){
    return x==other.x && y == other.y;
  }
  Coor* operator+(const Coor& other){
    return new Coor(x+other.x,y+other.y);
  }
  bool contained(int width,int height){
    return 0<=x && x<width && 0<=y && y<height;
  }
  int distance(const Coor& other){
    int _x =(x-other.x);
    int _y =(y-other.y);
    return _x*_x + _y*_y;
  }
};

int main(int argc, char const *argv[]) {
  vector<Coor> offsets = {
    Coor(1,2),
    Coor(2,1),
    Coor(-1,2),
    Coor(-2,1),
    Coor(1,-2),
    Coor(2,-1),
    Coor(-1,-2),
    Coor(-2,-1),
  };
  Coor* start = new Coor(15,2);
  Coor* end = new Coor(99,99);
  int width = 100;
  int height = 100;
  vector<Coor*> searched = {start};
  vector<Coor*> current = {start};
  int dis = 0;
  while(find_if(searched.begin(),searched.end(),[end](const Coor*a){
    return *end == *a;
  }) == searched.end()){
    auto current_copy = current;
    current.erase(current.begin(),current.end());
    for(auto loc: current_copy){
      auto &cur = *loc;
      for(auto offset:offsets){
        Coor* n_place = cur+offset;
        if(n_place->contained(width,height) && find_if(searched.begin(),searched.end(),[n_place](const Coor*a){
          return *n_place == *a;
        }) == searched.end() && n_place->distance(*end) < max(4,cur.distance(*end))){
          searched.push_back(n_place);
          current.push_back(n_place);
        }
      }
    }
    dis += 1;
  }
  cout<<dis;
  return 0;
}
