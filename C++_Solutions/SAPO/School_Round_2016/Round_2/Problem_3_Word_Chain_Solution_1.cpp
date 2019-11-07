#include <iostream>
#include <vector>
#include <string>

using namespace std;

string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

class Chain{
public:
  vector<string> chain;
  string last;

  Chain(const string &last){
    chain = vector<string>(0);
    chain.push_back(last);
    this->last = last;
  }

  Chain(const vector<string> &prev,const string &last){
    this->last = last;
    chain = prev;
    chain.push_back(last);
  }

  bool contains(const string &word){
    for(string w:chain){
      if(word == w) return true;
    }
    return false;
  }
};

bool is_equv(const string& one, const string &two){
  int errors = 0;
  for (size_t i = 0; i < one.size(); i++) {
    if(errors > 1) return false;
    if(one[i] != two[i]) errors += 1;
  }
  return errors == 1;
}


bool alpha(const string& word, const string& next){
  for (size_t i = 0; i < word.size(); i++) {
    if(alphabet.find(word[i])<alphabet.find(next[i])) return false;
    else if(alphabet.find(word[i])>alphabet.find(next[i])) return true;
  }
  return false;
}
bool better(const Chain& best, const Chain& next){
  for (size_t i = 0; i < best.chain.size(); i++) {
    if(best.chain[i] != next.chain[i]) return alpha(best.chain[i],next.chain[i]);
  }
}

int main(int argc, char const *argv[]) {
  vector<string> words = {"WALL","TAIL","TALL","WALK","BALL","WAIL","TALK"};
  vector<Chain*> chains(0);
  for(auto word:words) chains.push_back(new Chain(word));
  for (size_t i = 0; i < words.size()-1; i++) {
    vector<Chain*> chains_copy = chains;
    chains.clear();
    for(Chain* _chain: chains_copy){
      Chain& chain = *_chain;
      for(string word:words){
        if(!chain.contains(word)){
          if(is_equv(word,chain.last)) chains.push_back(new Chain(chain.chain,word));
        }
      }
    }
  }
  Chain& best = *chains[0];
  for (size_t i = 0; i < chains.size(); i++) {
    if(better(best,*chains[i])) best = *chains[i];
  }
  if(chains.size() == 0) cout<<"IMPOSSIBLE";
  else{
    for(auto word:best.chain) cout<<word<<' ';
    cout<<endl;
  }
  return 0;
}
