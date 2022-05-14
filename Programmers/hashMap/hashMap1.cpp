#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//completion의 길이는 participant의 길이보다 1작다

int main(void){
    vector<string> participant={"mislav","stankov","mislav","ana"};
    vector<string> completion={"stancov","ana","mislav"};
    //vector<string> unfinished = {};

    std::vector<int>::iterator iter;
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for(int i=participant.size();i>=0;i--){
        for(int j=completion.size();j>=0;j--){
            if(participant[i]==completion[j]){
                participant.pop_back();
            }
        }
    }
    std::cout<<"\n"<<participant[0]<<"\n";
    return 0;
}