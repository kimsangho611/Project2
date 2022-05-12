#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm time1, time2;

void filestat1();
void filestat2();
void filetime1();
void filetime2();
void sizecmp();
void blockcmp();
void datecmp();
void timecmp();

int main(){
    filestat1();
    filestat2();
    filetime1();
    filetime2();
    sizecmp();
    blockcmp();
    datecmp();
    timecmp();
}

//파일 1의 정보를 가져오는 함수 작성
void filestat1(){
    stat("/home/user/Project2/text1", &stat1);
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(){
    stat("/home/user/Project2/text2", &stat2);
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(){
    localtime_r(&stat1.st_mtime, &time1);
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(){
    localtime_r(&stat2.st_mtime, &time2);
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(){
    int size1 = (int)stat1.st_size;
    int size2 = (int)stat2.st_size;
    
    printf("size compare\n");
    if (size1 < size2) printf("The file size of the test2 file is bigger.\n\n");
    else if (size1 > size2) printf("The file size of the test1 file is bigger.\n\n");
    else printf("sizes is equal.\n\n");
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(){
    int block1 = (int)stat1.st_blocks;
    int block2 = (int)stat2.st_blocks;
    
    printf("block compare\n");
    if (block1 < block2) printf("The number of blocks in test2 file is bigger.\n\n");
    else if (block1 > block2) printf("The number of blocks in test1 file is bigger.\n\n");
    else printf("The number of blocks is equal.\n\n");
}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(){
    int date1 = (time1.tm_mon + 1) * 100 + time1.tm_mday;
    int date2 = (time2.tm_mon + 1) * 100 + time2.tm_mday;

    printf("date compare\n");
    if (date1 < date2) printf("file1 is early.\n\n");
    else if (date1 > date2) printf("file2 is early.\n\n");
    else printf("same date.\n\n");
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(){
    int file_time1 = (time1.tm_hour * 10000) + (time1.tm_min * 100) + time1.tm_sec;
    int file_time2 = (time2.tm_hour * 10000) + (time2.tm_min * 100) + time2.tm_sec;

    printf("time compare\n");
    if (file_time1 < file_time2) printf("The test1 file is early.\n\n");
    else if (file_time1 > file_time2) printf("The test2 file is early.\n\n");
    else printf("same time.\n\n");
}