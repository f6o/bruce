#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>

void print_limit(const char *, int);
#define doit(name) print_limit(#name,name)

int
main ()
{
  doit(RLIMIT_CPU);
  doit(RLIMIT_FSIZE);
  doit(RLIMIT_NOFILE);
}

void
print_limit(const char *name, int res)
{
  struct rlimit rl;
  getrlimit(res, &rl);
  printf("%s\t", name);
  if ( rl.rlim_cur == RLIM_INFINITY )
    printf("(inf)\t");
  else
    printf("%10lld\t", rl.rlim_cur);

  if ( rl.rlim_max == RLIM_INFINITY )
    printf("(inf)\n");
  else
    printf("%10lld\n", rl.rlim_max);
}
