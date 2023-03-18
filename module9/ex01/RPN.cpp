#include "RPN.hpp"

std::string	calc(std::string line)
{
	std::stack<std::string>	E;
	std::string		token;
	int			a, b;

	std::string		expr = to_space_separated_string(line);
	std::stringstream	ss(expr);

	while (!ss.eof() && ss >> token)
	{
		if (isnumeric(token))
			E.push(token);
		if (token != "+" && token != "-" && token != "*" && token != "/")
			continue ;
		a = b = 0;
		if (token == "*" || token == "/")
			a = b = 1;
		if (!E.size())
			return Error;
		std::stringstream(E.top()) >> b;
		E.pop();
		if (!E.size())
			return Error;
		std::stringstream(E.top()) >> a;
		E.pop();
		if (token == "+")
			E.push(to_string(a + b));
		else if (token == "-")
			E.push(to_string(a - b));
		else if (token == "*")
			E.push(to_string(a * b));
		else if (token == "/")
			E.push(to_string(a / b));
	}
	return (E.top());
}


std::string	to_space_separated_string(std::string& token)
{
	std::string	b;
	int		i;

	i = -1;
	while (++i < (int) token.length())
	{
		if (token[i] == ' ')
			continue ;
		b += token[i];
		b += ' ';
	}
	return (b);
}


//to_string not include in c++98
template<typename T>
std::string to_string(const T & value)
{
	std::ostringstream	oss;

	oss << value;
	return (oss.str());
}

bool	isnumeric(std::string & token)
{
	size_t	i = -1;
	while (++i < token.length())
	{
		if (token[i] < '0' || token[i] > '9')
			return false;
	}
	return true;
}


void	test(std::string e, std::string compare)
{
	std::string	res = calc(e);

	std::cout
	<< "expression: "
	<< YELLOW << e << nlreset
	<< "result: "
	<< GREEN << res << nlreset;

	if (compare != "")
	{
		assert(res == compare);
	}
}

void	test(std::string e, int compare)
{
	test(e, to_string(compare));
}

void	test(std::string e, std::string compare, bool b) // overload trick
{
	std::string	res;

	if (!b)
		return ;
	res = calc(e);

	std::cout << GREEN << res << nlreset;
}


