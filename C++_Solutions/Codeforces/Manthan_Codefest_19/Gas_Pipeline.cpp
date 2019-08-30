#include <vector>

using namespace std;

class PipeLine{
public:
  int currentCost;
  bool level;
};

vector<PipeLine*> getMin(vector<PipeLine*>& current){
  PipeLine* minTop = NULL;
  PipeLine* minBottom = NULL;
  for(auto pipeline : current)
  {
    if(pipeline->level == 1){
      if(minTop == NULL){
        minTop = pipeline;
      }
      else if(pipeline->currentCost<minTop->currentCost){
        minTop = pipeline;
      }
    }
    else{
      if(minBottom == NULL){
        minBottom = pipeline;
      }
      else if(pipeline->currentCost<minBottom->currentCost){
        minBottom = pipeline;
      }
    }
  }
  return vector<PipeLine*>{minTop,minBottom};
}
