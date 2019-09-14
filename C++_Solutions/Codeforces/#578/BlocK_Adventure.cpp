#include <iostream>

using namespace std;

bool isPossible(int* columns, int n, int m, int k){
  for(int i = 0; i < n - 1; i++){
    if(columns[i]+k<columns[i+1]){
      if(m >= columns[i+1] - (columns[i]+k)){
        m-=columns[i+1] - (columns[i]+k);
      }
      else{
        return false;
      }
    }
    else{
      m+=columns[i]+ k - columns[i+1];
    }
  }
  return true;
}

int main(){
  int p;
  cin>>p;
  int n,m,k;
  for(int i = 0; i < p; i++){
    cin>>n>>m>>k;
    int columns[n];
    for(int j = 0; j < n; j++){
      cin>>columns[j];
    }
    cout<<(isPossible(columns,n,m,k) ? "YES" : "NO")<<endl;
  }

  return 0;
}
