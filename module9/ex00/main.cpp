#include "iostream"
#include "fstream"
#include "sstream"
#include "cstdio"
#include "BitcoinExchange.hpp"
#include "map"

#define COLOR YELLOW

template < typename T >
	std::string to_string(const T &);

bool	_check_params_(int, char **);
void	printerr(std::string s = "");
bool	date_is_valid(std::string &);
bool	query_is_valid(std::string &);
bool	title_is_valid(std::string &);
bool	isnumeric(std::string &);
bool	number_check(std::string &);

int	main(int c, char **v)
{
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string	file;
	std::string	s;
	std::string	title;
	bool		title_checked = false;

	if (!_check_params_(c, v))
		return (printerr("could not open file."), 1);
	file = std::string(v[1]);
	if (ifs.is_open())
		ifs.close();
	ifs.open(file.c_str());
	if (ifs.fail())
		return (printerr(), 1);
	while (!ifs.eof() && getline(ifs, s))
	{
		if ( ! title_checked && title_is_valid(s))
		{
			title_checked = true;
			continue ;
		}
		else if ( ! query_is_valid(s))
		{
			printerr("bad input => " + s);
		}
		else if ( ! number_check(s))
		{
			;;
		}
		else
		{
			std::cout << /* YELLOW << */ s << nlreset;
		}
	}
}


//	helpers :: to be put in hpp

template<typename T>
std::string to_string(const T & value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

bool	number_check(std::string & s)
{
	std::string	number;

	if (!query_is_valid(s))
		return (false);
	number = s.substr(13, (int) s.length() - 13);

	std::stringstream	ssf(number);
	std::stringstream	ssi(number);
	float			f;
	long long		i;

	ssf >> std::noskipws >> f;
	ssi >> std::noskipws >> i;
	if ((!ssf.eof() || ssf.fail()) && (!ssi.eof() || ssi.fail()))
	{
		printerr("not a number.");
	}
	// debugger
	// std::cout << f << " :: " << i << nl;
	if (f < 0 || i < 0)
	{
		printerr("not a positive number.");
		return (false);
	}
	else if (i > 2147483647)
	{
		printerr("too large a number.");
		return (false);
	}
	return (true);
}

bool	query_is_valid(std::string & s)
{
	std::string	date;
	std::string	number;

	if ((int) s.length() < 14)
		return (false);
	if (s[10] != ' ' && s[11] != '|' && s[12] != ' ')
		return (false);
	date = s.substr(0, 10);
	if ( ! date_is_valid(date))
		return (false);
	return (true);
}

bool	title_is_valid(std::string & s)
{
	std::string	title;

	if ((int) s.length() > 12)
	{
		title = s.substr(0, 12);
		if (title != "date | value")
			return (false);
	}
	return (true);
}

bool	date_is_valid(std::string & s)
{
	std::string	s1, s2, s3;
	char		hyp1, hyp2;
	int		year, month, day;

	// length-10 check
	if ((int) s.length() ^ 10)
		return (false);

	// hyphens '-'
	hyp1 = s[4];
	hyp2 = s[7];
	if (hyp1 != '-' || hyp2 != '-')
		return (false);

	// year
	s1 = s.substr(0, 4);
	if (!isnumeric(s1))
		return (false);

	// month
	s2 = s.substr(5, 2);
	if (s2[0] != '0' && s2[0] != '1')
		return (false);
	if (s2[0] == '0' && s2[1] == '0')
		return (false);
	if (s2[0] == '1' && s2[1] != '0' && s2[1] != '1' && s2[1] != '2')
		return (false);

	// day
	s3 = s.substr(8, 2);
	if (!isnumeric(s3))
		return (false);
	std::stringstream(s3) >> day;
	if (day < 1 || day > 31)
		return (false);

	// valid date check
	int	months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	std::stringstream(s1) >> year;
	std::stringstream(s2) >> month;
	if (!(year % 400) || (year % 100 && ! (year % 4)))
		months[1] = 29;
	if (day > months[month])
		return (false);

	return (true);
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

bool	_check_params_(int c, char *v[])
{
	std::string	filename;

	if (c ^ 2)
		return (printerr(), false);
	filename = std::string(v[1]);
	if (filename == "")
		return (printerr(), false);
	return true;
}

void	printerr(std::string msg)
{
	std::cerr << "Error";
	if (msg != "")
		std::cerr << ": " << COLOR << msg;
	std::cerr << nlreset;
}

