[ Subject ] - [intra](https://cdn.intra.42.fr/pdf/pdf/72125/en.subject.pdf) 

IRC networks have defaulted to listening on TCP port 6667 for plain   \
   text connections for a considerable time now.  This is covered by the  \
   IRCU assignment of TCP/UDP ports 6665-6669. 
   
   More about TCP port 6667 - [rfc-editor](https://www.rfc-editor.org/rfc/rfc7194)

|       |       |
|-------|-------|
Goal    | Create our own **IRC server** 
&#8239; | Use an <kbd>irssi</kbd> or <kbd>nc</kbd> to to test it 
Name    | <kbd> ./ircserve </kbd>
Run     | <kbd> ./ircserve _port_  _pass_ </kbd>
Files   | Makefile
&#8239; | `*.hpp, *.cpp, *.tpp, *.ipp`
&#8239; | `*.conf` (only one allowed)
Stuff   | socket
&#8239; | socket
&#8239; | setsockopt
&#8239; | z/OS
&#8239; | - getsockname
&#8239; | - getprotobyname
&#8239; | - gethostbyname
&#8239; | - getaddrinfo
&#8239; | freeaddrinfo
&#8239; | bind
&#8239; | connect
&#8239; | listen
&#8239; | accept
&#8239; | <arpa/inet.h>
&#8239; | - htons
&#8239; | - htonl
&#8239; | - ntohs
&#8239; | - ntohl
&#8239; | - inet_addr
&#8239; | - inet_ntoa
&#8239; | - send
&#8239; | - recv
&#8239; | - signal
&#8239; | - lseek
&#8239; | - fstat
&#8239; | - poll | select


[ Notes from Peers ] - [ircgod](https://ircgod.com/posts)  \
[ IRC Introduction ] - [harvard](https://cyber.harvard.edu/lawofcyberspace/irc.html)  \
[ IRC Guide w/ cmds ] - [fedora](https://fedoramagazine.org/beginners-guide-irc)  \
[ IRC Guide - basics ] - [libera](https://libera.chat/guides/basics)  \
[ IRC Guide - basics ] - [opensource](https://opensource.com/life/16/6/irc-quickstart-guide)  \
[ Socket Programming ] - [gfg](https://www.geeksforgeeks.org/socket-programming-cc/)
