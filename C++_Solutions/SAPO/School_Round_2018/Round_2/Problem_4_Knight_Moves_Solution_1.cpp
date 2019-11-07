#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

class Coor{
public:
  int x,y;

  Coor(int x,int y){
    this->x = x;
    this->y = y;
  }

  Coor(int value, int& width, int& height){
    x = value%width;
    y = value/width;
  }

  int toInt(int& width, int& height){
    return y*width+x;
  }

  Coor operator+(Coor other){
    return Coor(x+other.x,y+other.y);
  }

  bool operator==(Coor two){
    return x==two.x && y == two.y;
  }
  bool operator<(const Coor &two)const {
    if(two.y > y){
      return true;
    }
    else if(two.x > x){
      return true;
    }
    else{
      return false;
    }
  }
  bool in(int& width,int& height){
    return 0<=x && x<width && 0<=y && y<height;
  }
};

int main(int argc, char const *argv[]) {
  vector<Coor> knight_moves = {
  Coor(1,2),
  Coor(2,1),
  Coor(-1,2),
  Coor(-2,1),
  Coor(1,-2),
  Coor(2,-1),
  Coor(-1,-2),
  Coor(-2,-1)
};
  Coor start(15,2);
  Coor end(99,99);
  int width = 100;
  int height = 100;
  set<Coor> searched = {start};
  set<Coor> current = {start};
  int distance = 0;
  while(searched.find(end) == searched.end()){
    set<Coor> current_copy = current;
    current.clear();
    for(auto place:current_copy){
      for(auto offset:knight_moves){
        Coor n_place = place + offset;
        if(n_place.in(width,height) && searched.find(n_place) == searched.end()){
          searched.insert(n_place);
          current.insert(n_place);
        }
      }
    }
    distance++;
  }

  cout<<distance<<endl;

  return 0;
}
