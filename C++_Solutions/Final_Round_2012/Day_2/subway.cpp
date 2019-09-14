#include <string>
#include <set>
#include <iostream>
#include <stack>
#include <map>

using namespace std;


map<int,set<int>> constructTree(string path){
  map<int,set<int>> out;
  int counter = 0;
  stack<int> prev;
  prev.push(0);
  for(int i = 0; i < path.length(); i++){
    if(path[i] == '0'){
      int newNode = ++counter;
      out[prev.top()].insert(newNode);
      out[newNode].insert(prev.top());
      prev.push(newNode);
    }
    else{
      prev.pop();
    }
  }
  return out;
}

void allPaths(set<string>& insertSet, int neededSize, map<int,set<int>>& Tree, int currentNode, set<int> currentPath,stack<int> currentStack, string currentString){
  if(currentString.length() == neededSize){
    insertSet.insert(currentString);
  }
  else{
    for(auto child:Tree[currentNode]){
      if(currentPath.find(child) == currentPath.end()){
        auto childPath = currentPath;
        childPath.insert(child);
        auto childStack = currentStack;
        childStack.push(currentNode);
        auto childString = currentString + '0';
        allPaths(insertSet,neededSize,Tree,child,childPath,childStack,childString);
      }
      else if(currentStack.top() == child){
        auto childStack = currentStack;
        childStack.pop();
        auto childString = currentString + '1';
        allPaths(insertSet,neededSize,Tree,child,currentPath,childStack,childString);
      }
    }
  }
}


int main(){
  set<string> paths;
  int n;
  cin>>n;
  string cur;
  int uqi = 0;
  for(int i = 0; i < n; i++){
    cin>>cur;
    if(paths.find(cur) == paths.end()){
      auto tree = constructTree(cur);
      for(auto node : tree){
        stack<int> mystack;
        mystack.push(node.first);
        allPaths(paths,cur.length(),tree,node.first,{node.first},mystack,"");
      }
      cerr<<endl;
      for(auto path: paths){
        cerr<<path<<endl;
      }
      cerr<<endl;
      uqi++;
    }
  }
  cout<<uqi<<endl;
}
