#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

long long int maxInRange(long long int* st, int ql, int qr, int nl, int nr, int ni){
  if(ql<=nl && nr<= qr){
    return st[ni];
  }
  else if(nr<ql || nl>qr){
    return 0;
  }
  else{
    int mid = (nl+nr)>>1;
    return max(maxInRange(st,ql,qr,nl,mid,2*ni+1),maxInRange(st,ql,qr,mid+1,nr,2*ni+2));
  }
}

void fillSegmentTree(long long int* st, long long int* arr, int nl, int nr, int ni){
  if(nl<nr){
    int mid = (nl+nr)>>1;
    fillSegmentTree(st,arr,nl,mid,2*ni+1);
    fillSegmentTree(st,arr,mid+1,nr,2*ni+2);

    st[ni] = max(st[2*ni+1],st[2*ni+2]);
  }
  else if(nl==nr){
    st[ni] = arr[nl];
  }
}

long long int* constuctSegmentTree(long long int* arr, int n){
  long long int* st = new long long int[(int)pow(2,ceil(log2(n))+1)-1];
  fillSegmentTree(st,arr,0,n-1,0);
  return st;
}

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  long long int a, b;
  int i;
  map<long long int,long long int> standCost;
  for(i = 0; i < n; i++){
    cin>>a>>b;
    if(standCost.find(a) == standCost.end()){
      standCost[a] = b;
    }
    else{
      standCost[a] = max(standCost[a],b);
    }
  }
  long long int size = standCost.size();
  long long int arr[size];
  i = 0;
  for(auto stand: standCost){
    arr[i++] = stand.second;
  }
  long long int* st = constuctSegmentTree(arr,size);
  i = 0;
  long long int height = 0;
  long long int cost = 0;
  for(auto stand: standCost){
    if(maxInRange(st,i+1,size-1,0,size-1,0) < stand.second){
      cost += (stand.first-height) * stand.second;
      height = stand.first;
    }
    i++;
  }
  cout<<cost<<endl;

  return 0;
}
