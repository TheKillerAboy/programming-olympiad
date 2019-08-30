#include <vector>
#include <list>
#include <iostream>

using namespace std;

vector<int>* copy_append(vector<int>* seq, int value){
  vector<int>* seq_copy = new vector<int>();
  copy(seq->begin(),seq->end(),back_inserter(*seq_copy));
  seq_copy->push_back(value);
  return seq_copy;
}

void next(list<vector<int>*>& current, int a, int b){
  list<vector<int>*> current_copy;
  copy(current.begin(),current.end(),back_inserter(current_copy));
  current.erase(current.begin(),current.end());
  for(auto seq:current_copy){
    if(seq->back()<=a){
      current.push_back(copy_append(seq,a));
    }
    if(seq->back()<=b){
      current.push_back(copy_append(seq,a));
    }
    delete seq;
  }
}

int main(){
  list<vector<int>*> current;
  int q,a,b;
  cin>>q;
  cin>>a>>b;
  current.push_back(new vector<int>{a});
  current.push_back(new vector<int>{b});
  for(int i = 0; i < q - 1; i ++){
    cin>>a>>b;
    next(current,a,b);
  }
  cout<<2*q-current.size();
}
