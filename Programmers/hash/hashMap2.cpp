#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<string> v1 ={"119","97674223", "1195524421"}
    
    //먼저 문자열을 3개씩 자르고
    for(int i = 0;i<v1.size();i++){
        v1[i].substr(i,3);
    }
}