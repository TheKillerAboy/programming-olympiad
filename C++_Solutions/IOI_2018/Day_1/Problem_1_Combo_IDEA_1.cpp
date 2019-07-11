#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

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



bool similar(const string& first, const string& second){
  int similar_length = min(first.size(),second.size());
  return  first.substr(0,similar_length) == second.substr(0,similar_length);
}

string shorter(const string& first, const string& second){
  if(first.size()<second.size()){
    return first;
  }
  return second;
}

void filter_self(vector<string> pos){
  int length = pos.size();
  vector<string> replace;
  for(int i = 0; i< length - 1; i++){
    bool has_similar = false;
    for(int j = i + 1; j< length;j++){
      if(similar(pos[i],pos[j])){
        has_similar = true;
        break;
      }
    }
    if(has_similar){

    }
  }
}

vector<string> possible_candidates(const string& p, const int& currect){
  vector<string> all,copyall,out;
  int length = p.size();

  all.push_back(&p[0]);

  for(int i = 1; i < length;i++){
    copyall = copy(all,all.begin(),all.end());
    all.clear();
    for(int j = 0; j < copyall.size(); j++){
      if(p[i] != copyall[j][0]){
        all.push_back(copyall[j]+p[i]);
        if(copyall[j].size() == currect - 1){
          out.push_back(copyall[j]+p[i]);
        }
      }
    }
    all.push_back(p[i]);
    allcopy.clear();
  }

  return out;
}

void filter(vector<string> allpos; vector<string> newpos){
  auto copyallpos = copy(allpos, allpos.begin(),allpos.end());
  allpos.clear();
  for(auto sequance: copyallpos){
    for(auto seq: all){
      if(similar(seq,sequance)){
        allpos.push_back(shorter(sequance,s));
        break;
      }
    }
  }
}

string guess_sequence(int N){
  vector<string> allpos;


}

int main(int argc, char const *argv[]) {


  return 0;
}
