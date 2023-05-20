
import select

import socket

import os

 

serverSocket    = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

serverSocket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

 

ipAddress   = '127.0.0.1'

portNumber  = 20000

 

serverSocket.bind((ipAddress, portNumber))

serverSocket.listen()

 

pollerObject = select.poll()

pollerObject.register(serverSocket, select.POLLIN)

 

while(True):

    fdVsEvent = pollerObject.poll(10000)

    for descriptor, Event in fdVsEvent:

        print("Got an incoming connection request")

        print("Start processing")

        # Do accept() on server socket or read from a client socket

 
