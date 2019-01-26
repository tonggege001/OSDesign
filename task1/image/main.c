#include<stdio.h>
#include<unistd.h>  //使用execv
#include<sys/types.h>
#include<signal.h>




int execv(const char * path,char * const argv[]);


int main()
{
    pid_t p1,p2,p3;

    
    p1=fork();
    if(p1<0)
        printf("p1 fork() error\n");

    if(p1==0){  //子进程
        if(execv("./ShowWindows",NULL)<0){
            printf("execv ShowWindows ERROR!\n");
        }
        exit(0);
    }
    
    p2 = fork();
    if(p2<0)
    printf("p2 fork() error\n");
    if(p2==0){
        if(execv("./Figure",NULL)<0)
            printf("execv Figure ERROR\n");
        exit(0);
    }
    
    p3 = fork();
    if(p3<0)
        printf("p3 fork() error\n");
    if(p3==0){
        if(execv("./Sum",NULL)<0)
            printf("execv Sum ERROR\n");
        exit(0);
    }
    printf("按任意键退出\n");
    getchar();
    kill(p1,SIGINT);
    kill(p2,SIGINT);
    kill(p3,SIGINT);

    return 0;
}
