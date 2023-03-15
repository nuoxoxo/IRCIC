#include "iostream"
#include "sstream"
#include "deque"
#include "RPN.hpp"

//#include "cassert"
//#include "string" // std::to_string

using	namespace std;

string	calc(string);
bool	isnumeric(string);
void	test(string, string);


// drive

int	main(int c, char **v)
{
	if (c == 2)
	{
		test(v[1], "");
		return 0;
	}
	test("8 9 * 9 - 9 - 9 - 4 - 1 +", "42");
	test("7 7 * 7 -", "42");
	test("(1 + 1)", "Error");
	test("10 6 9 3 + -11 * / * 17 + 5 +", "22");

	test("3 4 +", "7");
	test("3 5 6 + *", "33");
	test("3 10 5 + *", "45");
}


// helpers

void	test(string expr, string compare)
{
	string	res = calc(expr);

	cout
	<< "expression: "
	<< YELLOW << expr << nlreset
	<< "result: "
	<< GREEN << calc(expr) << nlreset;

	if (compare != "")
	{
		assert(res == compare);
	}

}

string	calc(string line)
{
	deque<string>	E;
	string		s;
	stringstream	ss(line);
	while (!ss.eof() && ss >> s)
	{
		if (s == "+" || s == "-" || s == "*" || s == "/")
		{
			int	r = 0, l = 0;
			if (E.size())
			{
				stringstream(E.back()) >> r;
				E.pop_back();
			}
			if (E.size())
			{
				stringstream(E.back()) >> l;
				E.pop_back();
			}
			if (s == "+")
				E.push_back(to_string(l + r));
			else if (s == "-")
				E.push_back(to_string(l - r));
			else if (s == "*")
				E.push_back(to_string(l * r));
			else if (s == "/")
				E.push_back(to_string(l / r));
		}
		else if ( ! isnumeric(s))
		{
			if ((s[0] == '+' || s[0] == '-')
			&& isnumeric(s.substr(1)))
				E.push_back(s.substr(1));
			else
				return "Error";
		}
		else if (isnumeric(s))
			E.push_back(s);
	}
	return E.back();
}

bool	isnumeric(string s)
{
	size_t	i = -1;
	while (++i < s.length())
	{
		if (s[i] < '0' || s[i] > '9')
			return false;
	}
	return true;
}
