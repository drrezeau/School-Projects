/***********************************************************************
 * Program:
 *    Lab UnixShell
 *    Brother Jones, CS 345
 * Author:
 *    Benjamin Walker
 * Summary:
 *    This program creates an interface to execute command-line commands
 *    other than the normal command-line interface. Also the ^\ signal is
 *    overwritten as to accommodate for printing the history of entered
 *    commands rather than quitting the process.
 ************************************************************************/

/************************************************************************
Input/output example:

[brw59@AUS213L28 lab3]$ gcc shell.c -o attempt1
[brw59@AUS213L28 lab3]$ attempt1
 COMMAND-> ls
a.out     sampleShell     shell.c   shellHistory.cpp   shell_ptr_type.c  signal.c       UnixShellT2.txt
attempt1  shell_backup.c  shell.c~  shellHistory.cpp~  sigANSI.c         temp_signal.h  UnixShell.txt
 COMMAND-> pwd
/home/wal10007/345/labs/lab3
 COMMAND-> dir
a.out     sampleShell     shell.c   shellHistory.cpp   shell_ptr_type.c  signal.c       UnixShellT2.txt
attempt1  shell_backup.c  shell.c~  shellHistory.cpp~  sigANSI.c         temp_signal.h  UnixShell.txt
 COMMAND-> ls -la
total 116
drwx------ 2 brw59 student  4096 Feb  5 11:38 .
drwx------ 7 brw59 student  4096 Feb  3 13:25 ..
-rwx------ 1 brw59 student  7354 Jan 29 13:30 a.out
-rwx------ 1 brw59 student  9721 Feb  5 11:38 attempt1
-rwx------ 1 brw59 student  5924 Jan 29 13:24 sampleShell
-rw------- 1 brw59 student  6489 Feb  5 11:32 shell_backup.c
-rw------- 1 brw59 student  6798 Feb  5 11:37 shell.c
-rw------- 1 brw59 student  6489 Feb  5 11:31 shell.c~
-rw------- 1 brw59 student  7125 Feb  4 14:33 shellHistory.cpp
-rw------- 1 brw59 student  7119 Jan 29 13:24 shellHistory.cpp~
-rw------- 1 brw59 student  4923 Jan 29 13:24 shell_ptr_type.c
-rw------- 1 brw59 student  1944 Jan 29 13:24 sigANSI.c
-rw------- 1 brw59 student  2064 Jan 29 13:24 signal.c
-rw------- 1 brw59 student 13662 Feb  4 15:10 temp_signal.h
-rw------- 1 brw59 student   603 Jan 29 13:24 UnixShellT2.txt
-rw------- 1 brw59 student   269 Jan 29 13:24 UnixShell.txt
 COMMAND-> ^\
ls
pwd
dir
ls -la

 COMMAND->

************************************************************************/

#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_LINE 80 /* 80 chars per line, per command, should be enough. */

// char message[MAX_LINE];
char history[10000][MAX_LINE]; // holds up to 10,000 history commands
int historyCount = 0;
int commandNumber = 0; // we only want to display the last 10 commands

// I had trouble using for loops earlier ... after an hour I realized that you can't
// initiallize a variable in the for loop: "for (int i = 0; ...." I made this recursive
// function to replace my for loop before I figured that out
void recursive_print(int count)
{
   if (count == 0)
      return;
   
   int size = strnlen(history[--count]);
   write(STDOUT_FILENO, history[count], size);
}

/*****
 * This is the function that overwrites the default signal handler for SIGQUIT
 *****/
void sig_handler(int signo)
{
   if (signo == SIGQUIT)
   {
      int i = commandNumber;
      printf("\n");
      for (; i <= historyCount; i++)
         recursive_print(i);
   }
   
}


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

   if (historyCount >= 10)
      commandNumber++; // should trail the commandNumber 10 behind

   // This converts the data from a pointer array (inputBuffer) to a double array (history)
   for (i = 0; i < MAX_LINE - 1; i++)
      history[historyCount][i] = inputBuffer[i];
   // we need to make sure the array ends with a NULL character, otherwise it will be broken
   history[historyCount++][MAX_LINE - 1]= '\0'; 

   
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

/****************************************************
 * main()
 * The error handling is setup before input is first
 * read.
 * A new fork is then created and the input processes
 * a system command. The & is taken into account
 * as to allow for parallel processes at the same time
 ****************************************************/
int main(void)
{
   char inputBuffer[MAX_LINE]; /* buffer to hold the command entered */
   int background;             /* equals 1 if a command is followed by '&' */
   char *args[MAX_LINE/2];   /* command line (of 80) has max of 40 arguments */
    
   while (1)                   /* Program terminates normally inside setup */
   {
      background = 0;
      printf(" COMMAND-> ");
      fflush(stdout);

      struct sigaction errorHandler;
      errorHandler.sa_handler = sig_handler;
      errorHandler.sa_flags = SA_RESTART;
      sigaction(SIGQUIT, &errorHandler, NULL);

      setup(inputBuffer, args, &background);       /* get next command */

      /* the steps are:
       * (1) fork a child process using fork()
       * (2) the child process will invoke execvp()
       * (3) if background != 1, the parent will wait,
       *     for the command to complete; otherwise,
       *     setup() gets called to process the next command line. 
       */ 

      
      pid_t pid;
      pid = fork();

      if (pid < 0)
         return 1;

      // if there is not an '&' on the command line evaluated from 'setup()',
      // then the process needs to wait before continuing 
      if (!background)
      {
         // this is asking the parent to wait for the child to finish
         waitpid(pid, NULL, 0);
      }

      if (pid == 0)
      {
         if (-1 == execvp(args[0],args)) // if it's an illegal call
         {
            printf("command not found\n");
            return 1;
         }
      }

   }
}

