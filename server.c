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
  functions like rand(), abs()
 */
#include <stdlib.h>

/*
 netdb.h is part off GNU c library
 efinitions for network database operations
 All data returned by the network data base library are supplied in
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
argc stands for argument count i.e. number arguments passed
argv stands for argument vector which  is 1-D array of string
where each string is arguments passed.
*/
int main(int argc, char *argv[])
{
  return 0;
}
