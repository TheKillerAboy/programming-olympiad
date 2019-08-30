#include <string>
#include <iostream>

using namespace std;

bool charToBool(char val){
  if(val == '1'){
    return 1;
  }
  return 0;
}

long long int binaryToInt(string binary){
  long long int out = 0;
  size_t length = binary.size();
  long long int multi = 1;
  for(int i = length-1;i>=0;i--){
    out+= multi*charToBool(binary[i]);
    multi *= 2;
  }
  return out;
}

int main(){
  string binary;
  cin>>binary;
  auto value = (float)binaryToInt(binary);
  int counter = 0;
  while(value > 1){
    counter+=1;
    value /= 4;
  }
  cout<<counter;
}
