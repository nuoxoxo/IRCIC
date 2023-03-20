#include "iostream"
#include "BitcoinExchange.hpp"

int	main(int c, char **v)
{
	std::map<std::string, double>::iterator	it;
	std::map<std::string, double>		dict;
	std::ifstream		ifs;
	std::ofstream		ofs;
	std::string		input, data, line, s;

	if (!_check_params_(c, v))
	{
		return (printerr("could not open file."), 1);
	}


	// open data.csv //

	data = "data.csv"; // Eval
	data = "assets/data.csv"; // Play

	if (ifs.is_open())
		ifs.close();
	ifs.open(data.c_str());
	if (ifs.fail())
	{
		return (printerr("could not open file."), 1);
	}


	// read data //

	if (!ifs.eof())
		getline(ifs, line); // jettison the headline
	while (!ifs.eof() && getline(ifs, line))
	{
		std::string	L, R;

		L = line.substr(0, line.find(","));
		R = line.substr(line.find(",") + 1);
		dict[L] = atof(R.c_str());
	}


	// open input.txt //

	input = std::string(v[1]);
	if (ifs.is_open())
		ifs.close();
	ifs.open(input.c_str());
	if (ifs.fail())
	{
		return (printerr("could not open file."), 1);
	}


	// read input

	if (!ifs.eof())
		getline(ifs, line); // jettison the headline
	while (!ifs.eof() && getline(ifs, line))
	{
		s = remove_whitesp(line); // s is a string out of spaces
		if ( !query_is_valid(s))
		{
			printerr("bad input => " + line /* original line */);
			continue ;
		}
		if ( !number_check(s))
		{
			continue ;
		}
		std::string	key = s.substr(0, s.find("|"));
		std::string	valstr = s.substr(s.find("|") + 1);
		double		val = atof(valstr.c_str());
		if (dict.count(key))
		{
			val = to_double_round_2(dict[key] * val);
			s = to_string(val);
			if (s[s.length() - 1] == '0') // it end is 0, dont't show it
			{
				s = s.substr(0, s.length() - 1);
			}
			std::cout << key << " => " << valstr << " = " YELLOW;
			if (s.find("+") == std::string::npos) // scientific notation not found
			{
				std::cout << s << nlreset;
				continue ;
			}
			std::cout
			<< std::setprecision(PRECISION) << val
			<< nlreset;
		}
		else
		{
			it = dict.upper_bound(key);
			if (it == dict.begin())
			{
				std::cout << key << " => " << valstr << " = 0" nl;
				continue ;
			}
			it--;
			val = to_double_round_2(it->second * val);
			s = to_string(val);
			if (s[s.length() - 1] == '0') // dont't show the ending '0'
			{
				s = s.substr(0, s.length() - 1);
			}
			std::cout << key << " => " << valstr << " = " YELLOW;
			if (s.find("+") == std::string::npos)
			{
				std::cout << s << nlreset;
				continue ;
			}
			std::cout
			<< std::setprecision(PRECISION) << val
			<< nlreset;
		}
	}

}

