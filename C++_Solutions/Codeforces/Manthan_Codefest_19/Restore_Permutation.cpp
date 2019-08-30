#include <iostream>
#include <vector>

using namespace std;

int MIN(int a, int b){
  if(b == -1){
    return a;
  }
  else if( a== -1){
    return b;
  }
  else if(a<b){
    return a;
  }
  return b;
}
int MAX(int a, int b){
  if(b == -1){
    return a;
  }
  else if( a== -1){
    return b;
  }
  else if(a<b){
    return b;
  }
  return a;
}

class SegmentNode{
public:
  int min, max, value;
  SegmentNode* leftChild;
  SegmentNode* rightChild;

  SegmentNode(int value_, int min_, int max_){
    leftChild = NULL;
    rightChild = NULL;
    min = min_;
    max = max_;
    value = value_;
  }

  static SegmentNode* createSegment(vector<int>& start, int min, int max){
    if(max < min){
      return NULL;
    }
    int mid = (min+max)>>1;
    SegmentNode* current = new SegmentNode(0,min,max);

    if(min == max){
      current->value = start[min];
    }
    else{
      current->leftChild = createSegment(start,min,mid);
      current->rightChild = createSegment(start,mid+1,max);
      current->value = MIN(current->leftChild->value,current->rightChild->value);
    }

    return current;
  }
  int getMin(int minR, int maxR){
    if(min>=minR && max<=maxR){
      return value;
    }
    else if(max<minR || min>maxR){
      return -1;
    }
    else{
      return MIN(leftChild->getMin(minR,maxR),rightChild->getMin(minR,maxR));
    }
  }
  void updateSegment(int minR, int maxR, int val){
    if(max<minR || min>maxR){
      return;
    }
    if(min>=minR && max<=maxR){
      if(min == max){
        if(value != -1){
          value += val;
        }
      }
    }
    if(min != max){
      leftChild->updateSegment(minR,maxR,val);
      rightChild->updateSegment(minR,maxR,val);
      value = MIN(leftChild->value,rightChild->value);
    }
  }
  int rightMostZero(){
    if(value == 0){
      if(min == max){
        return min;
      }
      else{
        return MAX(leftChild->rightMostZero(),rightChild->rightMostZero());
      }
    }
    return -1;
  }
};

class SegmentTree{
public:
  SegmentNode* root;
  SegmentTree(vector<int>& start, int& n){
    root = SegmentNode::createSegment(start,0,n-1);
  }
  int getMin(int min, int max){
    return root->getMin(min,max);
  }
  void updateSegment(int min, int max, int value){
    root->updateSegment(min,max,value);
  }
  int rightMostZero(){
    return root->rightMostZero();
  }
};

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  vector<int> Ss(n);
  for(int i = 0; i < n; i++){
    cin>>Ss[i];
  }

  SegmentTree myTree(Ss,n);
  vector<int> out(n);
  for(int i = 1; i <= n; i++){
    int last = myTree.rightMostZero();
    if(last == -1){
      myTree.updateSegment(0,n-1,-myTree.getMin(0,n-1));
      last = myTree.rightMostZero();
    }
    cout<<last<<' '<<i<<endl;
    out[last] = i;
    myTree.updateSegment(last,n-1,-1);
  }
  for(int i = 0; i < n; i++){
    cout<<out[i]<<' ';
  }
  return 0;
}
