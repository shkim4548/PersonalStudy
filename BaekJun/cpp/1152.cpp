#include"iostream"
#include"cstring"

int main(){

    int cnt=0;
    char str[100];

    std::cin>>str;
    for(int i=0;i<100;i++){
        if(str[i]==' '){
            cnt++;
        }
    }

    std::cout<<cnt<<std::endl;
}