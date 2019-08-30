#include <vector>
#include <iostream>

using namespace std;

int processQuery(int a, int b, int n){
  vector<int> values(2);
  values[0] = a;
  values[1] = b;
  int size = n+1;
  for(int i = 2; i < n+1; i++){
    values.push_back(values[i-1]^values[i-2]);
    if(values[i-1] == a && values[i] == b){
      size = i-1;
      break;
    }
  }
  return values[n%size];
}

int main(int argc, char const *argv[]) {
  int q;
  cin>>q;
  int a,b,n;
  for(int i = 0; i < q; i++){
    cin>>a>>b>>n;
    cout<<processQuery(a,b,n)<<endl;
  }
  return 0;
}
