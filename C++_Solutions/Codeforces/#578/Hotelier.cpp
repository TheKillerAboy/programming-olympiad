#include <iostream>

using namespace std;

void leftIntrest(int* arr){
  for(int i = 0; i < 10; i++){
    if(arr[i] == 0){
      arr[i] = 1;
      return;
    }
  }
}

void rightIntrest(int* arr){
  for(int i = 10; i > 0; --i){
    if(arr[i] == 0){
      arr[i] = 1;
      return;
    }
  }
}

void leftHotel(int* arr, int loc){
  arr[loc] = 0;
}

int main(int argc, char const *argv[]) {
  int rooms[10] = {0};
  int q;
  cin>>q;
  string events;
  int loc;
  cin>>events;
  for(int i = 0; i < q; i++){
    if(events[i] == 'L'){
      leftIntrest(rooms);
    }
    else if(events[i] == 'R'){
      rightIntrest(rooms);
    }
    else{
      leftHotel(rooms,events[i] - '0');
    }
  }
  for(int i = 0; i < 10; i++){
    cout<<rooms[i];
  }
  return 0;
}
