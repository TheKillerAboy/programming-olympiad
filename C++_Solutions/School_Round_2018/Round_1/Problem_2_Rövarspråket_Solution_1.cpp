#include <iostream>
#include <string>

using namespace std;

string klinkers = "aeiou";

bool isConsonant(const char& let){
  return klinkers.find(let) == string::npos;
}

int main(int argc, char const *argv[]) {
  string word;
  cin>>word;

  string out = "";

  for(auto let:word){
    if(isConsonant(let)){
      out += let+'o'+let;
    }
    else{
      out += let;
    }
  }

  cout<<out;
  return 0;
}
