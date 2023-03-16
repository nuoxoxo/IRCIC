#include "iostream"
#include "sstream"
#include "stack"
#include "RPN.hpp"

#include "cassert"
//#include "string" // std::to_string

using	namespace std;

string	calc(string);
bool	isnumeric(string);
void	test(string, string);
string	convert(string);


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
	test("10 6 9 3 + -11 * / * 17 + 5 +", "13"); // gfg
	test("1 + 0 6 9 3 + -11 * / * 17 + 5 +", "Error");

	test("3 4 +", "7");
	test("3 5 6 + *", "33");
	test("3 10 5 + *", "5");
	test("12 * 2 / 5 + 46 * 6 / 8 * 2 / + 2 * 2 -", "42");
	test("99 3 -4 + 2 - 6 + -2 +", "-3");
	test("123 + -2 3 * 7 + -4 +", "-13");
	test("4 12 -764 + 23 * 23 1 -", "2");
	test("3 -4 5 + -", "Error");
}


// helpers

void	test(string e, string compare)
{

	string	expr = convert(e);
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

string	convert(string s)
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

string	calc(string line)
{
	stack<string>	E;
	string		s;
	stringstream	ss(line);
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
				return "Error";
			if (E.size())
			{
				stringstream(E.top()) >> r;
				E.pop();
			}
			if (!E.size())
				return "Error";
			if (E.size())
			{
				stringstream(E.top()) >> l;
				E.pop();
			}

			// dbg
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
		else if ( ! isnumeric(s))
		{
			if ((s[0] == '+' || s[0] == '-')
			&& isnumeric(s.substr(1)))
				E.push(s.substr(1));
			else
				return "Error";
		}
		else if (isnumeric(s))
		{
			E.push(s);
		}
		/*
		{
			long long ll;
			stringstream(s) >> ll;
			if (ll < -2147483648)
				return "Error";
			if (ll > 9)
			{
				stack<int>	temp1;
				while (ll)
				{
					int n = ll % 10;
					ll /= 10;
					temp1.push(n);
				}
				while (!temp1.empty())
				{
					int n = temp1.top();
					temp1.pop();
					E.push(to_string(n));
				}
			}
			else
			{
				E.push(s);
			}
		}
		*/
	}
	return (E.top());
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
