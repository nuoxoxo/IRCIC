#include "RPN.hpp"

// creme 

void	calculator(std::string line)
{
	std::cout << GREEN << RPN(line) << nlreset;
}


// la creme de la creme

std::string	RPN(std::string line)
{
	std::stack<std::string>	E;
	std::string		token;
	std::string		expr;
	int			a, b;


	// ERROR MGMT

	if (!check_expression(line))
	{
		return (Error);
	}
	expr = to_space_separated_string(line);
	if (expr == Error)
	{
		return (expr);
	}


	// Get 'em one by one

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
			continue ;
		}
		if (E.size() < 2)
		{
			return (Error);
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


void	calculator(std::string expr, int compare)
{
	std::string	res = RPN(expr);
	std::string	cmp = to_string(compare);

	std::cout << "expression: " << YELLOW << expr << nlreset;
	std::cout << "result: " << GREEN << res << nlreset;

	assert(res == cmp);
}

void	calculator(std::string expr, std::string compare)
{
	std::string	res = RPN(expr);

	std::cout << "expression: " << YELLOW << expr << nlreset;
	std::cout << "result: " << GREEN << res << nlreset;

	if (compare == "")
		return ;

	assert(res == compare);
}


// util

std::string	to_space_separated_string(std::string token)
{
	std::string	res;
	int		i;

	i = -1;
	while (++i < (int) token.length())
	{
		if (token[i] == ' ' || (token[i] < 14 && token[i] > 8))
		{
			continue ;
		}
		res += token[i];
		res += ' ';
	}
	if (res == "" || res == " ")
	{
		return (Error);
	}
	return (res);
}

bool	check_expression(std::string & expr)
{
	int	i = -1;

	while (++i < (int) expr.length())
	{
		if (expr[i] == ' '
			|| (expr[i] < 14 && expr[i] > 8)
			|| (expr[i] <= '9' && expr[i] >= '0')
			|| expr[i] == '+' || expr[i] == '-'
			|| expr[i] == '*' || expr[i] == '/'
			|| expr[i] == '(' || expr[i] == ')'
		)
		{
			continue ;
		}
		return (false);
	}
	return (true);
}


void	debugger(void)
{
	std::cout << CYAN "::: misc. :::" nl2reset;

	calculator("3 4 +", 7);
	calculator("3 5 6 + *", 33);
	calculator("3 10 5 + *", 5);
	calculator("12 * 2 / 5 + 46 * 6 / 8 * 2 / + 2 * 2 -", 42);
	calculator("99 3 -4 + 2 - 6 + -2 +", -3);
	calculator("123 + -2 3 * 7 + -4 +", -13);
	calculator("4 12 -764 + 23 * 23 1 -", 2);
	calculator("3 -4 5 + -", Error);

	std::cout << CYAN "\n::: Subject tests :::" nl2reset;

	calculator("8 9 * 9 - 9 - 9 - 4 - 1 +", "42");
	calculator("7 7 * 7 -", "42");
	calculator("1 2 * 2 / 2 * 2 4 - +", "0");
	calculator("(1 + 1)", Error);
	calculator("(1 2 + 1)", "1");
	calculator("1 + (2 + 1)", Error);

	std::cout << CYAN "\n::: GeeksforGeeks :::" nl2reset;

	calculator("1 + 0 6 9 3 + -11 * / * 17 + 5 +", Error);
	calculator("10 6 9 3 + -11 * / * 17 + 5 +", "13");
	calculator("2 1 + 3 *", "9");
	calculator("21 +3*", "9");
	calculator("4135/+", "1");
	calculator("4 13 5 / +", "1");

	std::cout << CYAN "\n::: Eval :::" nl2reset;

	calculator("", "Error");
	calculator(" ", "Error");
	calculator("  ", "Error");
	calculator("", "Error");
	calculator("\b", "Error");
	calculator("\t", "Error");
	calculator("\n", "Error");
	calculator("\v", "Error");
	calculator("\f", "Error");
	calculator("\r", "Error");
	calculator("8 9 * 9 - 9 - 9 - 4 - 1 +", "42");
	calculator("9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -", "42");
	calculator("1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /", "15");
}


//to_string not include in c++98
template<typename T>
std::string to_string(const T & value)
{
	std::ostringstream	oss;

	oss << value;
	return (oss.str());
}

