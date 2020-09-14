#include "unp.h"

#include <stdarg.h>

static void err_doit(int, const char *, va_list);

void
err_sys(const char *fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);
  err_doit(1, fmt, ap);
  va_end(ap);
  exit(1);
}

void
err_quit(const char *fmt, ...)
{
  va_list ap;

  va_start(ap, fmt);
  err_doit(0, fmt, ap);
  va_end(ap);
  exit(1);
}

static void
err_doit(int errnoflag, const char *fmt, va_list ap)
{
  int errno_save, n;
  char buf[MAXLINE + 1];

  errno_save = errno;
  vsnprintf(buf, MAXLINE, fmt, ap);
  n = strlen(buf);
  if (errnoflag)
    snprintf(buf + n, MAXLINE - n, ": %s", strerror(errno_save));
  strcat(buf, "\n");

  fflush(stdout);
  fputs(buf, stderr);
  fflush(stderr);

  return;
}
