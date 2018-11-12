#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

static void sighandler(int signo){
  if(signo == SIGINT){
    int fd = open("text.txt",O_WRONLY|O_CREAT,0777);
    write(fd, "Exited due to SIGINT\n",20);
    close(fd);
    //printf("\nExited due to SIGINT\n");
    exit(0);
  }
  if(signo == SIGUSR1){
    printf("My parent is %d\n",getppid());
  }
}

int main(){
  signal(SIGINT,sighandler);
  signal(SIGUSR1, sighandler);
  while(1){
    printf("Hey! My name is %d\n",getpid());
    sleep(1);
  }
}
