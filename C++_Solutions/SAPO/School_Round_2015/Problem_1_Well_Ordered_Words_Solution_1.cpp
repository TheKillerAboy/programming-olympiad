#include <iostream>
#include <string>

using namespace std;

string alphabet = "abcdefghijklmnopqrstuvwxyz";

bool well(const string& word){
  for (size_t i = 0; i < word.size()-1; i++) {
    if(alphabet.find(word[i])>alphabet.find(word[i+1])) return false;
  }
  return true;
}

int main(int argc, char const *argv[]) {
  string word = "all";
  if(well(word)) cout<<"True";
  else cout<<"False";
  return 0;
}
