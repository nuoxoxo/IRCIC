# sender.py

import socket
from time import sleep

socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

while 1:
    socket.sendto(b'hello', ('127.0.0.1', 9998))
    print('sent data to socket_1')
    sleep(1)
    socket.sendto(b'hello', ('127.0.0.1', 9999))
    print('sent data to socket_2')
    sleep(1)

