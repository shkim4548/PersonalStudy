#include"iostream"
#include"string"

int main(){

    int cnt=0;
    std::string str;
    getline(std::cin, str);
    for(int i=0;i<str.length();i++){
        if(i!=0 && i!=str.length()-1)
            if(str[i]==' ')
                cnt++;
    }
    if(str.length()<=1)
        std::cout<<0<<std::endl;
    else
        std::cout<<cnt+1<<std::endl;
}