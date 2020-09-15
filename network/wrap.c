#include "unp.h"

int
Accept(int fd, struct sockaddr *sa, socklen_t *salenptr)
{
  int n;
 again:
  if ( (n = accept(fd, sa, salenptr)) < 0) {
    if ( errno == EPROTO || errno == ECONNABORTED)
      goto again;
    else
      err_sys("accept error");
  }
  return(n);
}

void
Bind(int fd, struct sockaddr *sa, socklen_t salen)
{
  if (bind(fd, sa, salen) < 0)
    err_sys("bind error");
}

void
Listen(int fd, int backlog)
{
  char *ptr;
  if ( (ptr = getenv("LISTENQ")) != NULL)
    backlog = atoi(ptr);

  if (listen(fd, backlog) < 0)
    err_sys("listen error");
}

int
Socket(int family, int type, int protocol)
{
  int n;
  if ( (n = socket(family, type, protocol)) < 0)
    err_sys("socket_err");
  return(n);
}

void
Close(int fd)
{
  if (close(fd) == -1)
    err_sys("close error");
}

void
Write(int fd, void *ptr, size_t nbytes)
{
  if (write(fd, ptr, nbytes) != nbytes)
    err_sys("write error");
}
