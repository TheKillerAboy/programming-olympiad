#include <string>
#include <iostream>

using namespace std;

int isSubString(string s, string t){
  if(s.size()<t.size()){
    return false;
  }
  for(int i = 0; i < s.size(); i++){
    for(int j = i; j < i + t.size() + 1; j++){
      if(j == i + t.size()){
        return true;
      }
      if(t[j-i] != s[j]){
        break;
      }
    }
  }
  return false;
}

int main(int argc, char const *argv[]) {
  string s,t;
  cin>>s>>t;
  int currentSize = 0;
  for(int size = s.size(); size > 0; size--){
    for(int pos = 0; pos <= s.size() - size; pos++){
      if(isSubString(s.substr(0,pos)+s.substr(pos+size),t)){
        cout<<size<<endl;
        return 0;
      }
    }
  }
  cout<<currentSize<<endl;
  return 0;
}
