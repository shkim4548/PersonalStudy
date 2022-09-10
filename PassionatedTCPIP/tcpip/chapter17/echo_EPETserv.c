#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 4
//엣지 트리거방식의 동작 방식을 확인하기 위해 버퍼 사이즈를 4로 진행
#define EPOLL_SIZE 50

//엣지트리거 기반의 에코 서버 구현
void setnonblockingmode(int fd);
void error_handling(char *buf);

int main(int argc, char *argv[])
{
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_adr, clnt_adr;
    socklen_t adr_sz;
    int str_len, i;
    char buf[BUF_SIZE];

    struct epoll_event *ep_events;
    struct epoll_event event;
    int epfd, event_cnt;
    if (argc != 2)
    {
        printf("Usage : %s <port>\n", argv[0]);
        exit(1);
    }

    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr.sin_port = htons(atoi(argv[1]));
    if (bind(serv_sock, (struct sockaddr *)&serv_adr, sizeof(serv_adr)))
        error_handling("bind() error");
    if (listen(serv_sock, 5) == -1)
        error_handling("listen() error");

    epfd = epoll_create(EPOLL_SIZE);
    ep_events = malloc(sizeof(struct epoll_event) * EPOLL_SIZE);

    setnonvblockingmode(serv_sock);
    event.events = EPOLLIN;
    event.data.fd = serv_sock;
    epoll_ctl(epfd, EPOLL_CTL_ADD, serv_sock, &event);

    while (1)
    {
        event_cnt = epoll_wait(epfd, ep_events, EPOLL_SIZE, -1);
        if (event_cnt == -1)
        {
            puts("epoll_wait() error");
            break;
        }
        puts("return epoll_wait");
        //이벤트의 발생횟수를 확인하기 위한 문자열 출력 문장
        for (i = 0; i < event_cnt; i++)
        {
            if (ep_events[i].data.fd == serv_sock)
            {
                adr_sz = sizeof(clnt_adr);
                clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_adr, &adr_sz);
                setnonblockingmode(clnt_sock);
                //accept 함수 호출에 의해 생성된 소켓을 Non-Blocking 소켓으로 변경한다.
                event.events = EPOLLIN | EPOLLET;
                //EPOLLIN에 EPOLLET을 추가해서 소켓의 이벤트 등록방식을 엣지 트리거 방식으로 설정중이다.
                event.data.fd = clnt_sock;
                epoll_ctl(epfd, EPOLL_CTL_ADD, clnt_sock, &event);
                printf("connectd client: %d \n", clnt_sock);
            }
            else
            {
                while (1)
                {
                    //레벨 트리거 방식의 에코서버에는 존재하지 않았던 내용. 엣지 트리거 방식에서는 이벤트 발생시 입력버퍼에 존재하는 데이터를 모두 수신해야 하기 때문에 read함수를 반복 호출한다.
                    str_len = read(ep_events[i].data.fd, buf, BUF_SIZE);
                    if (str_len == 0)
                    {
                        epoll_ctl(epfd, EPOLL_CTL_DEL, ep_events[i].data.fd, NULL);
                        close(ep_events[i].data.fd);
                        printf("closed client: %d \n", ep_events[i].data.fd);
                        break;
                    }
                    else if (str_len < 0)
                    {
                        //read함수가 -1을 return하고 errno에 저장된 값이 EAGAIN인 상황은 입력버퍼에 저장된 데이터를 모두 읽어 들인 경우에 발생하기 때문에 break문을 통해서 반복문에 탈출한다.
                        if (errno == EAGAIN)
                            break;
                    }
                    else
                    {
                        write(ep_events[i].data.fd, buf, str_len);
                        // echo 만드는 부분
                    }
                }
            }
        }
    }
    close(serv_sock);
    close(epfd);
    return 0;
}
void setnonblockingmode(int fd)
{
    int flag = fcntl(fd, F_GETFL, 0);
    fcntl(fd, F_SETFL, flag|O_NONBLOCK);
}

void error_handling(char *buf)
{
    fputs(buf, stderr);
    fputc('\n', stderr);
    exit(1);
}