#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void
err_sys(const char *msg)
{
  fprintf(stderr, "%s\n", msg);
  exit(1);
}

void
set_fl(int fd, int flags) /* flags are file status flags to turn on */
{
  int val;

  if ((val = fcntl(fd, F_GETFL, 0)) < 0)
    err_sys("fcntl F_GETFL error");
  
  val |= flags; /* turn on flags */

  if (fcntl(fd, F_SETFL, val) < 0)
    err_sys("fcntl F_SETFL error");
}

#define	BUFFSIZE 4096

int
main(void)
{
  int n;
  char buf[BUFFSIZE];
  set_fl(1, O_SYNC);
  while ((n = read(0, buf, BUFFSIZE)) > 0)
    if (write(1, buf, n) != n)
      err_sys("write error");
  
  if (n < 0)
    err_sys("read error");
  
  exit(0);
}
