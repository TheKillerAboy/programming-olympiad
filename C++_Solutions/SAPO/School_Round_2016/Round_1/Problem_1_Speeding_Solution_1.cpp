#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int time,distance;
  cout<<"Time?";
  cin>>time;
  cout<<"Distance?";
  cin>>distance;

  cout<<(float)(distance)*18/(time*5);
  return 0;
}
