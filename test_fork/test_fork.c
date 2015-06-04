#include <unistd.h>
#include <stdio.h>
int main ()
{
    pid_t fpid;
    int count=0;
    fpid=fork();
    if (fpid < 0)
        printf("error in fork!");
    else if (fpid == 0) {
        while (count < 20) {
        printf("i am the child process, my process id is %d, and loop is %d \n",getpid(),count);
        count++;}
    }
    else {
        while (count < 20) {
        printf("i am the parent process, my process id is %d \n",getpid());
        count++;
        }
    }
    printf("results: %d\n",count);
    return 0;
}
