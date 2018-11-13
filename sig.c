#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>

static void sighandler(int signo) {
  printf("got signal: %d\n", signo);
  if (signo == SIGINT) {
    printf("sigint!\n");
    char message[29] = "Program exited due to SIGINT\n";
    int f = open("error_log.txt", O_WRONLY | O_CREAT, 0755);
    write(f, message, 29);
    close(f);
    exit(EXIT_SUCCESS);
  }
  else if (signo == SIGUSR1) {
    printf("parent pid: %d\n", getppid());
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
