#include "RPN.hpp"

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

void	test(std::string e, std::string compare, bool b)
{
	std::string	res;
	if (!b)
		return ;
	res = calc(e);

	std::cout << GREEN << res << nlreset;
}


std::string	calc(std::string line)
{
	std::stack<std::string>	E;
	std::string		s;
	std::string		expr = to_space_separated_string(line);
	std::stringstream	ss(expr);

	while (!ss.eof() && ss >> s)
	{
		if (s == "+" || s == "-" || s == "*" || s == "/")
		{
			int	r = 0, l = 0;

			if (s == "*" || s == "/")
			{
				r = 1;
				l = 1;
			}
			if (!E.size())
				return Error;

			std::stringstream(E.top()) >> r;
			E.pop();

			if (!E.size())
				return Error;

			std::stringstream(E.top()) >> l;
			E.pop();

			// dbg (to keep)
			// std::cout << l << " . " << r << " . " << s << nl;

			if (s == "+")
				E.push(to_string(l + r));
			else if (s == "-")
				E.push(to_string(l - r));
			else if (s == "*")
				E.push(to_string(l * r));
			else if (s == "/")
				E.push(to_string(l / r));
		}
		else if (isnumeric(s))
		{
			E.push(s);
		}
	}
	return (E.top());
}


std::string	to_space_separated_string(std::string& s)
{
	std::string	r;

	int	i = -1;
	while (++i < (int) s.length())
	{
		if (s[i] == ' ')
			continue ;
		r += s[i];
		r += ' ';
	}
	return (r);
}


//to_string not include in c++98
template<typename T>
std::string to_string(const T & value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

bool	isnumeric(std::string & s)
{
	size_t	i = -1;
	while (++i < s.length())
	{
		if (s[i] < '0' || s[i] > '9')
			return false;
	}
	return true;
}


