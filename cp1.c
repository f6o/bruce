#include <utmp.h>
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
  /* two file cp */
  if ( argc != 3 ) {
    error("two file copy only\n");
  }

  int src = open(argv[1], O_RDONLY);
  if ( src == -1 )
    error("could not open the source file.");
  int dst = open(argv[2],
                 O_WRONLY | O_CREAT | O_TRUNC,
                 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  if ( dst == -1 ) {
    error("could not create the dest file.");
  }

  char buf[BUFSIZE];
  size_t s = sizeof(char)*BUFSIZE;
  ssize_t t;
  while ( (t = read(src, buf, s)) > 0 ) {
    if ( write(dst, buf, t) != t )
      error("write error");
  }
  close(src);
  close(dst);
}
