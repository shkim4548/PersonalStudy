
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//completion의 길이는 participant의 길이보다 1작다

int main(void){
    //3
    //vector<string> participant={"mislav","stanko","mislav","ana"};
    //vector<string> completion={"stanko","ana","mislav"};

    //2
    vector<string> participant={"leo","kiki","eden"};
    vector<string> completion={"eden","kiki"};
    string answer;

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for(auto loop : participant)
        cout<<loop<<endl;
    cout<<"\n";
    for(auto loop : completion)
        cout<<loop<<endl;

    cout<<participant.capacity()<<"\n";
    cout<<completion.capacity()<<"\n";

    for(int i=0; i<participant.size(); i++){
        if(i==completion.size())
            answer=participant[participant.size()-1];
        if(participant[i]!=completion[i]){
            answer=participant[i];
            break;
        }
    }
    cout<<answer<<endl;
    return 0;
}
