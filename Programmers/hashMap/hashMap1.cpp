#include<iostream>
#include<hash_map>
#include<vector>
#include<string>

using namespace std;

int main(){
    vector<string> participant = {"leo", "kiki", "eden"};
    vector<string> completion = {"eden","kiki"};

    for(int i =0; i<3;i++){
        for(int j=0;j<2;j++){
            if(participant[i]==completion[j]){
                participant[i];
                //대충 일치하는 participant 요소를 지워야함
            }
        }
    }
}