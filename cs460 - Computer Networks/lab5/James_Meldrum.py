#############################################################################
# Program:
#    Lab PythonWebServer, Computer Communication and Networking
#    Brother Jones, CS 460
# Author:
#    James Meldrum
# Summary:
#    This is a program that receives a request to deploy data to a web page.
#
# Note: If you put #!/usr/bin/python as the first line of this file and
#       make the program executable, the submit command will not be happy.
#       Run your Python program using:  python yourCode.py
#
#############################################################################

from socket import *
import sys

CRLF = "\r\n"

#returns the correct http content type for the given file name
def get_http_file_type(filename):
    if(filename.endswith(".htm") or filename.endswith(".html")):
       return "text/html"        
    if(filename.endswith(".gif")):
       return "image/gif"
    if(filename.endswith(".png")):
       return "image/png"
    if(filename.endswith(".txt")):
       return "text/html"
    if(filename.endswith(".jpg") or filename.endswith(".jpeg")):
       return "image/jpeg"
    return "application/octet-stream"

#sets default port for the server or allows command line input
DEFAULT_VALUE = 6789
argument1 = int(sys.argv[1]) if len(sys.argv) == 2 else DEFAULT_VALUE
serverPort = argument1

#bind to socket and begin listening
serverSocket = socket(AF_INET, SOCK_STREAM)
serverSocket.bind(('', serverPort))
serverSocket.listen(1)
print 'The Server is ready to receive'

try:
   while 1:
      connectionSocket, addr = serverSocket.accept()
      sentence = connectionSocket.recv(4096)
      #gets the filename requested
      words = sentence.split( ' ' )
      print words[1]
      filename = "." + words[1]
      fis = ""
      fileExists = True
      dataToSend = ""
      statusLine = ""
      contentType = ""
      
      try:
         fis = open(filename, 'rb')
         dataToSend = fis.read()
      except:#error if the file doesn't exist
         fileExists = False

      if fileExists: #sets content type and status line for valid filename
         statusLine = "HTTP/1.1 200 OK" + CRLF
         contentType = "Content-Type: " + get_http_file_type( filename ) + CRLF
      else:#not found error if file not found
         statusLine = "HTTP/1.1 404 Not Found" + CRLF
         contentType = "Content-Type: text/html" + CRLF
         dataToSend  = "<HTML><HEAD><TITLE>Not Found</TITLE></HEAD><BODY>Not Found</BODY></HTML>"
      
      print statusLine
      print contentType
      #send data to client
      connectionSocket.send(statusLine)
      connectionSocket.send(contentType)
      connectionSocket.send(CRLF)
      connectionSocket.send(dataToSend)
      #close for next iteration
      connectionSocket.close()
except KeyboardInterrupt:
   print "\nClosing Server"
   serverSocket.close()

