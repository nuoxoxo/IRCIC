# receiver.py

import socket
import select

socket_1 = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
socket_2 = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

socket_1.bind(('127.0.0.1', 9998))
socket_2.bind(('127.0.0.1', 9999))

poller = select.poll()

poller.register(socket_1, select.POLLIN)
poller.register(socket_2, select.POLLIN)

while 1:
    evts = poller.poll(5000)
    for sock, evt in evts:
        if evt and select.POLLIN:
            if sock == socket_1.fileno():
                socket_1.recvfrom(4096)
                print('received poll event from socket_1')
            if sock == socket_2.fileno():
                socket_2.recvfrom(4096)
                print('received poll event from socket_2')

