#include "iostream"
#include "cstdlib"
#include "cstdio"
#include "cstring"
#include "netinet/in.h"
#include "sys/socket.h"
#include "unistd.h" // read close
#include "arpa/inet.h" // inet_pton
#include "Fmt.hpp"

#define PORT 8080

int	main()
{
	struct sockaddr_in	Server_address;
	int		Client_fd;
	int		valread;
	int		status;
	int		ret;
	char		buffer[1024] = { 0 };
	const char *msg = "this is major tom to ground control";

	Client_fd = socket(
		AF_INET,
		SOCK_STREAM,
		0
	);
	if ( Client_fd < 0 )
		return (perror("failed to create socket"), -1);

	Server_address.sin_family = AF_INET;
	Server_address.sin_port = htons(PORT);

	ret = inet_pton(
		AF_INET,
		"127.0.0.1",
		& Server_address.sin_addr
	);
	if (ret < 1)
		return (perror("invalid address"), -1);

	status = connect(
		Client_fd,
		(struct sockaddr *) & Server_address,
		sizeof( Server_address )
	);
	if (status < 0)
		return (perror("failed to connect"), -1);

	send(Client_fd, msg, strlen(msg), 0);
	std::cout << YELLOW << "Message sent. (client side)" nlreset;

	valread = read( Client_fd, buffer, 1024);
	std::cout << YELLOW << buffer << " (received by client)" << nlreset;
	

}




