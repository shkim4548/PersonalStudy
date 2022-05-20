#include<stdio.h>
#include<arpa/inet.h>

int main(int argc, char* argv[]){
    unsigned short host_port=0x1234;
    unsigned short net_port;
    unsigned long host_addr=0x12345678;
    unsigned long net_addr;

    net_port = htons(host_port); //host to network short
    net_addr = htonl(host_addr); // host to network long

    printf("Host ordered port : %#x\n", host_port); //인텔계열 CPU니까 리틀 앤디안 방식
    printf("Network ordered port : %#x \n", net_port); //network 방식이니까 빅 앤디안으로 변환된다.
    printf("Host Ordered address : %#lx \n", host_addr); //위와 같지만 타입이 long 형식으로 바뀜
    printf("Network ordered address = %#lx \n", net_addr); // network 방식 long 타입 리틀 엔디안
    return 0;
}