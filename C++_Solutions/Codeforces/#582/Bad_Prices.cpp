#include <iostream>

using namespace std;

int MIN(int a, int b){
  if(a==-1){return b;}
  else if(b==-1){return a;}
  else if(a<b){return a;}
  return b;
}

int ceilLog2(int n){
  int out = 0;
  float N = (float)n;
  while(N > 1){
    out ++;
    N/=2;
  }
  return out;
}

int power2(int a){
  int out = 1;
  for( int i = 0; i < a; i++){
    out*=2;
  }
  return out;
}

void populateSegmentTree(int* st, int* arr, int l, int r, int ni){
  if(l<r){
    int mid = (l+r)>>1;
    populateSegmentTree(st,arr,l,mid,2*ni+1);
    populateSegmentTree(st,arr,mid+1,r,2*ni+2);

    st[ni] = MIN(st[2*ni+1],st[2*ni+2]);
  }else if(l==r){
    st[ni] = arr[l];
  }
}

int* constructSegmentTree(int* arr, int size){
  int* st = new int[power2(ceilLog2(size)+1)-1];
  populateSegmentTree(st,arr,0,size-1,0);
  return st;
}

int minInRange(int* st, int ql, int qr, int nl, int nr, int ni){
  if(ql<=nl&&qr>=nr){
    return st[ni];
  }
  else if(nl>qr || nr<ql){
    return -1;
  }
  else{
    int mid = (nl+nr)>>1;
    return MIN(minInRange(st,ql,qr,nl,mid,2*ni+1),minInRange(st,ql,qr,mid+1,nr,2*ni+2));
  }
}

int NumberOfBad(int* arr, int size){
  int* st = constructSegmentTree(arr,size);
  int out = 0;
  for(int i = 0; i < size-1; i++){
    if(minInRange(st,i+1,size-1,0,size-1,0) < arr[i]){
      out++;
    }
  }
  delete st;
  return out;
}

int main(int argc, char const *argv[]) {
  int q;
  cin>>q;
  int size;
  for(int i = 0; i < q; i++){
    cin>>size;
    int arr[size];
    for(int j = 0; j < size;j++){
      cin>>arr[j];
    }
    cout<<NumberOfBad(arr,size)<<endl;
  }
  return 0;
}
