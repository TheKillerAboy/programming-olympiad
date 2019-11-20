#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

using namespace std;


class Node{
public:
  vector<bool> links;
  Node(string nodes);
  bool has(int i);
};

map<int,Node*> nodes;

bool charToBool(char car){
  if(car == '1'){
    return true;
  }
  return false;
}

Node::Node(string nodes){
  links.reserve(nodes.size());
  for(auto let:nodes){
    links.push_back(charToBool(let));
  }
}
bool Node::has(int i){
  return links[i];
}

bool pathWorks(list<int>& path){
  for(auto it = path.begin(); it != path.end(); it++){
    if((++it)!=path.end()){
      if(!nodes[*(--it)]->has(*(++it))){
        return false;
      }
    }
  }
  return true;
}

int main(){
  int nodesAmount;
  cin>>nodesAmount;
  string line;
  for(int i = 0; i < nodesAmount;i++){
    cin>>line;
    nodes[i] = new Node(line);
  }
  list<list<int>> paths;
  list<int> firstPath;
  int firstPathSize;
  cin>>firstPathSize;
  int nodeNum;
  for(int i = 0; i < firstPathSize; i++){
    cin>>nodeNum;
    firstPath.push_back(nodeNum);
  }
  paths.push_back(firstPath);
  list<list<int>> paths_copy;
  while(paths.size() > 1){
    paths_copy.clear();
    copy(paths.begin(),paths.end(),back_inserter(paths_copy));
    paths.clear();
    for(auto path : paths_copy){
      for(auto it = path.begin(); it!= path.end(); it++){
        list<int> path_copy;
        copy(path.begin(),path.end(),back_inserter(path_copy));
        path_copy.erase(it);
        if(pathWorks(path_copy)){
          paths.push_back(path_copy);
        }
      }
    }
  }
  for(auto pos : paths_copy.front()){
    cout<<pos<<' ';
  }
}
