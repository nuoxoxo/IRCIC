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


void	RPN(std::string expr, std::string compare)
{

	std::string	res = calc(expr);

	std::cout << "expression: " << YELLOW << expr << nlreset;
	std::cout << "result: " << GREEN << res << nlreset;
	if (compare == "")
		return ;
	assert(res == compare);
}

void	RPN(std::string expr, int compare)
{

	std::string	res = calc(expr);
	std::string	cmp = to_string(compare);

	std::cout << "expression: " << YELLOW << expr << nlreset;
	std::cout << "result: " << GREEN << res << nlreset;

	assert(res == cmp);
}

void	RPN(std::string e)
{
	std::string	res;

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
			return (false);
	}
	return (true);
}

