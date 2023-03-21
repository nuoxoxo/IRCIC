#include "RPN.hpp"

//	calculator & its overloads

void	calculator(std::string line)
{
	std::cout << GREEN << RPN(line) << nlreset;
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


//	creme

std::string	RPN(std::string expr)
{
	std::stack<std::string>	E;
	char			token;
	int			a, b, i;

	if (!check_expression(expr))
		return (Error);
	if (expr == Error)
		return (expr);
	i = -1;
	while (++i < (int) expr.length())
	{
		token = expr[i];

		if (token <= '9' && token >= '0')
		{
			E.push(std::string(1, token));
			continue ;
		}
		if (token != '+' && token != '-' && token != '*' && token != '/')
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
		if (token == '+')
		{
			E.push(to_string(a + b));
		}
		else if (token == '-')
		{
			E.push(to_string(a - b));
		}
		else if (token == '*')
		{
			E.push(to_string(a * b));
		}
		else if (token == '/')
		{
			if (!b)
				return (Error);
			E.push(to_string(a / b));
		}
	}
	if (!E.empty())
		return (E.top());
	return (Error);
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
	header("Sanity tests");

	calculator("", "Error");
	calculator("(", "Error");
	calculator("a", "Error");
	calculator("[", "Error");
	calculator("}", "Error");
	calculator("((", "Error");
	calculator("((", "Error");
	calculator("()", "Error");
	calculator("{}", "Error");
	calculator("1 2 3 4 +++//", "Error");
	calculator("~", "Error");
	calculator("*", "Error");
	calculator("&", "Error");
	calculator(".", "Error");
	calculator("@", "Error");
	calculator(">", "Error");
	calculator("<", "Error");
	calculator(" ", "Error");
	calculator("  ", "Error");
	calculator("", "Error");
	calculator("\b", "Error");
	calculator("\t", "Error");
	calculator("\n", "Error");
	calculator("\v", "Error");
	calculator("\f", "Error");
	calculator("\r", "Error");

	header("Basic tests");

	calculator("0 0 /", "Error");
	calculator("3 4 +", 7);
	calculator("3 5 6 + *", 33);
	calculator("3 10 5 + *", 5);
	calculator("12 * 2 / 5 + 46 * 6 / 8 * 2 / + 2 * 2 -", 42);
	calculator("99 3 -4 + 2 - 6 + -2 +", -3);
	calculator("123 + -2 3 * 7 + -4 +", -13);
	calculator("4 12 -764 + 23 * 23 1 -", 2);
	calculator("3 -4 5 + -", Error);

	header("Subject tests");

	calculator("8 9 * 9 - 9 - 9 - 4 - 1 +", "42");
	calculator("7 7 * 7 -", "42");
	calculator("1 2 * 2 / 2 * 2 4 - +", "0");
	calculator("(1 + 1)", Error);
	calculator("(1 2 + 1)", "1");
	calculator("1 + (2 + 1)", Error);

	header("Subject tests with a twist");

	calculator("1 + 0 6 9 3 + -11 * / * 17 + 5 +", Error);
	calculator("10 6 9 3 + -11 * / * 17 + 5 +", "13");
	calculator("2 1 + 3 *", "9");
	calculator("21 +3*", "9");
	calculator("4135/+", "1");
	calculator("4 13 5 / +", "1");

	header("Eval");

	calculator("8 9 * 9 - 9 - 9 - 4 - 1 +", "42");
	calculator("9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -", "42");
	calculator("1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /", "15");

}

void	header(const char * stuff)
{
	if (stuff)
		std::cout << CYAN nl << "::: " << stuff << " :::" << nl2reset;
}


//to_string not include in c++98
template<typename T>
std::string to_string(const T & value)
{
	std::ostringstream	oss;

	oss << value;
	return (oss.str());
}



