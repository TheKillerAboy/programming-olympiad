#include <vector>
#include <string>
#include <iostream>

using namespace std;

class DigitWord{
public:
  string word;
  vector<vector<int>> positions;

  DigitWord(const string word_);
  void fillPositions(const string phrase);
  static vector<int> getPosistionsOfLetter(const string phrase, const char letter);

  bool hasQualifer();
};

DigitWord::DigitWord(const string word_){
  word = word_;
}

void DigitWord::fillPositions(const string phrase){
  for(auto letter: word){
    positions.push_back(DigitWord::getPosistionsOfLetter(phrase,letter));
  }
}

vector<int> DigitWord::
  getPosistionsOfLetter(const string phrase, const char letter){
    vector<int> out;
    int length = phrase.size();
    for(int i = 0; i < length; i++){
      if(phrase[i] == letter){
        out.push_back(i);
      }
    }
    return out;
}

bool DigitWord::hasQualifer(){
  vector<vector<int>> orders;
  for(auto value : positions[0]){
    orders.push_back(vector<int>{value});
  }
  int length = word.size();
  for(int i = 1; i < length; i++){
    vector<vector<int>> orders_copy(orders.size());
    copy(orders.begin(),orders.end(),orders_copy.begin());
    orders.clear();

    for(auto order : orders_copy){
      auto last_digit = order[i-1];
      for(auto next : positions[i]){
        if(next > last_digit){
          vector<int> order_copy(order.size());
          copy(order.begin(),order.end(),order_copy.begin());
          order_copy.push_back(next);

          orders.push_back(order_copy);
        }
      }
    }
  }
  return orders.size() > 0;
}

int main(int argc, char const *argv[]) {
  vector<DigitWord*> digitWords;
  digitWords.push_back(new DigitWord("ONE"));
  digitWords.push_back(new DigitWord("TWO"));
  digitWords.push_back(new DigitWord("THREE"));
  digitWords.push_back(new DigitWord("FOUR"));
  digitWords.push_back(new DigitWord("FIVE"));
  digitWords.push_back(new DigitWord("SIX"));
  digitWords.push_back(new DigitWord("SEVEN"));
  digitWords.push_back(new DigitWord("EIGHT"));
  digitWords.push_back(new DigitWord("NINE"));

  string phrase;
  cin>>phrase;

  for(auto digitWord : digitWords){
    digitWord->fillPositions(phrase);
    if(digitWord->hasQualifer()){
      cout<<digitWord->word;
      return 0;
    }
  }
  cout<<"NONE";
  return 0;
}
