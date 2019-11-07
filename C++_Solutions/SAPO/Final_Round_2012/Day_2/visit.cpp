#include <map>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

#define INF 999999

int main(){
  map<int,set<int>> heights;
  int n;
  cin>>n;
  int cur;
  int arr[n];
  for(int i = 0; i < n; i++){
    cin>>cur;
    heights[cur].insert(i);
    arr[i] = cur;
  }
  for(int i = 0; i < n; i++){
    set<int>& currentSet = heights[arr[i]];
    auto current = currentSet.find(i);
    auto lefti = prev(current,1);
    auto righti = next(current,1);
    int left = (current == currentSet.begin() ? INF : abs(*lefti-i));
    int right = (righti == currentSet.end() ? INF : abs(*righti-i));
    int MIN;
    if(right == INF){
      MIN = left;
    }
    else if(left == INF){
      MIN = right;
    }
    else{
      MIN = min(left,right);
    }
    cout<<(MIN == INF ? -1 : MIN)<<' ';
  }
}
