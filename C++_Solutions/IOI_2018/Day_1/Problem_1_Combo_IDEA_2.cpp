#include<vector>
#include<string>

using namespace std;

int press(string S);

class groupSequance{
public:
  vector<string> group;

  groupSequance(const string sequance, const int N);
  groupSequance();
  void merge(groupSequance* otherGroup);

  static string equalivantSequances(const string seq1, const string seq2);
};

groupSequance::groupSequance(){;}

groupSequance::groupSequance(const string sequance, const int N){
  int length = sequance.size();
  for(int i = 0; i < length - 2; i++){
    char begin = sequance[i];
    string subSequance(1, begin);
    bool valid = true;
    for(int j = 1; j < N; j++){
      if(sequance[i+j] != begin){
        subSequance += sequance[i+j];
      }
      else{
        valid = false;
        break;
      }
    }
    if(valid){
      group.push_back(subSequance);
    }
  }
}

void groupSequance::merge(groupSequance* otherGroup){
  if(group.size() == 0){
    group.reserve(otherGroup->group.size());
    copy(otherGroup->group.begin(),otherGroup->group.end(),group.begin());
    return;
  }
  vector<string> replace;
  for(auto currentSequanceSelf : group){
    for(auto currentSequanceOther : otherGroup->group){
      string currentSequance = groupSequance::equalivantSequances(currentSequanceSelf,currentSequanceOther);
      if(currentSequance != "I"){
        replace.push_back(currentSequance);
      }
    }
  }
  group.clear();
  group.reserve(replace.size());
  copy(replace.begin(),replace.end(),group.begin());

  delete otherGroup;
}

string groupSequance::equalivantSequances(const string seq1, const string seq2){
  int sublength = min(seq1.size(),seq2.size());
  if(seq1.substr(sublength) == seq2.substr(sublength)){
    if(seq1.size() == sublength){
      return seq2;
    }
    return seq1;
  }
  return "I";
}

groupSequance* mainGroup = new groupSequance();

void pressMerge(const string sequance){
  groupSequance* newGroup = new groupSequance(sequance,press(sequance));
  mainGroup->merge(newGroup);
}

string guess_sequence(int N){

}
