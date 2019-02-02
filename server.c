/*
 stdio.h contains input output related  features
 it defines the 3 types of variables: size_t, FILE, fpos_t
 it also define some important macros like EOF, NULL and functions for i/o
 operations
*/
#include <stdio.h>
/*
  stdlib.h contains 4 types of variables like wide char wchar_t
  Macros like RAND_MAX
  functions like rand(), abs()message
 */
#include <stdlib.h>

/*
 netdb.h is part off GNU c library
 definitions for network database operations
 All data returned to the network database library are supplied in
 host order and returned in network order (suitable for use in
 system calls).
*/
#include <netdb.h>
/*
 The header file in.h contains constants and structures needed for internet
 domain addresses.
*/
#include <netinet/in.h>
/*
 string.h defines function related to manipulation of array of characters
 It defines only one type of variable size_t
 and one macro NULL
*/
#include <string.h>

/*
 unistd.h contains fork() declaration
*/
#include <unistd.h>
/*
argc stands for argument count i.e. number arguments passed
argv stands for argument vector which  is 1-D array of string
where each string is arguments passed.
*/
void doprocessing(int sock);

int main(int argc, char *argv[])
{
  int sockfd, newsockfd, portno,clilen;
  char buffer[256];
  struct sockaddr_in serv_addr, cli_addr;
  int n, pid;

/*
  AF_INET is socket address family here we are communicating over IPV4 protocol
  so socket address family i.e sa_family is AF_INET
  SOCK_STREAM is type of socket.There are 4
  SOCK_STREAM,SOCK_DGRAM,SOCK_SEQPACKET,SOCK_RAW
  SOCK_STREAM is for tcp socket
*/
  sockfd=socket(AF_INET, SOCK_STREAM, 0);

// initialize socket structure
  bzero((char *) &serv_addr, sizeof(serv_addr));

// assign port number over which socket will communicate
  portno=5001;

  serv_addr.sin_family=AF_INET;
// bind socket too all interfaces. INADDR_ANY is cosntant equal to 0
  serv_addr.sin_addr.s_addr=INADDR_ANY;
// htons convert host byte order to network byte order
  serv_addr.sin_port=htons(portno);

// bind the host address using bind() call
  bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr) < 0);

// at this point server socket is ready
// Now here process will go into sleep mode and wait (listen) for incomming connections
  listen(sockfd,5);
  clilen=sizeof(cli_addr);
   while(1)
   {
     newsockfd=accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
     pid=fork();
     if(pid==0)
     {
       close(sockfd);
       doprocessing(newsockfd);
       exit(0);
     }
     else
     {
       close(newsockfd);
     }
   }
  return 0;
}

void doprocessing(int sock)
{
  int n;
  char buffer[256];
  n=read(sock, buffer, 255);
  printf("Client said: ");
  n=write(sock, "Got it.", 18);
}
