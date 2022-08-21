#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/time.h>
#include<sys/select.h>

#define BUF_SIZE 100
void error_handling(char* buf);

int main(int argc, char* argv[]){
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_adr, clnt_adr;
    struct timeval timeout;
    fd_set reads, cpy_reads;

    socklen_t adr_sz;
    int fd_max, str_len, fd_num, i;
    char buf[BUF_SIZE];
    if(argc!=2){
        printf("Usage : %s <port>\n", argv[0]);
        exit(1);
    }

    serv_sock=socket(PF_INET, SOCK_STREAM, 0);
    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family=AF_INET;
    serv_adr.sin_addr.s_addr=htonl(INADDR_ANY);
    serv_adr.sin_port=htons(atoi(argv[1]));

    if(bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr))==-1)
        error_handling("bind() error");
    if(listen(serv_sock, 5)==-1)
        error_handling("listen() error");

    FD_ZERO(&reads);
    FD_SET(serv_sock, &reads);
    //select 함수의 두번째 인자로 전달될 fd_set 형 변수 reads에 서버 소켓을 등록하고 있다.
    fd_max=serv_sock;

    while(1){
        cpy_reads = reads;
        timeout.tv_sec=5;
        timeout.tv_usec=5000;

        if((fd_num=select(fd_max+1, &cpy_reads, 0, 0, &timeout))==-1)
            break;
            //위의 while 문 아래에서 무한 루프 아래에 select 함수가 호출되고 있다.
            // select 문의 3번 4번 인자가 0으로 비어있다 -> 필요한 인자만 제공 가능하다.
        if(fd_num==0)
            continue;
        
        for(i=0;i<fd_max+1;i++){
            if(FD_ISSET(i, &cpy_reads)){
                //select 함수가 1이상 반복되었을때 실행되는 반복문
                //1이상 반환되었음으로 FD_ISSET 함수를 호출하면서 상태 변화가 있었던(수신된 데이터가 있는 소켓의)파일 디스크립터를 찾고 있다.
                if(i==serv_sock){
                    //상태변화가 확인이 되면 제일 먼저 서버 소켓에 변화가 있었는지 확인한다.
                    adr_sz=sizeof(clnt_adr);
                    clnt_sock=accept(serv_sock, (struct sockaddr*)&clnt_adr, &adr_sz);
                    //위의 if문에서 서버 소켓의 변화가 맞다면 연결요청에 대한 수락의 과정을 진행한다.
                    FD_SET(clnt_sock, &reads);
                    //fd_set형 변수 reads에 클라이언트와 연결된 소켓의 파일 디스크립터 정보를 등록함에 주목한다.
                    if(fd_max<clnt_sock)
                        fd_max=clnt_sock;
                    printf("connected client : %d \n", clnt_sock);
                }
                else{
                    //상태변화가 발생한 소켓이 서버 소켓이 아닌경우 실행되는 영역
                    str_len=read(i, buf, BUF_SIZE);
                    if(str_len == 0){
                        //수신된 데이터가 EOF(연결종료 신호)라면 닫아버린다
                        FD_CLR(i, &reads);
                        close(i);
                        printf("closed client: %d \n", i);
                    }
                    else{
                        //EOF가 아니라면 읽어들인다.
                        write(i, buf, str_len);
                    }
                }
            }
        }
    }
    close(serv_sock);
    return 0;
}

void error_handling(char* buf){
    fputs(buf, stderr);
    fputc('\n', stderr);
    exit(1);
}