#include <iostream>
#include <map>
#include <set>

using namespace std;

void setCurrentSet(int& currentSetIndex, set<int>*& currentSet, map<int,set<int>*>& ropesMptoStr){
  currentSetIndex = (*ropesMptoStr.rbegin()).first;
  currentSet = (*ropesMptoStr.rbegin()).second;
}

bool removeFromSet(int& currentSetIndex, set<int>*& currentSet, map<int,set<int>*>& ropesMptoStr, int value){
  currentSet->erase(value);
  if(currentSet->empty()){
    ropesMptoStr.erase(currentSetIndex);
    return true;
  }
  return false;
}

int minMaxLength(map<int,set<int>*>& ropesMptoStr, int length){
  int currentSetIndex;
  set<int>* currentSet;
  setCurrentSet(currentSetIndex,currentSet,ropesMptoStr);
  int currentLength = *currentSet->rbegin();
  int minStrength = currentSetIndex;
  if(removeFromSet(currentSetIndex,currentSet,ropesMptoStr,currentLength)){setCurrentSet(currentSetIndex,currentSet,ropesMptoStr);}
  int total = currentLength;
  while(total < length){
    currentLength = *currentSet->lower_bound(length-total);
    minStrength = min(minStrength,currentSetIndex);
    if(removeFromSet(currentSetIndex,currentSet,ropesMptoStr,currentLength)){setCurrentSet(currentSetIndex,currentSet,ropesMptoStr);}
    total+=currentLength;
  }
  return minStrength;
}

int main(int argc, char const *argv[]) {
  int n,l;
  cin>>n>>l;
  map<int,set<int>*> ropesMptoStr;
  int strength, length;
  for(int i = 0; i < n; i++){
    cin>>length>>strength;
    if(ropesMptoStr.find(strength) == ropesMptoStr.end()){
      ropesMptoStr[strength] = new set<int>{length};
    }
    else{
      ropesMptoStr[strength]->insert(length);
    }
  }
  cout<<minMaxLength(ropesMptoStr,l)+minMaxLength(ropesMptoStr,l)<<endl;
  return 0;
}
