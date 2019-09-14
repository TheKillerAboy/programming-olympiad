#include <iostream>
#include <utility>
#include <map>
#include <memory>
#include <vector>

using namespace std;

typedef pair<int,int> Coor;

#define X first
#define Y second

const int INF = 999999;

int alignerIndex(Coor a, bool aligner){
  if(aligner){
    return a.Y;
  }
  return a.X;
}

int distance(Coor a, Coor b){
  return max(abs(a.X-b.X),abs(a.Y-b.Y));
}

struct D2Node{
  Coor value;
  bool myAligner;
  unique_ptr<D2Node> leftChild;
  unique_ptr<D2Node> rightChild;

  D2Node(Coor a, bool aligner){
    value = a;
    myAligner = aligner;
  }

  void push(Coor newValue, bool aligner){
    unique_ptr<D2Node>* push_toP;
    if(alignerIndex(newValue,aligner) >= alignerIndex(value,aligner)){
      push_toP = &rightChild;
    }
    else{
      push_toP = &leftChild;
    }
    unique_ptr<D2Node>& push_to = *push_toP;
    if(push_to){
      push_to->push(newValue,aligner+1);
    }
    else{
      push_to = unique_ptr<D2Node>(new D2Node(newValue,aligner));
    }
  }

  static Coor distanceMinReturnCoor(Coor s, Coor a, Coor b){
    if(distance(s,a)<distance(s,b)){
      return a;
    }
    return b;
  }

  Coor nearest(Coor a){
    if(a == value){
      return value;
    }
    if(!rightChild && !leftChild){
      return value;
    }
    unique_ptr<D2Node>* push_toP;
    if(!rightChild){
      push_toP = &leftChild;
    }
    else if(!leftChild){
      push_toP = &rightChild;
    }
    else if(distance(rightChild->value,a) < distance(leftChild->value,a)){
      push_toP = &rightChild;
    }
    else{
      push_toP = &leftChild;
    }
    unique_ptr<D2Node>& push_to = *push_toP;
    return distanceMinReturnCoor(a,value,push_to->nearest(a));
  }
  Coor findMin(int aligner){
    Coor minLoc = {INF,INF};
    if(leftChild){
      Coor leftLoc = leftChild->findMin(aligner);
      if(alignerIndex(leftLoc,aligner) < alignerIndex(minLoc,aligner)){
        minLoc = leftLoc;
      }
    }
    if(rightChild){
      Coor rightLoc = rightChild->findMin(aligner);
      if(alignerIndex(rightLoc,aligner) < alignerIndex(minLoc,aligner)){
        minLoc = rightLoc;
      }
    }
    if(alignerIndex(value,aligner) < alignerIndex(minLoc,aligner)){
      minLoc = value;
    }
    return minLoc;
  }
  static D2Node* deleteD2(D2Node* root,Coor a, bool aligner){
    if(root == NULL){
      return NULL;
    }
    if(root->value == a){
      if(root->rightChild){
        Coor minLoc = root->rightChild->findMin(aligner);
        root->value = minLoc;
        root->rightChild = unique_ptr<D2Node>(deleteD2(root->rightChild.release(),minLoc,aligner+1));
      }
      else if(root->leftChild){
        Coor minLoc = root->leftChild->findMin(aligner);
        root->value = minLoc;
        root->leftChild = unique_ptr<D2Node>(deleteD2(root->leftChild.release(),minLoc,aligner+1));
      }
      else{
        delete root;
        return NULL;
      }
      return root;
    }
    if(alignerIndex(a,aligner) >= alignerIndex(root->value,aligner)){
      root->rightChild = unique_ptr<D2Node>(deleteD2(root->rightChild.release(),a,aligner+1));
    }
    else{
      root->leftChild = unique_ptr<D2Node>(deleteD2(root->leftChild.release(),a,aligner+1));
    }
    return root;
  }
  void print(string tabber){
    cout<<tabber;
    printf("(%i, %i)\n", value.X,value.Y);
    if(leftChild){
      cout<<tabber<<"L:"<<endl;
      leftChild->print(tabber+'\t');
    }
    if(rightChild){
      cout<<tabber<<"R:"<<endl;
      rightChild->print(tabber+'\t');
    }
  }
};

struct D2Tree{
  unique_ptr<D2Node> root;
  D2Tree(){;}
  void push(Coor a){
    if(root){
      root->push(a,0);
    }
    else{
      root = unique_ptr<D2Node>(new D2Node(a,0));
    }
  }
  Coor nearest(Coor a){
    if(root){
      return root->nearest(a);
    }
    return {-1,-1};
  }
  void deleteD2(Coor a){
    root = unique_ptr<D2Node>(D2Node::deleteD2(root.release(),a,0));
  }
  void print(){
    if(root){
      root->print("");
    }
  }
};


map<Coor,int> amountInCell;
D2Tree cellsWithStones;

int get_rocks(Coor a, int amount){
  int out = 0;
  int count = 0;
  for(auto keyValue : amountInCell){
    count += keyValue.second;
    if(count >= amount){
      break;
    }
  }
  if(count < amount){
    return -1;
  }
  vector<pair<Coor,int>> removed;
  pair<Coor,int> changed = {Coor{-1,-1},-1};
  while(amount > 0){
    Coor nearestCoor = cellsWithStones.nearest(a);
    int rocks = amountInCell[nearestCoor];
    if(amount >= rocks){
      amount -= rocks;
      out += 2*rocks*distance(a,nearestCoor);
      removed.push_back(*amountInCell.find(nearestCoor));
      amountInCell.erase(nearestCoor);
      cellsWithStones.deleteD2(nearestCoor);
    }
    else{
      out += 2*rocks*distance(a,nearestCoor);
      changed = *amountInCell.find(nearestCoor);
      amountInCell[nearestCoor] -= amount;
      amount = 0;
    }
  }
  for(auto keyValue : removed){
    amountInCell[keyValue.first] = keyValue.second;
    cellsWithStones.push(keyValue.first);
  }
  if(changed.Y != -1){
    amountInCell[changed.first] = changed.second;
  }
  return out;
}

void update_cells(Coor a, int amount){
  if(amountInCell.find(a) != amountInCell.end()){
    if(amount > 0){
      amountInCell[a] = amount;
    }
    else{
      amountInCell.erase(a);
      cellsWithStones.deleteD2(a);
    }
  }
  else{
    if(amount > 0){
      amountInCell[a] = amount;
      cellsWithStones.push(a);
    }
  }
}

int main(){
  int N,M,Q;
  cin>>N>>M>>Q;
  int cell;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cin>>cell;
      if(cell>0){
        update_cells({j,i},cell);
      }
    }
  }
  int q,a,b,K;
  for(int i = 0; i < Q; i++){
    cin>>q>>a>>b>>K;
    if(q == 0){
      cout<<get_rocks({b,a},K)<<endl;
    }
    else{
      update_cells({b,a},K);
    }
  }
}
