#include <string>
#include <iostream>

using namespace std;

int main(){
  string txt,pat;
  cin>>txt>>pat;
  for(int remove = txt.length() - pat.length(); remove >= 1; remove--){
    for(int i = 0; i <= txt.length() - remove; i++){
      string val = txt.substr(0,i) + txt.substr(i+remove);
      if(remove == 5){
        cerr<<val<<endl;
      }
      if(val.find(pat) != val.npos){
        cout<<remove<<endl;
        return 0;
      }
    }
  }
  cout<<0<<endl;
  return 0;
}
