#include <iostream>
#include <array>
#include <string>
#include <cmath>

using namespace std;

class Coor{
public:
    int x,y;
    Coor(int x,int y){
        this ->x = x;
        this->y=y;
    }
    int distance(Coor* other){
        return abs(other->x-this->x) + abs(other->y-this->y);
    }
};

int get_index(array<char,30> console,char letter){
    for (int i = 0; i < console.size(); i++) {
        if(console[i] == letter){
            return i;
        }
    }
    return -1;
}

Coor* get_coor(array<char,30> console,char letter){
    int index = get_index(console,letter);
    return new Coor((index-index%6)/6,index%6);
}

int main(){
    array<char,30> console = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T',
                              'U','V','W','X','Y','Z',' ','-','.','~'};
    string word = "PHONE";
    if(word[0] != 'A'){
        word = 'A'+word;
    }
    word.push_back('~');
    int distance = 0;
    for(int i = 0;i<word.size()-1;i++){
        distance+=get_coor(console,word[i])->distance(get_coor(console,word[i+1])) + 1;
    }
    cout<<distance;
    return 0;
}
