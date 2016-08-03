/***********************************************************************
* Program:
*    Lab RockClient, Rock/Paper/Scissors with Sockets - Client Code
*    Brother Jones, CS 460
* Author:
*    David Lambertson
* Summary:
*    Client side code that allows two people to play a game of RPS.
************************************************************************/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
using namespace std;


void error(const char *msg)
{
   cout << msg << endl;
   exit(0);
}

int main(int argc, char *argv[]) 
{
   if (argc < 3)
   {
      cout << "USAGE: [host name] [port number]\n";
      return 0;
   }

   int port = atoi(argv[2]);


   int sockfd, n;
   struct sockaddr_in serv_addr;
   struct hostent *server;

   char buffer[256];

   //Connecting to the Server
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   if (sockfd < 0) 
      error("ERROR opening socket");

   server = gethostbyname(argv[1]);

   if (server == NULL) {
      fprintf(stderr,"ERROR, no such host\n");
      exit(0);
   }
   bzero((char *) &serv_addr, sizeof(serv_addr));
   serv_addr.sin_family = AF_INET;
   bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
   serv_addr.sin_port = htons(port);
   if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
      error("ERROR connecting");

   //display what player number they are
   n = read(sockfd,buffer,255);
   if (n < 0) error("ERROR reading from socket");
   printf("%s\n",buffer);
   while(1)
   {
      //prompts the user for their move
      printf("Choose(R P S): ");
      bzero(buffer,256);
      fgets(buffer,255,stdin);
      
      //sends it to the server
      n = write(sockfd,buffer,strlen(buffer));
      if (n < 0) error("ERROR writing to socket");

      //closes if given an 'e'
      if (!buffer[0] == 'e') {break;}
      bzero(buffer,256);
      

      //this will be for showing who wins
      n = read(sockfd,buffer,255);
      if (n < 0) error("ERROR reading from socket");
      printf("%s\n",buffer);
   }
   close(sockfd);
   return 0;
}
