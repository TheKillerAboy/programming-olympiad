#include <map>
#include <vector>
#include <iostream>

using namespace std;

int fix(string word){
  if(word.length() == 0){
    return 0;
  }
  else if(word.length() == 1){
    return 1;
  }
  int current = 0;
  int out = 0;
  for(int i = 1; i < word.length(); i++){
    if(i!=current && word[i] == word[current]){
      out += fix(word.substr(current+1,i-current-1));
      current = i + 1;
    }
  }
  if(current != word.length()){
    out++;
    if(current < word.length() - 1){
      out+=fix(word.substr(current+1));
    }
  }
  return out;
}

int main(){
  string word;
  cin>>word;
  cout<<fix(word);

  return 0;
}
