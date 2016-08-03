#############################################################################
# Program:
#    Lab PythonWebServer, Computer Communication and Networking
#    Brother Jones, CS 460
# Author:
#    Bit Kim
# Summary:
#    HTTP Web Server implementation using Python programming language
#
# Note: If you put #!/usr/bin/python as the first line of this file and
#       make the program executable, the submit command will not be happy.
#       Run your Python program using:  python yourCode.py
#
#############################################################################
import sys
import re
import os.path
from socket import *

def get_file(file_path, content_type):

   if os.path.isfile(file_path):

      # plain text
      if re.match('text', content_type) != None:
         return open(file_path, "r").read()

      # binary
      else:
         return open(file_path, "rb").read()

   # no file
   else:
      return False

def content_type(file_name):

   if file_name.endsWith(".htm") or file_name.endsWith(".html"):
     return "text/html"
   
   if file_name.endsWith(".gif"):
     return "image/gif"
   
   if file_name.endsWith(".png"):
     return "image/png"
   
   if file_name_endsWith(".jpg"):
     return "image/jpeg"

   return "application/pcetet-stream"


################
# MAIN FUNCTION!
################
def main():
   CRLF = "\r\n"
   DEFAULT_PORT = 6789
   port = int(sys.argv[1]) if len(sys.argv) == 2 else DEFAULT_PORT

   serverSocket = socket(AF_INET, SOCK_STREAM)
   serverSocket.bind(('', port))
   serverSocket.listen(1)

   try:
      connectionSocket, addr = serverSocket.accept()
      header = connectionSocket.recv(8192)
      
      print header.split("\n")[0]
      
      file_name = "." + header.split("\n")[0].split(" ")[1];
      
      con_type = content_type(file_name);
      
      contents = get_file(file_name, con_type)
      
      if contents:
         response =  "HTTP/1.0 200 OK" + CRLF + \
                     "Content-type: " + content_type(filetype) + CRLF + CRLF + contents

      else:
         response = "HTTP/1.0 404 Not Found" + CRLF + \
             "Content-type: text/html" + CRLF + CRLF + """
              <html>
                     <head><title>%s Not Found</title></head> +
                     <body><p> "%s" Was Not Found</p></body>
              </html>
            """ % (file_name, file_name)
         
         connectionSocket.send(response)
         connectionSocket.close()
   except KeyboardInterrupt:
      print "\nServer Disconnecting"
   
   serverSocket.close()
      
      
if __name__ == "__main__":
       main()
