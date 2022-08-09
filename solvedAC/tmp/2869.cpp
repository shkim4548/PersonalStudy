#include<iostream>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int A,B,V, cnt=1;
    cin>>A>>B>>V;
    while(1){
        V-=A;
        if(V<=0){
            cout<<cnt<<'\n';
            break;
        }
        V+=B;
        cnt++;
    }
    return 0;
}