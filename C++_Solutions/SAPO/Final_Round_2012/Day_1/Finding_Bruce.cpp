#include <iostream>
#include <cmath>

using namespace std;

long long int getCorner(long long int n){
  return n*n-n+1;
}

int main(){
  long long int n;
  cin>>n;
  long long int realm = ceil(sqrt(n));
  long long int corner = getCorner(realm);
  if(realm%2){
    if(n <= corner){
      printf("%i %i\n",realm,realm + n - corner);
    }
    else{
      printf("%i %i\n",realm + corner - n,realm);
    }
  }
  else{
      if(n <= corner){
        printf("%i %i\n",realm + n - corner,realm);
      }
      else{
        printf("%i %i\n",realm,realm + corner - n);
      }
  }
  return 0;
}
