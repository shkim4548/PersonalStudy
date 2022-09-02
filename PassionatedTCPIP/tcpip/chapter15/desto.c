#include<stdio.h>
#include<fcntl.h>

int main(void){
    FILE* fp;
    int fd=open("data.dat", O_WRONLY|O_CREAT|O_TRUNC);
    //open 함수를 사용해서 파일 생성했으므로 파일 디스크립터가 반환된다.
    if(fd==-1){
        fputs("file open error", stdout);
        return -1;
    }

    fd=fopen(fd, "w");
    //fdopen 함수호출을 통해서 파일 디스크립터 FILE 포인터로 변환하고 있다. 이 때 두번째 인자로 "w"가 전달되었으니, 출력모드의 FILE 포인터가 반환된다.
    fputs("Network C programming \n", fp);
    //위의 fd포인터에 저장된 포인터를 기반으로 표준 출력 함수인 fputs 함수를 호출하고 있다.
    fclose(fp);
    //FILE 포인터를 이용해서 파일을 닫고 있다. 이 경우  파일 자체가 완전히 종료되기 때문에 파일 디스크립터를 이용하여 또 다시 종료할 필요는 없다. fclose 함수 호출 이후부터는 파일 디스크립터도 의미없는 정수이다.
    return 0;
}