#include <iostream>

using namespace std;

void fillPirates(int* arr, int c, int left, int offset){
  if(c >= left/2){
    arr[offset] = c-(left-1)/2;
    for(int i = 0; i < left/2; i++){
      arr[i+offset+1] = 0;
    }
    for(int i = offset+1+left/2; i<offset+left;i++){
      arr[i] = 1;
    }
  }
  else{
    arr[offset] = -1;
    fillPirates(arr,c,left-1,offset+1);
  }
}

int main(){
  int c,n;
  cin>>c>>n;
  int arr[n];

  fillPirates(arr,c,n,0);

  for(int i = 0; i < n; i++){
    cout<<arr[i]<<endl;
  }
}
