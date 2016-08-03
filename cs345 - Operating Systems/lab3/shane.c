/***********************************************************************
* Program:
*    Lab UnixShell  
*    Brother Jones, CS 345
* Author:
*    Shane Jensen
* Summary:
*    Exploring shells by adding signal handling, forking, and history.
*    Note: for reliable signal handling you must compile with option -O2
************************************************************************/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#define MAX_LINE 80 /* 80 chars per line, per command, should be enough */
#define MAX_HISTORY 10
#define MAX_HISTORY_NUM 1000

int show_history = 0; /* modified by the SIGQUIT handler to say when to print history */
int current_history_num = -1; /* the number of valid cmds sent to execvp */
int most_recent_index = 0; /* the history rollover list index tracker */
int num_in_history = 0; /* amount of cmds in history - useful when there's < MAX_HISTORY */
char history[MAX_HISTORY][MAX_LINE+1]; /* history buffer and account for null term strs */

/**
 * Separates the inputBuffer into distinct tokens using whitespace as delimiters.
 *
 * parse_cmd() modifies the inputBuffer creating a set of null-terminated strings
 * and places pointers into the args[] array that point to the beginning of
 * each argument. A NULL pointer is placed in the args[] array indicating
 * the end of the argument list. This is what is needed for using execvp().
 */
void parse_cmd(char inputBuffer[], char *args[], int *background, int length)
{
   int i;       /* loop index for accessing inputBuffer array */
   int start;   /* index where beginning of next command parameter is */
   int ct;      /* index of where to place the next parameter into args[] */

   ct = 0;      
   start = -1;  /* Used as a flag to indicate that we are looking
                 * for the start of the command or an argument if
                 * it is a -1, or stores the starting position of
                 * the command or argument to be put in args[].
                 */
   /* examine every character in the inputBuffer */
   for (i=0; i<length; i++)
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

         case '\n':                /* should be the final char examined */
            if (start != -1)       /* if in the command or an argument */
            {
               args[ct] = &inputBuffer[start]; /* set up pointer in args[] */ 
               ct++;
            }
            inputBuffer[i] = '\0';
            args[ct] = NULL;       /* no more arguments to this command */
            break;

         default :                 /* some other character */
            if (start == -1 && inputBuffer[i] != '&')
               start = i;          /* starting position of the command or arg */
            if (inputBuffer[i] == '&')
            {
               *background  = 1;
               inputBuffer[i] = '\0';
            }
      }  /* end of switch */
   }  /* end of for loop looking at every character */
   args[ct] = NULL; /* just in case the input line was > 80 */
}

/**
 * If input is a history cmd, retrieve the most recent.
 * Otherwise, make sure it's valid input and notify caller.
 */
int check_cmd(char inputBuffer[], int length)
{
   int i, j, len;
   char c;
   if (length == 2 && inputBuffer[0] == 'r' && num_in_history > 0)
   {
      strncpy(inputBuffer, history[most_recent_index], MAX_LINE);
      len = strlen(inputBuffer);
      printf("%s", inputBuffer);
      return len; /* history found! Update length and send to execvp */
   }
   if (length == 4 && inputBuffer[0] == 'r' && inputBuffer[1] == ' ')
      c = inputBuffer[2];
   else return 0; /* send raw cmd to execvp */

   for (i=0,j=most_recent_index; i < num_in_history; i++, j--)
   {
      j = (j + MAX_HISTORY) % MAX_HISTORY; /* keep j within array bounds */
      if (c == history[j][0])
      {
         strncpy(inputBuffer, history[j], MAX_LINE);
         len = strlen(inputBuffer);
         printf("%s", inputBuffer);
         return len; /* history found! Update length and send to execvp */
      }
   }
   printf("No matching command in history\n");
   return -1; /* invalid cmd, get more input */
}

/**
 * Update pointers and such for tracking the MAX_HISTORY most recent cmds.
 */
void add_history(char inputBuffer[])
{
   most_recent_index = (most_recent_index + 1) % MAX_HISTORY;
   strncpy(history[most_recent_index], inputBuffer, MAX_LINE);
   current_history_num = (current_history_num + 1) % MAX_HISTORY_NUM;
   if (num_in_history < MAX_HISTORY)
      num_in_history++;
}

/**
 * Prints the most recent history, starting with the oldest cmd.
 */
void print_history()
{
   int i, j, oldest_history_num;
   oldest_history_num = current_history_num - num_in_history + 1;
   j = (most_recent_index - num_in_history + MAX_HISTORY + 1) % MAX_HISTORY;
   printf("\n");
   for (i = 0; i < num_in_history; i++, j++)
   {
      j %= MAX_HISTORY; /* keep j within array bounds */
      printf("% 3d  %s", oldest_history_num+i, history[j]);
   }
}

/**
 * get_cmd() reads in the next command line, checks for history cmds, ensures
 * the cmds are valid, and then passes back control to the caller.
 *
 * A ^d input at the beginning of a line, by a user, exits the shell.
 */
void get_cmd(char inputBuffer[], char *args[], int *background)
{
   int length; /* # of characters in the command line */
   int valid;  /* whether or not the cmd is valid */

   while (1) /* if a valid/historical cmd is entered then we return control */
   {         /*    to the caller, otherwise we get new input from user.     */
      printf(" COMMAND-> ");
      fflush(stdout);
      /* read what the user enters on the command line */
      length = read(STDIN_FILENO, inputBuffer, MAX_LINE);
      inputBuffer[length] = '\0'; /* make sure buffer overflow doesn't happen */

      if (show_history != 0)
      {
         print_history();
         show_history = 0;
         continue;
      }

      if (length == 0)
         exit(0);      /* ^d was entered, end of user command stream */
      if (length < 0)
      {
         perror("error reading the command");
         exit(-1);     /* terminate with error code of -1 */
      }
      if (length < 2)
         continue; /* the user just hit enter so ask for input again */

      valid = check_cmd(inputBuffer, length);
      if (valid >= 0)
      {
         if (valid > 0)
            length = valid;
         add_history(inputBuffer);
         parse_cmd(inputBuffer, args, background, length);
         return; /* sends the cmd to execvp */
      }
   }
} 

/**
 * A signal handler which tells the program to print the cmd line history.
 */
void handle_SIGQUIT( int junk )
{
   show_history = 1;
   return;
}

/**
 * Initialize cmd buffers and other things, then wait for and execute given cmds
 * in a child process, pausing until it finishes or just moving on as told by user.
 */
int main(void)
{
   char inputBuffer[MAX_LINE+1]; /* buffer to hold the command entered & null char */
   int background;               /* equals 1 if a command is followed by '&' */
   char *args[MAX_LINE/2];       /* command line (of 80) has max of 40 arguments */

   /* set up the signal handler */
   struct sigaction handler;
   /*handler.sa_flags = SA_RESTART;*/     /* wasn't necessary for me */
   handler.sa_handler = handle_SIGQUIT;   /* function the handler will call */
   sigaction(SIGQUIT, &handler, NULL);    /* handler to call for SIGQUIT signal */

   while (1)   /* Program terminates normally inside get_cmd */
   {
      background = 0;
      get_cmd(inputBuffer, args, &background);   /* get next command */

      pid_t pid, npid;
      pid = fork();
      if (pid == 0) /* child process is running */
      {
         execvp(args[0], args);
         printf("command not found\n");
         exit(-1);
      }
      else /* parent process is running */
      {
         if (background != 1)
         {
            do npid = waitpid(pid, NULL, 0);
            while (npid != pid);
         }
      }
   }
}

