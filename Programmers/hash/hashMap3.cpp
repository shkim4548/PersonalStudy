#include<iostream>
#include<vector>
#include<string>
#include<map>
//using namespace std;

int main(void){
    std::vector<std::vector<std::string>> clothes1{
        {"yellohat", "headgear"},
        {"bluesunglasses", "eyewear"},
        {"green_turban", "headgear"}
    };
    
    int answer=0;
    int n=0;
    int r=n;
    std::vector<std::string> compare;
    
    compare[0]=clothes1[0][1];
    for(int i=0;i<clothes1.size();i++){
        if(clothes1[i][1]==compare[0])

    }
}