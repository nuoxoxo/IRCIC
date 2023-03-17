#include "iostream"
#include "sstream"
#include "stack"
#include "RPN.hpp"

#include "cassert"
#define Error "Error"

using	namespace std;

bool	isnumeric(string &);
void	test(string, string);
string	calc(string);
string	to_space_separated_string(string &);

template <typename T>
string	to_string(const T &);

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

	test("(1 + 1)", Error);
	test("10 6 9 3 + -11 * / * 17 + 5 +", "13"); // gfg
	test("1 + 0 6 9 3 + -11 * / * 17 + 5 +", Error);

	test("3 4 +", "7");
	test("3 5 6 + *", "33");
	test("3 10 5 + *", "5");
	test("12 * 2 / 5 + 46 * 6 / 8 * 2 / + 2 * 2 -", "42");
	test("99 3 -4 + 2 - 6 + -2 +", "-3");
	test("123 + -2 3 * 7 + -4 +", "-13");
	test("4 12 -764 + 23 * 23 1 -", "2");
	test("3 -4 5 + -", Error);

}


// helpers

void	test(string e, string compare)
{

	string	res = calc(e);

	cout
	<< "expression: "
	<< YELLOW << e << nlreset
	<< "result: "
	<< GREEN << calc(e) << nlreset;

	if (compare != "")
	{
		assert(res == compare);
	}
}


string	calc(string line)
{
	stack<string>	E;
	string		s;
	string		expr = to_space_separated_string(line);
	stringstream	ss(expr);

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
			if (E.size())
			{
				stringstream(E.top()) >> r;
				E.pop();
			}
			if (!E.size())
				return Error;
			if (E.size())
			{
				stringstream(E.top()) >> l;
				E.pop();
			}

			// dbg (to keep)
			// cout << l << " . " << r << " . " << s << nl;

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


string	to_space_separated_string(string& s)
{
	string	r;

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
string to_string(const T & value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

bool	isnumeric(string & s)
{
	size_t	i = -1;
	while (++i < s.length())
	{
		if (s[i] < '0' || s[i] > '9')
			return false;
	}
	return true;
}
