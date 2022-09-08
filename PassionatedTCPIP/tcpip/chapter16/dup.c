#include <stdio.h>
#include <unistd.h>

//dup와 dup2의 기능확인을 위한 코드
int main(int argc, char *argv[])
{
    int cfd1, cfd2;
    char str1[] = "Hi~ \n";
    char str2[] = "It's nice day~ \n";

    cfd1 = dup(1);
    //dup함수호출을 통해서 파일 디스크립터 1을 복사하고
    cfd2 = dup2(cfd1, 7);
    //dup2함수호출을 통해서 복사한 파일 디스크립터를 재복사하고 있다. 파일 디스크립터의 정수값도 7로지정

    printf("fd1=%d, fd2=%d \n", cfd1, cfd2);
    write(cfd1, str1, sizeof(str1));
    write(cfd2, str2, sizeof(str2));
    //위의 두 줄은 복사된 파일 디스크립터를 이용해서 출력을 진행한다. 실제 복사의 여부를 알 수 있다.

    close(cfd1);
    //복사된 파일 디스크립터를 모두 종료하고 있다. 종료했지만 하나가 남아 있으므로 아래에서 출력이 이뤄진다
    close(cfd2);
    //마지막 파일 디스크립터를 종료한다.
    write(1, str1, sizeof(str1));
    close(1);
    write(1, str2, sizeof(str2));
    return 0;
}