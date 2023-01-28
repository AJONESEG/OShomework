/*
 * Programming Assignment 1
 *    Kyle LeDoux
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*--------Prototypes--------*/
int makearg( char[], char**[] );

/*-----------Main-----------*/
int main(){
  char **args, str[] = "ls -l file";
  int argc;
  argc = makearg( str, &args );
  printf( "Number of arguments: %d\n", argc );
  int i;
  /*
  for( i = 0; i++; i < argc )
    printf( "%s", *args[i] );
  */
}

/*-----Makearg Function-----*/
int makearg( char s[], char **args[] ){
  int size = 0;
  int spaces = 0;
  int number_args;
  int i, j, k = 0;
  char *cp;

  while( s[size] != '\0' ){ // Count number of args
    if( s[size] == ' ' )
      spaces++;
    size++;
  }
  number_args = spaces+1;

  args = malloc( size * sizeof(char*) );
  cp = s; // copy char array into char pointer
  char string[15]; 
  while( *cp != '\0' ){ // go until the end of line
    string[j] = s[k]; // copy char of s into new string
    j++;
    k++;
    if( s[k] == ' ' || s[k] == '\0' ){ // if there's an indication of the end of an argument
      if( i >= number_args )
	break;
      args[i] = malloc(j * sizeof(char*)); // allocate memory to the first line of args
      string[j+1] == '\0'; // set a null value at the end of the line
      
      *args[i] = string;
      printf( "Argument %d: %s\n", i+1, *args[i] );
      int p = 0;
      j = 0;
      i++;
      k++;
    }
    cp++; // increase 1 char at a time going through the line
  }
  return number_args;
}
