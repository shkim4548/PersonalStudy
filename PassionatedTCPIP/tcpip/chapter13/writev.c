#include<stdio.h>
#include<sys/uio.h>

int main(int argc, char* argv[]){
    struct iovec vec[2];
    char buf1[] = "ABCDEFG";
    char buf2[] = "123456789";
    int str_len;

    vec[0].iov_base = buf1;
    //첫번째로 전송할 데이터가 저장된 위치
    vec[0].iov_len = 3;
    //첫번째로 전송할 데이터가 저장된 길이
    vec[1].iov_base = buf2;
    //두번째로 전송할 데이터가 저장될 위치
    vec[1].iov_len = 4;
    //두번째로 전송할 데이터가 저장된 길이

    str_len = writev(1, vec, 2);
    //writev 함수의 첫번째 전달인자가 1이므로 콘솔로 출력이 이뤄진다.
    puts("");
    printf("Write Bytes: %d \n", str_len);
    return 0;
}