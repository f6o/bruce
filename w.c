#include <utmp.h>
#include <stdio.h>

int parse(int argc, char **argv)
{
  printf("%d\n", argc);
  while ( argc-- > 0 ) {
    printf("%s\n", *argv);
    argv++;
  }
}

int main(int argc, char** argv)
{
  // parse(argc, argv);
  printf("%s\n", UTMP_FILE);

  utmpname(UTMP_FILE);
  setutent();

  struct utmp *u = getutent();

  printf("USER\tTTY\tFROM\n");
  while ( u != NULL ) {
    if ( u->ut_type == USER_PROCESS ) {
      printf("%s\t", u->ut_user);
      printf("%s\t", u->ut_line);
      printf("%s\t", u->ut_host);
      printf("\n");
    }
    u = getutent();
  }
  
  endutent();

  // TODO implement unix command: w
  // online man: https://linux.die.net/man/1/w

  /* what w HAS and who DOESN'T:
     + uptime
       - current time
       - how long the system has been running
       - how many users are currently logged on
       - the system load avgs for the past 1, 5, 15 minutes
     + header USER/TTY/FROM/LOGIN@/IDLE/JCPU/PCPU/WHAT
     + FROM: remote host
     + LOGIN@: login time
     + IDLE: idle time
     + JCPU: the time used by all processes attatched to the tty
     + PCPU: the time used by the current process, named in the WHAT field
     + WHAT: 
  */
}
