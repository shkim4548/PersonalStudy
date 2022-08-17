#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>

void read_childproc(int sig){
    int status;
    pid_t id=waitpid(-1, &status, WNOHANG);
    if(WIFEXITED(status)){
        printf("Remove proc id : %d \n", id);
        printf("Child send : %d \n", WEXITSTATUS(status));
    }
}

int main(int argc, char* argv[]){
    pid_t pid;
    struct sigaction act;
    //시그널 SIGCHILD에 대한 시그널 핸들러의 등록과정, 자식 프로세스가 종료되면 read_childproc을 실행한다.
    act.sa_handler=read_childproc;
    sigemptyset(&act.sa_mask);
    sigaction(SIGCHLD, &act, 0);

    pid=fork();
    //부모프로세스를 통해서 총 두개의 자식 프로세스를 생성한다. 1번
    if(pid==0){
        //자식 프로세스의 실행 영역
        puts("Hi! Im child process");
        sleep(10);
        return 12;
    }
    else{
        //부모 프로세스의 실행 영역
        printf("Child proc id : %d \n", pid);
        pid=fork();
        //부모 프로세스를 통해서 총 두개의 자식 프로세스를 생성한다. 2번
        if(pid==0){
            //또 다른 자식 프로세스의 실행영역
            puts("Hi! im child process");
            sleep(10);
            exit(24);
        }
        else{
            int i;
            printf("Child proc id : %d \n", pid);
            for(i=0;i<5;i++){
                puts("wait...");
                sleep(5);
                //5초씩 대기 시간을 만들어 5회 반복 -> 25초 대기
                //하지만 여기서 signal이 들어오면 부모프로세스가 깨어나므로 25초 미만이 소요된다
            }
        }
    }
    return 0;
}