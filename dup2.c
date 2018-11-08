#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 64

void
error(const char * msg) {
  fprintf(stderr, msg);
  exit(1);
}

int
mydup2(int oldfd, int newfd) {
  /*
   * APUE 3ED, EX. 3.x
   * fcntl を使わずに dup2 を書き直す
   * 
   * dup2(fd, fd2)
   * == close(fd); fcntl(fd, F_DUPFD, fd2)
   * 
   */

  if ( oldfd == newfd )
    return newfd;
  
  if ( newfd == IS_OPEN )
    close(newfd);

  /*
   * TODO: newfd のファイル記述子フラグ FD_CLOEXEC はクリアされる
   */
}

int
main(int argc, char** argv)
{
  /*
   * test mydup2
   */

  return 0;
}
