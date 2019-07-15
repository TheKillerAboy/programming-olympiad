#include <utility>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

int nCk( int n, int k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

class AllValues{
public:
  vector<shared_ptr<pair<int,int>>> values;

  void add_value(const int& value);
  int value_index(const int& value);
  int get_value_amount(const int& value);
  AllValues(const int& start);

  vector<shared_ptr<vector<pair<int,int>>>> get_flow();
  int calculate_possible_factors();

  void print_factors();
};

void AllValues::add_value(const int& value){
  int vIndex = value_index(value);
  if(vIndex != -1){
    values[vIndex]->first+=1;
  }
  else{
    values.push_back(make_shared<pair<int,int>>(value,1));
  }
}
int AllValues::value_index(const int& value){
  int length = values.size();
  for(int i = 0; i < length; i ++){
    if(values[i]->first == value){
      return i;
    }
  }
  return -1;
}
int AllValues::get_value_amount(const int& value){
  int vIndex = value_index(value);
  if(vIndex != -1){
    return values[vIndex]->second;
  }
  return -1;
}
AllValues::AllValues(const int& start){
  int start_reducer = start;
  for(int i = 2; start_reducer != 1; i++){
    if(start_reducer % i == 0){
      add_value(i);
      start_reducer/=i;
      i = 2;
    }
  }
}

vector<shared_ptr<vector<pair<int,int>>>> AllValues::get_flow(){
  vector<shared_ptr<vector<pair<int,int>>>> out,copyout;
  int length = values.size();

  for(int j = 0; j <= values[0]->second;j++){
    out.push_back(make_shared<vector<pair<int,int>>>());
    out[j]->push_back(pair<int,int>(values[0]->first,j));
  }

  for(int i = 1; i < length; i++){
    copyout = vector<shared_ptr<vector<pair<int,int>>>>(out);
    out.clear();
    for(auto current : copyout){
      for(int j = 0; j <= values[i]->second;j++){
        shared_ptr<vector<pair<int,int>>> copysingle(current);
        copysingle->push_back(pair<int,int>(values[i]->first,j));
        out.push_back(copysingle);
      }
    }
  }

  return out;
}
int AllValues::calculate_possible_factors(){
  auto flow = get_flow();
  int length = values.size();
  int out = 0;

  for(auto current : flow){
    int subtotal = 1;
    for(int j = 0; j<length;j++){
      subtotal*=nCk(values[j]->second,(*current)[j].second);
    }
    out += subtotal;
  }

  return out;
}

void AllValues::print_factors(){
  string out = "";
  for(auto v: values){
    out+=to_string(v->first)+'^'+to_string(v->second)+'x';
  }
  out.pop_back();
  cout<<out<<endl;
}

int main(int argc, char const *argv[]) {
  AllValues factors(30);
  cout<<factors.calculate_possible_factors()<<endl;
  return 0;
}
