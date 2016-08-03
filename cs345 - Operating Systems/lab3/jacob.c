/***********************************************************************
* Program:
*    Lab UnixShell 
*    Brother Jones, CS 345
* Author:
*      Jacob Bowser
* Summary:
*    This program implements the history feature of a shell program.  It
*    prompts the user to input commands (a string of text as far as this
*    program is concerned) with the prompt: " COMMAND-> "
*
*    The program displays the last ten commands entered by the user when
*    a period (.) is entered as the only input on a command line.
***********************************************************************/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 80 /* 80 chars per line, per command, should be enough. */
#define BUFFER_SIZE 50
/* The size of the history buffer */
#define HIST_SIZE 10
/* Maximum number of commands until count rolls over. */
#define MAX_NUM_CMDS 1000

static char msg4handler2print[BUFFER_SIZE];

// A global array of strings and a count of the number of valid strings in it.
char commands[HIST_SIZE][MAX_LINE];
int goodStringCount = 0;
/**
 * setup() reads in the next command line, separating it into distinct tokens
 * using whitespace as delimiters.
 *
 * setup() modifies the inputBuffer creating a set of null-terminated strings
 * and places pointers into the args[] array that point to the beginning of
 * each argument.  A NULL pointer is placed in the args[] array indicating
 * the end of the argument list.  This is what is needed for using execvp().
 *
 * A ^d input at the beginning of a line, by a user, exits the shell.
 */

void setup(char inputBuffer[], char *args[], int *background)
{
   int length; /* # of characters in the command line */
   int i;      /* loop index for accessing inputBuffer array */
   int start;  /* index where beginning of next command parameter is */
   int ct;     /* index of where to place the next parameter into args[] */
    
   ct = 0;
    
   /* read what the user enters on the command line */
   length = read(STDIN_FILENO, inputBuffer, MAX_LINE);  
   
   start = -1;            /* Used as a flag to indicate that we are looking
                           * for the start of the command or an argument if
                           * it is a -1, or stores the starting position of
                           * the command or argument to be put in args[].
                           */
   if (length == 0)
      exit(0);            /* ^d was entered, end of user command stream */
   if (length < 0)
   {
      perror("error reading the command");
      exit(-1);           /* terminate with error code of -1 */
   }

   if (length > 1)
   {
      inputBuffer[length] = '\0';
      inputBuffer[length + 1] = '\0';
      strncpy(commands[goodStringCount % HIST_SIZE], inputBuffer, MAX_LINE);
      goodStringCount++;  
   }
   /* examine every character in the inputBuffer */
   for (i=0;i<length;i++)
   { 
      switch (inputBuffer[i])
      {
         case ' ':
         case '\t' :               /* argument separators */
            if(start != -1)        /* found the end of the command or arg */
            {
               args[ct] = &inputBuffer[start]; /* set up pointer in args[] */
               ct++;
            }
            inputBuffer[i] = '\0'; /* add a null char; make a C string */
            start = -1;
            break;

         case '\n':                 /* should be the final char examined */
            if (start != -1)        /* if in the command or an argument */
            {
               args[ct] = &inputBuffer[start]; /* set up pointer in args[] */ 
               ct++;
            }
            inputBuffer[i] = '\0';
            args[ct] = NULL; /* no more arguments to this command */
            break;

         default :             /* some other character */
            if (start == -1 && inputBuffer[i] != '&')
               start = i;      /* starting position of the command or arg */
            if (inputBuffer[i] == '&')
            {
               *background  = 1;
               inputBuffer[i] = '\0';
            }
      }  /* end of switch */
   }  /* end of for loop looking at every character */
   args[ct] = NULL; /* just in case the input line was > 80 */
} 

/***************************************************************
 * The signal handler
 ***************************************************************/
void handle_SIGQUIT( int junk )
{
   int lenOfMsg;
   lenOfMsg = strnlen(msg4handler2print, BUFFER_SIZE);
   write(STDOUT_FILENO, msg4handler2print, lenOfMsg);
   /* this handler could exit, but typically would return so that you
   * continue execution of the program after handling the signal.*/ 
   //exit(0);
   return; 
}
      
/*************************************************************************
* findCommandInHistory() searches backward for the first command that
* begins with a particular character (char c) in the history buffer.
* If a string is found that begins with the character, the string is
* passed back to the calling function.  If the character being looked
* for is a NULL then the most recent command is returned.  In both of
* the preceeding cases, the return value is set to true.  If no matching
* string is found, the return value is set to false.
**************************************************************************/
int findCommnandInHistory(char c, char stringFound[])
{
   int temp = goodStringCount;
   stringFound = "";

   // If the character being looked for is a null, then return the most
   // recent command, if there was one.
   if (c == '\0')
   {
      if (goodStringCount)
      {
         stringFound = commands[ (goodStringCount - 1) % HIST_SIZE ];
         return 1;
      }
      else
      {
         return 0; 
      }
   }
   
   // Look back through the history for a command staring with the letter
   // given in the first argument to this function.
   for (temp; temp >= 0 && temp != temp - HIST_SIZE; --temp)
   {            
      if (commands[temp % HIST_SIZE][0] == c)
      {
         stringFound = commands[temp % HIST_SIZE];
         return 1;
      }
   }
         
   return 0;
}


/*************************************************************************
* Display the contents of the history buffer of commands with the number
* of the command listed on the beginning of the line.
**************************************************************************/
void displayHistory()
{
   int start;
   int i = start;
   
   if (goodStringCount > HIST_SIZE)
      start = goodStringCount - HIST_SIZE;
   else
      start = 0;

   printf("\n");
   for (i; i < goodStringCount; i++)
   {            
      printf(" %3d %s", i, commands[i % HIST_SIZE]);
   }
   
   return;
}

/***********************************************************************
 * The main function
 * 
 **********************************************************************/
int main(void)
{
   //siganl handling
   struct sigaction handler;
   handler.sa_handler = displayHistory;
   handler.sa_flags = SA_RESTART;
   sigaction(SIGQUIT, &handler, NULL);

   char inputBuffer[MAX_LINE]; /* buffer to hold the command entered */
   int background;             /* equals 1 if a command is followed by '&' */
   char *args[MAX_LINE/2];   /* command line (of 80) has max of 40 arguments */
  
   
   while (1)                   /* Program terminates normally inside setup */
   {
      background = 0;
      printf(" COMMAND-> ");
      fflush(stdout);
      setup(inputBuffer, args, &background); /* get next command */
      
      pid_t pid;
      pid = fork();
      
      if (pid < 0)                           //less than 0 is a failure
      {
         fprintf(stderr, "Fork Failed");
         return 1;
      }
      else if (pid == 0)                   //a 0 means to execute the command
      {
         if (execvp(args[0], args))        //non-existent command = error message               
            fprintf(stdout, "command not found\n");
      }
      else
      {
         if (background != 1)             //if there is an & share process with parent
            waitpid(pid, NULL, 0);
      }
      
      /* the steps are:
       * (1) fork a child process using fork()
       * (2) the child process will invoke execvp()
       * (3) if background != 1, the parent will wait,
       *     for the command to complete; otherwise,
       *     setup() gets called to process the next command line. 
       */ 
   }
}

