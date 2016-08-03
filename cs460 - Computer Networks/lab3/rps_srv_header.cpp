/***********************************************************************
* Program:
*    Lab RockSrv, Rock/Paper/Scissors with Sockets - Server Code
*    Brother Jones, CS 460
* Author:
*    David Lambertson
* Summary:
*    This is the server side of a simple RPS game over the network.
*    it allows two players to connect and play a RPS game. The website below
*    is the source I used to help me.
*    http://www.linuxhowtos.org/C_C++/socket.htm
************************************************************************/

#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
using namespace std;

//Error display function
void error(const char *msg)
{
   cout << msg << endl;
   exit(1);
}

//The logic behind deciding who wins the game
string winner(string player1, string player2)
{
   string winner;
   if (!player1.compare(player2))
   { winner = "DRAW!"; }
   else if (!player1.compare("r") && player2.compare("s"))
      winner = "Player 1 is winner!";
   else if (!player1.compare("s") && player2.compare("r"))
      winner = "Player 2 is winner!";
   else if (!player1.compare("r") && player2.compare("p"))
      winner = "Player 2 is winner!";
   else if (!player1.compare("p") && player2.compare("r"))
      winner = "Player 1 is winner!";
   else if (!player1.compare("s") && player2.compare("p"))
      winner = "player 1 is winner!";
   else if (!player1.compare("p") && player2.compare("s"))
      winner = "Player 2 is winner!";

   return winner;
}

int main(int argc, char *argv[]) 
{
   
   if (argc < 2)
   {
      cout << "USAGE: [port number]\n";
      return 0;
   }
   
   int port = atoi(argv[1]);
   int sockfd, playerOne, playerTwo;
   socklen_t clilen;
   char buffer1[256], buffer2[256];
   int n;
   
   
   assert(port != 0);
   
   struct sockaddr_in serv_addr, cli_addr;
   
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   
   //Makes sure sockfd connected correctly
   assert(sockfd != 0);
   
   bzero((char *) &serv_addr, sizeof(serv_addr));
   
   
   serv_addr.sin_family = AF_INET;
   serv_addr.sin_addr.s_addr = INADDR_ANY; 
   serv_addr.sin_port = htons(port);
   
   if (bind(sockfd, (struct sockaddr *) &serv_addr,
            sizeof(serv_addr)) < 0) 
      error("ERROR on binding");
   
   listen(sockfd,5);
   clilen = sizeof(cli_addr);
   cout << "Waiting for Player 1\n";
   //connects player one
   playerOne = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
   if (playerOne < 0) error("ERROR connecting player one");
   
   //Telling player 1 who they are
   n = write(playerOne, "You are Player 1", 64);
   if (n < 0) error("ERROR writing to socket");

   //Connecting player 2
   cout << "Waiting for Player 2\n";
   playerTwo = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);   
   if (playerTwo < 0) error("ERROR on accept");
   //Telling player 2 who they are
   n = write(playerTwo, "You are Player 2", 64);
   if (n < 0) error("ERROR writing to socket");




   while(1)
   {
      string player1;
      string player2;
      cout << "MATCH" << endl;
      bzero(buffer1, 255);
      bzero(buffer2, 255);

      //Waits for the individual moves of each player
      cout << "WAITING FOR PLAYER 1 Move\n";
      n = read(playerOne, buffer1, 255);
      if (n < 0) error("ERROR reading from player 1");

      cout << "WAITING FOR PLAYER 2 Move\n";
      n = read(playerTwo, buffer2, 255);
      if(n < 0) error("ERROR reading from player 2");

      //converts to strings for ease of use
      player1 = tolower(buffer1[0]);
      player2 = tolower(buffer2[0]);

      if (!player1.compare("e") || !player2.compare("e"))
      {//closes the connection if the players are done
         cout << "CLOSING CONNECTIONS\n";
         break;
      }
      //gets the results of the game
      string tmp = winner(player1, player2);
      for (int i = 0; i < tmp.length(); i++)
      { buffer1[i] = buffer2[i] = tmp[i]; }

      //sends the results to each player
      n = write(playerOne, buffer1, 255);
      if (n < 0) error("ERROR writing to socket");
      n = write(playerTwo, buffer2, 255);
      if (n < 0) error("ERROR writing to socket");

   }

   //CLOSES
   close(playerOne);
   close(playerTwo);
   
   close(sockfd);
   return 0; 
}
