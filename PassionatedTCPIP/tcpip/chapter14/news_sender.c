#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>

#define TTL 64
#define BUF_SIZE 30
void error_handling(char* message);

int main(int argc, char* argv[]){
    int send_sock;
    struct sockaddr_in mul_adr;
    int time_live=TTL;
    char buf[BUF_SIZE];
    FILE* fp;
    if(argc!=3){
        printf("Usage : %s <GroupIP> <PORT>\n", argv[0]);
        exit(1);
    }
    send_sock=socket(PF_INET, SOCK_DGRAM, 0);
    //멀티캐스트에 사용하는 소켓은 UDP소켓이다.
    memset(&mul_adr, 0, sizeof(mul_adr));
    mul_adr.sin_family=AF_INET;
    //데이터를 전송할 주소정보를 설정하는 중이다. 반드시 IP주소를 멀티캐스트 주소로 설정해야한다.
    mul_adr.sin_addr.s_addr=inet_addr(argv[1]); //Muiticast IP로 설정하는 부분, 컴파일러 옵션으로 제공해야한다.
    mul_adr.sin_port=atoi(argv[2]); //Multicast Port로 설정하는 부분, 컴파일러 옵션으로 제공해야한다.

    setsockopt(send_sock, IPPROTO_IP, IP_MULTICAST_TTL, (void*)&time_live, sizeof(time_live));
    //소켓의 TTL정보를 지정하고 있다. Sender에선 반드시 해야할 일이다.
    if((fp=fopen("news.txt", "r"))==NULL)
        error_handling("fopen() error");
    
    //브로드캐스팅 실행부
    while(!feof(fp)){
        fgets(buf, BUF_SIZE, fp);
        sendto(send_sock, buf, strlen(buf),0 , (struct sockaddr*)&mul_adr, sizeof(mul_adr));
        //UDP소켓을 기반으롵 통신하므로 sendto 함수를 사용한다.
        sleep(2);
        //데이터 전송에 시간차를 인위적으로 만들기 위해 사용했다
    }
    close(fp);
    close(send_sock);
    return 0;
}

void error_handling(char* message){
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
//TTL이란 거쳐갈 수 있는 노드의 수를 지정한다고 보면 된다.