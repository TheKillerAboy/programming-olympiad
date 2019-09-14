#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int processQuery(int x,int n,int* damage,int* grow){
  int maxDamage = *max_element(damage,damage+n);
  int bestProfit = 0;
  int bestProfitHit = 0;
  for(int i = 0; i < n; i++){
    if(bestProfit<damage[i] - grow[i]){
      bestProfit = damage[i] - grow[i];
      bestProfitHit= damage[i];
    }
  }
  if(bestProfit <= 0){
    return -1;
  }
  int moves = ceil((float)x/bestProfit);
  if(x%bestProfit+bestProfit<=bestProfitHit){
    return moves - 1;
  }
  else{
    return moves - floor((float)(maxDamage-1)/bestProfitHit);
  }
}

int main(int argc, char const *argv[]) {
  int q;
  cin>>q;
  int n,x;
  for(int i = 0; i < q; i++){
    cin>>n>>x;
    int damage[n];
    int grow[n];
    for(int j = 0; j < n ; j++){
      cin>>damage[j]>>grow[j];
    }
    cout<<processQuery(x,n,damage,grow)<<endl;
  }
  return 0;
}
