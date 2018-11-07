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
main(int argc, char** argv)
{
  if ( argc != 2 )
    return 1;

  /*
   * excercise 2.6
   */
  
  int ro1 = open(argv[1], O_RDONLY);
  int wo = open(argv[1], O_WRONLY);
  int ro2 = open(argv[1], O_RDONLY);

  char buf[1024], buf2[1024];
  ssize_t sr = read(ro1, buf, 20);
  printf("%s\n", buf);
  ssize_t sw = write(wo, "testing 1 2 3 ...", 20);
  ssize_t sr2 = read(ro2, buf2, 20);
  printf("%s\n", buf2);
  
  close(ro1);
  close(ro2);
  close(wo);
    
}
