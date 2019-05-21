#include <iostream>
#include <vector>
#include <array>

using namespace std;




class Coor{
private:
    static vector<Coor> offset;
public:
    int x,y;
    Coor(int x,int y){
        this->x=x;
        this->y=y;
    }
    Coor(){
        x=0;
        y=0;
    }
    Coor add(Coor other){
        return *(new Coor(x+other.x,y+other.y));
    }
    bool equals(Coor other){
        return x == other.x && y == other.y;
    }
    Coor* next(){
        Coor* out;
        out = new Coor[8];
        for(int i = 0; i < 8;i++){
            out[i] = add(offset[i]);
        }
        return out;
    }
};

vector<Coor> Coor::offset{
Coor(1,2),
Coor(-1,2),
Coor(1,-2),
Coor(-1,-2),
Coor(2,1),
Coor(2,-1),
Coor(-2,1),
Coor(-2,-1)
};

class Knights{
public:
    vector<Coor> knights;
    Knights(){
        knights = *(new vector<Coor>(0));
    }
    void add(Coor location){
        if(!contains(location)){
            knights.push_back(location);
        }
    }
    bool contains(Coor location){
        for(Coor loc:knights){
            if(loc.equals(location)){
                return true;
            }
        }
        return false;
    }
    void clear(){
        knights.clear();
    }
};
