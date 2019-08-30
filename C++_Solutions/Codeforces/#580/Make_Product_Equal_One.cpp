#include <iostream>

using namespace std;

int main(){
  int size;
  cin >> size;

  int negs = 0;

  long long int operations = 0;

  bool hasZero = false;

  long long int val;

  for(int i = 0; i < size; i++){
    cin>>val;
    if(val < 0){
      operations += -val - 1;
      negs += 1;
      negs %= 2;
    }
    else if (val > 0){
      operations += val - 1;
    }
    else{
      operations+=1;
      hasZero = true;
    }
  }

  if(negs == 1 && !hasZero){
    operations+=2;
  }

  cout<<operations<<endl;

  return 0;
}
