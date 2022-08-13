#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, int argv[]){
    int status;

    pid_t pid=fork();
    //프로세스를 생성 후 ID를 저장한다.
    if(pid==0){
        return 3;
        //fork()함수를 통해 호출한 자식 프로세스를 main의 return을 통해서 종료한다.
    }
    else{
        printf("Child PID: %d \n", pid);
        pid=fork();
        //여기서 자식 프로세스가 하나 더 생성된다.

        if(pid==0){
            exit(7);
            //위의 
        }
        else{
            printf("Child PID: %d \n", pid);
            wait(&status);
            //wait 함수를 호출한다. -> 종료된 프로세스의 관련정보를 status에 담기게된다. 해당 프로세스는 완전히 소멸된다.
            if(WIFEXITED(status))
                printf("Child send one  : %d \n", WEXITSTATUS(status));

            wait(&status);
            if(WIFEXITED(status))
                printf("Child send two : %d \n", WEXITSTATUS(status));
            //생성한 자식 프로세스가 두개이므로 두번 종료한다.
            sleep(30);
            //30초동안 부모 프로세스를 일부로 멈추어 자식 프로세스의 상태를 확인히도록 했다.
        }
    }
    return 0;
    //콘솔에 표시되는 결과는 PID는 없는 것이며
    //자식 프로세스 종료시 전달된 숫자는 부모프로세스에게 넘어간 내용이다
}