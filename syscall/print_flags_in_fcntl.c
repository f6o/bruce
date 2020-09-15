#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define ECHO(name) printf("%16s:%4x\n",#name,name)

int
main()
{
  // int val = fcntl(atoi(argv[1]), F_GETFL 0)
  printf("FLAGS USED IN fcntl\n---\n");
  ECHO(F_DUPFD);
  ECHO(F_DUPFD_CLOEXEC);
  ECHO(F_GETFD);
  ECHO(F_SETFD);
  ECHO(F_GETFL);
  ECHO(F_SETFL);
  ECHO(F_GETOWN);
  ECHO(F_SETOWN);
  
  ECHO(O_ACCMODE);
  ECHO(O_RDONLY);
  ECHO(O_WRONLY);
  ECHO(O_RDWR);
}
