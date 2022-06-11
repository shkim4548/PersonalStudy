#include"iostream"
#include"string"
using namespace std;

int main(){
    int n, cnt;
    string str;

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>cnt;
        getline(cin, str);
        for(int j=1;j<str.length()+1;j++){
            for(int k=0;k<cnt;k++){
                cout<<str[j];
            }
        }
        cout<<"\n";
    }
    return 0;
}