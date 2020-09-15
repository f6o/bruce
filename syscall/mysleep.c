#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <setjmp.h>

static void sig_alarm(int signo)
{
  // do nothing
}

static jmp_buf sleep_env;
static void sig_alarm2(int signo)
{
  longjmp(sleep_env, 2);
}

unsigned int sleep1(unsigned int sec)
{
  if ( signal(SIGALRM, sig_alarm) == SIG_ERR )
    return sec;

  alarm(sec);
  pause();
  return(alarm(0));
}

unsigned int sleep2(unsigned int sec)
{
  if ( signal(SIGALRM, sig_alarm2) == SIG_ERR )
    return sec;

  if ( setjmp(sleep_env) == 0 ) {
    alarm(sec);
    pause();
  }
  return(alarm(0));
}

static void sig_int(int signo)
{
  int i, j;
  volatile int k = 0;
  for ( i = 0; i < 10000; i++ )
    for ( j = 0; j < 10000; j++ )
      k += i*j;
  printf("sigint handler finished");
}

int main()
{
  unsigned int unslept;

  if ( signal(SIGINT, sig_int) == SIG_ERR ) {
    return 1;
  }

  unslept = sleep2(5);
  printf("sleep2 returned %u\n", unslept);
}

