#include <iostream>
#include <cctype>

using namespace std;

string letters = "abcdefghijklmnopqrstuvwxyz";

void remove_symbols(string& word){
  for (size_t i = 0; i < word.size(); i++) {
    if(letters.find(tolower(word[i])) == string::npos){
      word[i] = ' ';
    }
  }
}
int count_words(string& word){
  int counter = 0;
  bool space = true;
  for (size_t i = 0; i < word.size(); i++) {
    if(word[i-1] == ' ' && word[i] != ' '){
      counter++;
    }
  }
  return counter;
}

int count_letters(string& word){
  int counter = 0;
  for (size_t i = 0; i < word.size(); i++) {
    if(letters.find(tolower(word[i])) != string::npos){
        counter++;
    }
  }
  return counter;
}

int main(int argc, char const *argv[]) {

  string word = "\“Stop!\”, shouted Chris. He said to Emily, \“Why were you running in the hall?\”";
  remove_symbols(word);
  cout<<(long double)count_letters(word)/count_words(word)<<endl;
  return 0;
}
