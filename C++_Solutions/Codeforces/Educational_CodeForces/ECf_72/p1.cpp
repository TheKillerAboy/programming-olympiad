#include <iostream>
#include <cmath>

using namespace std;

int many(int str, int inte, int exp){
  if(inte - str >= exp){
    return 0;
  }
  else{
    if(inte - str > -1){
      exp -= inte - str + 1;
      str += inte - str + 1;
    }
    // for(int s = str; s <= str+exp; s++){
    //   if(inte+exp - (s - str) < s){
    //     out++;
    //   }
    // }
    int move = floor((float)(str-inte+exp)/2);
    return inte + move == str + exp - move ? move - 1 : move;
  }
}

int main(){
  int q;
  cin>>q;
  int str,inte,exp;
  for(int i = 0; i < q; i++){
    cin>>str>>inte>>exp;
    cout<<many(str,inte,exp)<<endl;
  }
}
