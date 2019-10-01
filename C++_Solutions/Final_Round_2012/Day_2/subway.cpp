#include <string>
#include <set>
#include <iostream>

using namespace std;

void next_iter(string& arr){
  size_t n = arr.length();
  for(size_t i = 1; i < n-1; i++){
    arr[i-1] = arr[i];
  }
  arr[n-2] = arr[0];
  arr[0] = '0';
  arr[n-1] = '1';
}

int main(){
  set<string> known;
  int N;
  cin>>N;
  string cur;
  int count = 0;
  for(int i = 0; i < N; i++){
    cin>>cur;
    if(known.find(cur) == known.end()){
      count++;
      string first = cur;
      known.insert(cur);
      next_iter(cur);
      while(cur != first){
        known.insert(cur);
        next_iter(cur);
      }
    }
  }

  cout<<count<<endl;

  return 0;
}