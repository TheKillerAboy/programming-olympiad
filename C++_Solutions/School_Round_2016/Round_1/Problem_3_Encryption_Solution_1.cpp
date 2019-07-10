#include <iostream>

using namespace std;

string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char Shift(const char& let,const int& N){
  return alphabet[(alphabet.find(let)+N)%26];
}

int main(int argc, char const *argv[]) {

  string word;
  int N;
  cout<<"Word?";
  cin>>word;
  cout<<"N?";
  cin>>N;
  int len = word.size();

  string out = "";
  for(int i = len - N;i<len;i++){
    out+= word[i];
  }
  for(int i = 0;i < len - N; i++){
    out+=Shift(word[i],N);
  }
  for(int i = 0;i<N;i++){
    out[i] = Shift(out[i],N);
  }

  cout<<out;

  return 0;
}
