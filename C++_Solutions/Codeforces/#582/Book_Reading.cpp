#include <vector>
#include <iostream>

using namespace std;

vector<unsigned char> getPattern(int m){
  vector<unsigned char> out;
  out.reserve(20);
  int check = 0;
  int current = m%10;
  out.push_back((unsigned char)current);
  while(true){
    current += m;
    current %= 10;
    out.push_back((unsigned char)current);
    if(current == out[check]){
      check++;
      if(check*2 == out.size()){
        out.resize(check);
        return out;
      }
    }
    else{
      check = 0;
    }
  }
}

long long int query(int n, int m){
    vector<unsigned char> pattern = getPattern(m);
    int size = pattern.size();
    long long int sum = 0;
    for(int i = 0; i < size; i++){
      sum+=pattern[i];
    }
    long long int out = (n/size)*sum;
    for(int i = 0; i < n%size;i++){
      out+=pattern[i];
    }
    return out;
}

int main(){
  int q;
  cin>>q;
  int m,n;
  for(int i = 0; i < q; i++){
    cin>>n>>m;
    cout<<query(n,m)<<endl;
  }
}
