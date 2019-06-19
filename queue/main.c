#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

// fork
#include <unistd.h>

// wait
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
  printf("start\n");
  int pid = fork();
  int status, terminated;
  volatile int k = 0;
  int i, j;

  if ( pid < 0 ) {
    perror("fork error");
    exit(1);
  }

  if ( pid == 0 ) {
    // child
    for ( i = 0; i < 10000; i++ ) {
      for ( j = 0; j < 10000; j++ ) {
	k += j*i;
      }
    }
    printf("hey dad...\n");
    exit(0);
  } else {
    // parent
    printf("wheres my daughter??\n");
    if ( wait(&status) < 0 ) {
      perror("child seems not to be terminated");
      exit(2);
    }
  }
  printf("done\n");
}
