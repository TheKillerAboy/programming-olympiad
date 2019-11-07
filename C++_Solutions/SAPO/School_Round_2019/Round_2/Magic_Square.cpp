#include <iostream>
#include <set>

using namespace std;

int getValue(int* arr, int n, int i, int j){
  return arr[n*i+j];
}
void setValue(int* arr, int n, int i, int j, int value){
  arr[n*i+j] = value;
}

int getRow(int* arr, int n, int i_){
  int sum = 0;
  for(int i = 0; i < n; i++){
    sum+=getValue(arr,n,i_,i);
  }
  return sum;
}
int getColumn(int* arr, int n, int j_){
  int sum = 0;
  for(int j = 0; j < n; j++){
    sum+=getValue(arr,n,j,j_);
  }
  return sum;
}

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  int* arr = new int[n*n];
  int cur;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin>>cur;
      setValue(arr,n,i,j,cur);
    }
  }

  int* columns = new int[n];
  int* rows = new int[n];
  bool isSquare = true;
  int wrong_c = 0;
  int wrong_r = 0;
  int lastWrong_c;
  int lastWrong_r;
  int correct = getColumn(arr,n,0);
  set<int> values;

  for(int i = 0; i < n; i++){
    columns[i] = getColumn(arr,n,i);
    rows[i] = getRow(arr,n,i);
    if(values.find(columns[i]) == values.end()){
      values.insert(columns[i]);
    }
    if(values.find(rows[i]) == values.end()){
      values.insert(rows[i]);
    }
    if(columns[i] != correct){
      if(columns[i] != rows[i]){
        isSquare = false;
      }
      wrong_c += 1;
      lastWrong_c = i;
      if(wrong_c>n/2){
        wrong_c = wrong_c-n/2;
        correct = columns[i];
      }
    }
    if(rows[i] != correct){
      wrong_r += 1;
      lastWrong_r = i;
      if(wrong_r>n/2){
        wrong_r = wrong_r-n/2;
        correct = columns[i];
      }
    }
  }

  if(isSquare){
    printf("MAGIC");
  }
  else if(wrong_c == 1 && wrong_r == 1 && values.size() == 2){
    if(columns[lastWrong_c] == rows[lastWrong_r]){
      for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
          if(i != lastWrong_c && j != lastWrong_r){
            printf("ALMOST MAGIC\n%i %i %i",lastWrong_c,lastWrong_r,getValue(arr,n,i,j));
            return 0;
          }
        }
      }
    }
  }
  else{
    printf("NOT MAGIC");
  }


  return 0;
}
