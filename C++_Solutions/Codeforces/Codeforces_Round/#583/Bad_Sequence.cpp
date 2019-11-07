#include <iostream>

using namespace std;

int main(){
  int size;
  cin>>size;
  string brackets;
  cin>>brackets;
  int counter = 0;
  for(int i = 0; i < brackets.length(); i++){
    if(brackets[i] == ')'){
      counter--;
    }
    else{
      counter++;
    }
    if(counter < -1){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  if(counter != 0){
    cout<<"NO"<<endl;
  }
  else{
    cout<<"YES"<<endl;
  }
  return 0;
}
