#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

static void sighandler(int signo) {
  if (signo == SIGINT) {
    printf("SIGINT handled\n");
    sleep(1);
    kill(getpid(), 15);
  } else {
    printf("SIGUSR1 handled, pid = %d\n", getpid());
  }
}

int main() {

  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  
  while (1) {
    printf("%d\n", getpid());

    sleep(1);
  }

  return 0;
}
