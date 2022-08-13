#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void timeout(int sig){
    if(sig==SIGALRM)
        puts("Time out");
}