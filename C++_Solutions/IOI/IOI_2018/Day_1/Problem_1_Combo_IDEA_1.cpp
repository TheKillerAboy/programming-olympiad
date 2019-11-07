#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#define Combos vector<string>

using namespace std;

string CHOOSES = "ABXY";

char random_letter(){
  return CHOOSES[rand()%4];
}

string guess_random_sequence(const int& size){
  string out = "";
  for(int i = 0; i < size; i++){
    out += random_letter();
  }
  return out;
}

string longer_combo(const string& one, const string& two){
  if(one.size()>two.size()){
    return one;
  }
  return two;
}

auto similare(const string& one, const string& two){
  int common = min(one.size(),two.size());
  return {one.substr(0,common)==two.substr(0,common),longer_combo(one,two)};
}

Combos merge_inclusive(const Combos& one, const Combos& two){
  Combos out;

}
