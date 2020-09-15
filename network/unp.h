
#ifndef __unp_h
#define __unp_h

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

/* for bzero */
#include <strings.h>

#define MAXLINE 4096
#define LISTENQ 1024

#define SA struct sockaddr

/* error.c */

void err_quit(const char *, ...);
void err_sys(const char *, ...);

/* wrap.c */
int Accept(int, struct sockaddr *, socklen_t *);
void Bind(int, struct sockaddr *, socklen_t);
void Listen(int, int);
int Socket(int, int, int);
void Close(int);
void Write(int, void *, size_t);

#endif
