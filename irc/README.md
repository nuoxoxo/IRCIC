Socket Programming - [gfg](https://www.geeksforgeeks.org/socket-programming-cc/)

Socket programming is a way of connecting ***two nodes*** on a network to communicate with each other.  \
One socket (node) listens on a particular ***port*** at an IP, while the other socket reaches out to the other to form a connection.

The server forms the ***listener socket*** while the client reaches out to the server.



[ Subject ] - [intra](https://cdn.intra.42.fr/pdf/pdf/72125/en.subject.pdf) 

IRC networks have defaulted to listening on TCP port 6667 for plain   \
   text connections for a considerable time now.  This is covered by the  \
   IRCU assignment of TCP/UDP ports 6665-6669. 
   
   More about TCP port 6667 - [rfc-editor](https://www.rfc-editor.org/rfc/rfc7194)


[ Notes from Peers ] - [ircgod](https://ircgod.com/posts)  \
[ IRC Introduction ] - [harvard](https://cyber.harvard.edu/lawofcyberspace/irc.html)  \
[ IRC Guide w/ cmds ] - [fedora](https://fedoramagazine.org/beginners-guide-irc)  \
[ IRC Guide - basics ] - [libera](https://libera.chat/guides/basics)  \
[ IRC Guide - basics ] - [opensource](https://opensource.com/life/16/6/irc-quickstart-guide)  \


![](https://i.imgur.com/CjhDkz2.png)

|       |       |       |
|-------|-------|-------|
Goal    | Create our own **IRC server** 
&#8239; | Use an <kbd>irssi</kbd> or <kbd>nc</kbd> to to test it 
Name    | <kbd> ./ircserve </kbd>
Run     | <kbd> ./ircserve _port_  _pass_ </kbd>
Files   | `*.hpp`
&#8239; | `*.cpp`
&#8239; | `*.tpp`
&#8239; | `*.ipp`
&#8239; | `*.conf` (only one allowed)
&#8239; | Makefile
Stuff   | setsockopt | socket
&#8239; | getsockname
&#8239; | getprotobyname
&#8239; | gethostbyname
&#8239; | getaddrinfo
&#8239; | freeaddrinfo
&#8239; | bind
&#8239; | connect
&#8239; | listen
&#8239; | accept
&#8239; | send
&#8239; | recv
&#8239; | accept
&#8239; | accept
&#8239; | htons
&#8239; | htonl
&#8239; | ntohs
&#8239; | ntohl
&#8239; | inet_addr | arpa/inet.h
&#8239; | inet_ntoa
&#8239; | lseek     | misc.
&#8239; | fstat
&#8239; | poll
&#8239; | selelct

