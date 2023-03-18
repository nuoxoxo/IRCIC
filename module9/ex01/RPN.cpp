#include "RPN.hpp"

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

void	RPN(std::string e, std::string compare)
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

void	RPN(std::string e, int compare)
{

	std::string	res = calc(e);
	std::string	cmp = to_string(compare);

	std::cout
	<< "expression: "
	<< YELLOW << e << nlreset
	<< "result: "
	<< GREEN << res << nlreset;

	assert(res == cmp);
}

void	RPN(std::string e, std::string compare, bool b) // overload trick
{
	std::string	res;

	if (!b)
		return ;
	res = calc(e);

	std::cout << GREEN << res << nlreset;
}

void	default_debugger(void)
{
	std::cout << CYAN "::: misc. :::" nl2reset;

	RPN("3 4 +", 7);
	RPN("3 5 6 + *", 33);
	RPN("3 10 5 + *", 5);
	RPN("12 * 2 / 5 + 46 * 6 / 8 * 2 / + 2 * 2 -", 42);
	RPN("99 3 -4 + 2 - 6 + -2 +", -3);
	RPN("123 + -2 3 * 7 + -4 +", -13);
	RPN("4 12 -764 + 23 * 23 1 -", 2);
	RPN("3 -4 5 + -", Error);

	std::cout << CYAN "\n::: Subject tests :::" nl2reset;

	RPN("8 9 * 9 - 9 - 9 - 4 - 1 +", "42");
	RPN("7 7 * 7 -", "42");
	RPN("1 2 * 2 / 2 * 2 4 - +", "0");
	RPN("(1 + 1)", Error);
	RPN("(1 2 + 1)", "1");
	RPN("1 + (2 + 1)", Error);

	std::cout << CYAN "\n::: GeeksforGeeks :::" nl2reset;

	RPN("1 + 0 6 9 3 + -11 * / * 17 + 5 +", Error);
	RPN("10 6 9 3 + -11 * / * 17 + 5 +", "13");
	RPN("2 1 + 3 *", "9");
	RPN("21 +3*", "9");
	RPN("4135/+", "1");
	RPN("4 13 5 / +", "1");

	std::cout << CYAN "\n::: Eval :::" nl2reset;

	RPN("8 9 * 9 - 9 - 9 - 4 - 1 +", "42");
	RPN("9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -", "42");
	RPN("1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /", "15");
}

