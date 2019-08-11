#include <string>

#include "combo.h"

using namespace std;

string guess_sequence(int N){
  string allPos = "ABXY";
  string sequance;
  int index = 0;
  while(true){
    sequance = allPos[index++];
    if(press(sequance) == 1)
      break;
  }
  allPos.erase(allPos.find(sequance));
  int currentSize = 1;
  while(currentSize<N){
    int newSize = press(sequance+allPos[0]+sequance+allPos[1]+allPos[0]+sequance+allPos[1]+allPos[1]+sequance+allPos[1]+allPos[2]);
    if(newSize == currentSize){
      sequance+=allPos[2];
    }
    else if (newSize == currentSize+1){
      sequance+=allPos[0];
    }
    else{
      sequance+=allPos[1];
    }
    currentSize++;
  }
  return sequance;
}
