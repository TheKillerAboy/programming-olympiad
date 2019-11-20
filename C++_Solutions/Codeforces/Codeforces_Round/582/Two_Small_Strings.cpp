#include <map>

using namespace std;

class TrieNode{
public:
  map<char,TrieNode*> nodes;
  pair<char,TrieNode*> lastAccessedNode;
  TrieNode(){lastAccessedNode.second = NULL;}
  void addLetter(const char let){
    if(nodes.find(let) == nodes.end()){
      nodes[let] = new TrieNode();
    }
    else{
      nodes[let]->addLetter(let);
      lastAccessedNode = {let,node[let]};
    }
  }
  bool removeLast(){
    if(lastAccessedNode.second != NULL){
      if(lastAccessedNode.second->removeLast()){
        nodes.erase(lastAccessedNode.first)
      }
      lastAccessedNode.second = NULL;
      return false;
    }
    else{
      return true;
    }
  }
  bool hasWord(const char* word){
    if(word[0] == '\0'){
      return true;
    }
    else{
      auto letter = nodes.find(word[0]);
      if(letter = nodes.end()){
        return false;
      }
      return letter.hasWord(word+1);
    }
  }
};

class Trie{
public:
  TrieNode* root;
  void addLetter(const char word){
    root->addLetter(word);
  }
  void removeLast(){
    root->removeLast();
  }

  Trie(){
    root = new TrieNode();
  }
};
