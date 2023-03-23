#include "Fmt.hpp"
#include "Server.hpp"

int	main(int c, char **v)
{
	if (c ^ 3 || argv_is_invalid(v[1]) || argv_is_invalid(v[2]))
	{
		return (_usage_(), 0 /*1*/);
	}

	// Rainbow test

	std::string	arr[5] = {ITAL, CYAN, YELLOW, GREEN, LOWKEY};
	int		i = -1;

	while (++i < 6)
	{
		std::cout << ( i < 5 ? arr[i] : "" ) << "Hello, World! " nlreset;
	}
	std::cout << nl;

	// Start server here

	std::string	port(v[1]), pass(v[2]);
	IRCServer	server(port, pass);

	std::cout
	<< "name: " << server.get_name() << nl
	<< "port: " << server.get_port() << nl
	<< "pass: " << RED << server.get_pass_might_delete() << nl2reset;

}

