# NetworksProject
Braden Steiner, David Lambertson
ReadMe
Usage
To use the program you would need to download all the files for the given game found at https://github.com/drrezeau/NetworksProject. You would have to run the game (file is project.html in the Webgl folder) locally and it takes two to play. When it first opens, it asks the user for a username. This is used to create and ID with the remote PeerJS server. Using this ID, you are able to connect with peers. After connecting with the remote server, you then are prompted to enter your friend’s ID. This is used to connect the two of you together. The game waits for roughly 4 seconds to allow the connection to finish and the game loads. While waiting the game shows controls. Then you battle till the Death!

Step 1:Enter your Username
Step 2:Enter friend’s username
Step 3:Play game!!

Note: Every time you want a new game you will have to reconnect.

Files:
Project.html
This file contains all of the beginning code which runs the game and receives the username and the opponent username from the player. It will call functions within many of the other files in the game. We had to change some of the code in each version to ensure that each player controlled a different tank(See line 354: one must be true, while the other is false). To pass what buttons were being pressed, we have a commands variable (see line 547) which we then pass to sendData. sendData can be found in the peer2.js. We also made sure that the opponent controls were coming from the peer2peer connection. 

Peer2.js
This file contains all of the code to connect to the server, then using the opponent username to connect directly to the other player. We had to make sure that the listener was only instantiated once and the user controls were sent for each frame of the game. We have four important functions in this file: connect2Server, connect2Peer, sendData, and receiveData. The first two are used to establish connections for the peer2peer to work properly. The last 2 send and receive data between the two peers.

PeerTest.html
This file is a test. This is how we started to learn about PeerJS to allow us to use it. In it it contains code to connect to the remote server to make peer-to-peer connections possible. It shows our progress before we inserted code into the game.
