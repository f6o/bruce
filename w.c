#include <utmp.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

void
show_info (struct utmp *u) {
  printf("%s\t", u->ut_user);
  printf("%s\t", u->ut_line);
  printf("%s\t", u->ut_host);
  printf("\n");
}

int
main(int argc, char** argv)
{
  struct utmp u;
  int fd = open(UTMP_FILE, O_RDONLY);
  if ( fd == -1 ) {
    perror(UTMP_FILE);
    exit(1);
  }
  
  ssize_t s;
  while ( ( s = read(fd, &u, sizeof(u)) ) > 0 ) {
    if ( u.ut_type == USER_PROCESS )
      show_info(&u);
  }

  close(fd);

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
