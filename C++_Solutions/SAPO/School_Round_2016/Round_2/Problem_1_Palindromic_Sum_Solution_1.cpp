#include <iostream>

using namespace std;

long long int palindromeic(const long long int value){
  string v = to_string(value);
  string inverse = "";
  for (int i = v.size()-1; i >=0; i--) {
    inverse+=v[i];
  }
  return stoll(inverse);
}

int main(int argc, char const *argv[]) {
  long long int value = 89;
  int count = 0;
  while (palindromeic(value) != value){
    value=palindromeic(value)+value;
    cout<<value<<endl;
    count++;
  }
  cout<<count<<endl;
  return 0;
}
