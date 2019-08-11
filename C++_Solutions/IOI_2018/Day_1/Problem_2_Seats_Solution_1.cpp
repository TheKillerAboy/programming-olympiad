#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Coor{
public:
  int x,y;
  Coor(int x, int y);
  Coor();
};

class Rect{
public:
  Coor leftTop,rightBottom;
  bool contains(Coor pos);
  Rect(int leftTop_x,int leftTop_y,int rightBottom_x,int rightBottom_y);
  Rect();
};

Coor::Coor(){
  x=0;
  y=0;
}
Coor::Coor(int x, int y){
  this->x=x;
  this->y=y;
}

bool Rect::contains(Coor pos){
  return (pos.x>=leftTop.x && pos.x<rightBottom.x)&&(pos.y>=leftTop.y && pos.y<rightBottom.y);
}
Rect::Rect(int leftTop_x,int leftTop_y,int rightBottom_x,int rightBottom_y){
  leftTop = Coor(leftTop_x,leftTop_y);
  rightBottom = Coor(rightBottom_x,rightBottom_y);
}
Rect::Rect(){
  leftTop = Coor(0,0);
  rightBottom = Coor(0,0);
}

class SegmentTreeNode{
public:
  vector<SegmentTreeNode*> children;
  Rect rect;
  bool isBeauty;

  SegmentTreeNode(Rect& rect_);

  void updateBeauty(vector<vector<int>>& order);
  int isBeautyCounter(int value);
  int size();
};

SegmentTreeNode::SegmentTreeNode(Rect& rect_){
  rect = rect_;
  children.reserve(4);
  if(rect.leftTop.x<rect.rightBottom.x && rect.leftTop.y<rect.rightBottom.y){
    int x_mid = (rect.leftTop.x+rect.rightBottom.x)>>1;
    int y_mid = (rect.leftTop.y+rect.rightBottom.y)>>1;
    Rect rec1 = Rect(rect.leftTop.x,x_mid,rect.leftTop.y,y_mid);
    Rect rec2 = Rect(x_mid,rect.rightBottom.x,rect.leftTop.y,y_mid);
    Rect rec3 = Rect(rect.leftTop.x,x_mid,y_mid,rect.rightBottom.y);
    Rect rec4 = Rect(x_mid,rect.rightBottom.x,y_mid,rect.rightBottom.y);
    children.push_back(new SegmentTreeNode(rec1));
    children.push_back(new SegmentTreeNode(rec2));
    children.push_back(new SegmentTreeNode(rec3));
    children.push_back(new SegmentTreeNode(rec4));
  }
  isBeauty = false;
}

int SegmentTreeNode::size(){
  return (rect.rightBottom.y-rect.leftTop.y)*(rect.rightBottom.x-rect.leftTop.x);
}

void SegmentTreeNode::updateBeauty(vector<vector<int>>& order){
  set<int> values;
  int mySize = size();
  for(int x = rect.leftTop.x; x< rect.rightBottom.x;x++){
    for(int y = rect.leftTop.y; y< rect.rightBottom.y;y++){
      values.insert(order[x][y]);
    }
  }
  isBeauty = mySize == values.size();
  for(auto value: values){
      if(!(0<= value&&value < mySize)){
        isBeauty = false;
        break;
      }
  }
  for(auto child : children){
    child->updateBeauty(order);
  }
}


int SegmentTreeNode::isBeautyCounter(){
  int output = isBeauty;
  for(auto child:children){
    output+=child->isBeautyCounter();
  }
  return output;
}

SegmentTreeNode* root;
vector<vector<int>*>* values;
int w,h;

give_initial_chart(int H, int W, int[] R, int[] C){
  values = new vector<vector<int>*>();
  root = new SegmentTreeNode(W,H);
  for(int i = 0; i < W; i++){
    values->push_back(new vector<int>())
    for(int j = 0; j < H; j++){
      *(values)[i]->push_back(0);
    }
  }
  int currentValue = 0;
  for(int i = 0; i < W; i++){
    for(int j = 0; j < H; j++){
      *(*(values)[C[i]])[R[j]] = currentValue++;
    }
  }
  root->updateBeauty(values);
  w=W;
  h=H;
}

int swap_seats(int a, int b){
  for(int i = 0; i < W; i++){
    for(int j = 0; j < H; j++){
      if(*(*(values)[i])[j])==a){
        *(*(values)[i])[j] = b;
      }
      else((*(*(values)[i])[j])==b){
        *(*(values)[i])[j] = a;
      }
    }
  }
  root->updateBeauty(values);
  return root->isBeautyCounter();
}
