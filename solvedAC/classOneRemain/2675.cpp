#include"iostream"
#include"string"
using namespace std;

int main(){
    int n, cnt;
    string str;

    cin>>n;
    for(int i=0;i<n;i++){
        cin >> cnt;
        cin >> str;
        for(int j=0;j<str.length();j++){
            for(int k=0;k<cnt;k++){
                cout<<str[j];
            }
        }
        cout<<"\n";
    }
    return 0;
}