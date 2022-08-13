#include<stdio.h>
#include<unistd.h>

int main(int argc, char* argv[]){
    pid_t pid=fork();

    if(pid==0){
        puts("Hi, I am a child process");
    }
    else{
        printf("Child process ID: %d \n", pid);
        sleep(30);
    }

    if(pid==0)
        puts("End Child process");

    else
        puts("End parent process");

    return 0;
    // 좀비 프로세스의 확인으 원하면 새로운 wsl 콘솔을 열어서 ps au 명령어를 통해 확인해야한다.
}