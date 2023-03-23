#include "iostream"
#include "netinet/in.h"
#include "sys/socket.h"

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
	char		*msg = "server call to major tom";

	// generate a socker fd
	Server_fd = socket(
		AF_INET, /* domain */
		SOCK_STREAM,
		0
	);
	if ( Server_fd < 0 )
	{
		return (perror"socket sick");
		exit(EXIT_FAILUER)
	}


	// attach socket to port 8080
	ret = setsockopt(
		Server_fd,
		SOL_SOCKET,
		SO_REUSEADDR | SO_REUSEPORT,
		& opt,
		sizeof(opt)
	);
	if (ret)
	{
		perror("setsockopt cold");
		exit(EXIT_FAILUER);
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT /* 8080 */);


	// bind function:
	//  binds the socket to the address and port number specified in addr
	red = bin(
		Server_fd,
		(struct sockaddr *) & address,
		sizeof(address)
	);
	if (ret < 0)
	{
		perror("ill bind");
		exit(EXIT_FAILUER);
	}

}


