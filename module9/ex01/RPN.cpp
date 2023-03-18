#include "RPN.hpp"

// creme 

void	calc(std::string line)
{
	std::cout << GREEN << RPN(line) << nlreset;
}


// la creme de la creme

std::string	RPN(std::string line)
{
	std::stack<std::string>	E;
	std::string		token;
	int			a, b;

	std::string		expr = to_space_separated_string(line);
	std::stringstream	ss(expr);

	while (!ss.eof() && ss >> token)
	{
		if (token <= "9" && token >= "0")
		{
			E.push(token);
			continue ;
		}

		if (token != "+" && token != "-" && token != "*" && token != "/")
		{
			std::cout << token << std::endl;
			continue ;
		}
		if (E.size() < 2)
		{
			return Error;
		}
		std::stringstream(E.top()) >> b;
		E.pop();
		std::stringstream(E.top()) >> a;
		E.pop();
		if (token == "+")
		{
			E.push(to_string(a + b));
		}
		else if (token == "-")
		{
			E.push(to_string(a - b));
		}
		else if (token == "*")
		{
			E.push(to_string(a * b));
		}
		else if (token == "/")
		{
			E.push(to_string(a / b));
		}
	}
	return (E.top());
}


void	calc(std::string expr, int compare)
{

	std::string	res = RPN(expr);
	std::string	cmp = to_string(compare);

	std::cout << "expression: " << YELLOW << expr << nlreset;
	std::cout << "result: " << GREEN << res << nlreset;

	assert(res == cmp);
}

void	calc(std::string expr, std::string compare)
{

	std::string	res = RPN(expr);

	std::cout << "expression: " << YELLOW << expr << nlreset;
	std::cout << "result: " << GREEN << res << nlreset;
	if (compare == "")
		return ;
	assert(res == compare);
}


// util

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


void	default_debugger(void)
{
	std::cout << CYAN "::: misc. :::" nl2reset;

	calc("3 4 +", 7);
	calc("3 5 6 + *", 33);
	calc("3 10 5 + *", 5);
	calc("12 * 2 / 5 + 46 * 6 / 8 * 2 / + 2 * 2 -", 42);
	calc("99 3 -4 + 2 - 6 + -2 +", -3);
	calc("123 + -2 3 * 7 + -4 +", -13);
	calc("4 12 -764 + 23 * 23 1 -", 2);
	calc("3 -4 5 + -", Error);

	std::cout << CYAN "\n::: Subject tests :::" nl2reset;

	calc("8 9 * 9 - 9 - 9 - 4 - 1 +", "42");
	calc("7 7 * 7 -", "42");
	calc("1 2 * 2 / 2 * 2 4 - +", "0");
	calc("(1 + 1)", Error);
	calc("(1 2 + 1)", "1");
	calc("1 + (2 + 1)", Error);

	std::cout << CYAN "\n::: GeeksforGeeks :::" nl2reset;

	calc("1 + 0 6 9 3 + -11 * / * 17 + 5 +", Error);
	calc("10 6 9 3 + -11 * / * 17 + 5 +", "13");
	calc("2 1 + 3 *", "9");
	calc("21 +3*", "9");
	calc("4135/+", "1");
	calc("4 13 5 / +", "1");

	std::cout << CYAN "\n::: Eval :::" nl2reset;

	calc("8 9 * 9 - 9 - 9 - 4 - 1 +", "42");
	calc("9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -", "42");
	calc("1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /", "15");
}



//to_string not include in c++98
template<typename T>
std::string to_string(const T & value)
{
	std::ostringstream	oss;

	oss << value;
	return (oss.str());
}

