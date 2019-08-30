#include <set>
#include <vector>
#include <iostream>

using namespace std;

int leftCheck(vector<int>& as, int n, int l){
  set<int> values;
  for(int i = 0; i < l + 1; i++){
    if(values.find(as[i]) == values.end()){
      values.insert(as[i]);
    }
    else{
      return -1;
    }
  }
  for(int i = n; i > 0; --i){
    if(values.find(as[i]) == values.end()){
      values.insert(as[i]);
    }
    else{
      return i - l + 1;
    }
  }
  return -1;
}

int rightCheck(vector<int>& as, int n,int r){
  set<int> values;
  for(int i = n; i > r; --i){
    if(values.find(as[i]) == values.end()){
      values.insert(as[i]);
    }
    else{
      return -1;
    }
  }
  for(int i = 0; i < n; i++){
    if(values.find(as[i]) == values.end()){
      values.insert(as[i]);
    }
    else{
      return r - i + 1;
    }
  }
  return -1;
}

void assignOut(int& minOut, int value){
  if(value != -1){
    if(minOut == -1 || minOut > value){
      minOut = value;
    }
  }
}

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  vector<int> as(n);
  for(int i =0; i < n; i++){
    cin>>as[i];
  }

  int minOut = -1;

  int value;
  for(int i = 0; i < n; i++){
    value = leftCheck(as,n,i);
    if(value == -1){
      break;
    }
    assignOut(minOut, value);
  }
  for(int i = n; i > 0; --i){
    value = rightCheck(as,n,i);
    if(value == -1){
      break;
    }
    assignOut(minOut, value);
  }
  if(minOut == -1){
    minOut = 0;
  }
  cout<<minOut;
  return 0;
}
