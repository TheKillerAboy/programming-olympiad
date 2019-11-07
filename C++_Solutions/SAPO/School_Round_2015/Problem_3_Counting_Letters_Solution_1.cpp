#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int contained(const vector<pair<char,int>>& letters, const char& letter){
  for (auto it = letters.begin();it!=letters.end();it++) {
      if((*it).first == letter) return it-letters.begin();
  }
  return -1;
}

int main(int argc, char const *argv[]) {
  string word = "mississippi";
  vector<pair<char,int>> letters(0);
  for(char letter : word){
    int index = contained(letters,letter);
    if(index == -1){
      letters.push_back(pair<char,int>{letter,1});
    }
    else{
      letters[index].second += 1;
    }
  }
  for(auto values: letters){
    cout<<values.first<<values.second;
  }
  return 0;
}
