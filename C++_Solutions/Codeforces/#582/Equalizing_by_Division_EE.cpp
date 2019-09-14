#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n,k;
  cin>>n>>k;
  vector<int> begining(n);
  for(int i = 0; i < n; i++){
    cin>>begining[i];
  }
  set<int> current;
  copy(begining.begin(),begining.end(),inserter(current,current.begin()));
  set<int> allValues = current;
  while(!current.empty()){
    for(auto value : current){
      current.erase(value);
      int next = value>>1;
      if(allValues.find(next) == allValues.end()){
        current.insert(next);
        allValues.insert(next);
      }
    }
  }
  for(auto value : allValues){
  printf("%i\n", value);
  }
}
