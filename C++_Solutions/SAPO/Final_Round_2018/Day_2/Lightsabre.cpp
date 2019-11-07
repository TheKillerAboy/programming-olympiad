#include <iostream>
#include <algorithm>
#include <vector>

#pragma GCC optimize ("O3")

#define INF 99999999

using namespace std;

vector<vector<int>> stored;

int getSabre(int N, int M){
  for(int j = 1; j <= M; j++){
    for(int i = 0; i <= N; i++){
      printf("%i %i\n", i,j);
      if(j == 1){
        stored[i][j] = i;
      }
      else if(i == 1 || i == 0){
        stored[i][j] = i;
      }
      else{
        for(int k = 1; k <= i; k++){
          stored[i][j] = min(stored[i][j],1+max(stored[k-1][j-1],stored[i-k][j]));
        }
      }
    }
  }
  return stored[N][M];
}

int main(){
  int N,M;
  cin>>N>>M;
  cout<<(N+1)*(M+1)*sizeof(int)<<" Bytes"<<endl;
  stored = vector<vector<int>>(N+1,vector<int>(2,INF));
  cout<<getSabre(N,M)<<endl;

  return 0;
}
