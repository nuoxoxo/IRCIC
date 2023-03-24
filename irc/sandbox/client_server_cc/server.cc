#include "iostream"
#include "netinet/in.h"
#include "sys/socket.h"
#include "unistd.h" // read close
#include "cstring" // strlen
#include "cstdio" // perror
#include "Fmt.hpp"

#define PORT 8080

int	main()
{
	struct sockaddr_in	address;
	int		Server_fd;
	int		new_socket;
	int		valread;
	int		ret;
	int		opt = 1;
	int		addrlen = sizeof(address);
	char		buffer[1024] = { 0 };
	const char *msg = "this is ground control to major tom"; // doubt: keyword const

	// SOCKET Creation
	//  generate a socker fd
	Server_fd = socket(
		AF_INET, /* domain */
		// AF_INET or AF_INET6 - between procs on different hosts (IPV6)
		// AF_LOCAL - between procs on the same host
		SOCK_STREAM, /* communication type */
		// SOCK_STREAM - TCP
		// SOCK_DGRAM - UDP
		0 /* protocol */
	);
	if ( Server_fd < 0 )
		return (perror("failed to create socket"), -1);


	// ATTACH
	//  attach socket to port 8080
	ret = setsockopt(
		Server_fd,
		SOL_SOCKET,
		SO_REUSEADDR | SO_REUSEPORT,
		& opt,
		sizeof(opt)
	);
	if (ret)
		return (perror("setsockopt error"), -1);
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT /* 8080 */);


	// BIND
	//  binds the socket to the address and port number specified in addr
	ret = bind(
		Server_fd,
		(struct sockaddr *) & address,
		sizeof(address)
	);
	if (ret < 0)
		return (perror("bind error"), -1);

	// LISTEN
	ret = listen(
		Server_fd,
		3
	);
	if (ret < 0)
		return (perror("listen failed"), -1);

	// ACCEPT
	new_socket = accept(
		Server_fd,
		(struct sockaddr *) & address,
		(socklen_t *) & addrlen
	);
	if (new_socket < 0)
		return (perror("accept failed"), -1);

	// READ
	valread = read(
		new_socket,
		buffer,
		1024
	);
	std::cout << CYAN << buffer << " (received by server)" << nlreset;

	// SEND
	send(new_socket, msg, strlen(msg), 0);
	std::cout << CYAN << "Message sent. (server side)" nlreset;

	// CLOSE Socket (client)
	close(new_socket);
	shutdown(Server_fd, SHUT_RDWR);
}


