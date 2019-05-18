#include <iostream>
#include <vector>

using namespace std;

bool equals(vector<int> v1,vector<int> v2){
    for (int i = 0; i < v1.size(); i++) {
        if(v1[i] != v2[i]){
            return false;
        }
    }
    return true;
}

bool contains(vector<vector<int>> parent,vector<int> child){
    for(vector<int> v: parent){
        if(equals(v,child)){
            return true;
        }
    }
    return false;
}

int main(){
    vector<int> sequance{4, 10, 7, 5, 11, 8, 6, 12, 9, 7, 13, 10, 9, 15, 12, 10, 16, 13, 11, 17, 14, 12, 18, 15, 14};
    vector<vector<int>> pattern(0);

    for (int size = 1; size <= sequance.size()>>1; size++) {
        for(int start = 0; start < sequance.size()-size; start+=size){
            vector<int> pattern_sequance(size);
            for(int i = start; i < start+size;i++){
                if(i+1<sequance.size()) {
                    pattern_sequance[i-start] = (sequance[i + 1] - sequance[i]);
                }
            }
            if(!(contains(pattern,pattern_sequance))){
                pattern.push_back(pattern_sequance);
            }
        }
        if(pattern.size() == 1){
            break;
        }
        else{
            pattern.clear();
        }
    }

    for(int i = 0;i<pattern[0].size();i++){
        cout<<pattern[0][i]<<' ';
    }
    cout<<'\n';

    return 0;
}