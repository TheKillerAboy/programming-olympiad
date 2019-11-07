#include <iostream>
#include <string>

using namespace std;

void replace_spaces(string& message){
  for (size_t i = 0; i < message.size(); i++) {
    if (message[i] == ' ') {
      message[i] = '.';
    }
  }
  string add = "";
  for (size_t i = 0; i < message.size()%5; i++) {
    add+='.';
  }
  message = message + add;
}

string flip(string message){
  string out = "";
  for (size_t i = 0; i < 5; i++) {
    for (size_t j = 0; j < message.size()/5; j++) {
      out += message[5*j+i];
    }
  }
  return out;
}

int main(int argc, char const *argv[]) {
  string message = "T.GLEHC.L.EACEM.THDAR.A.LATSATTHET!.EDE.T....HDKT.EOIH";
  replace_spaces(message);
  cout<<flip(message)<<endl;
  return 0;
}
