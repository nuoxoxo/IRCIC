#include "iostream"
#include "BitcoinExchange.hpp"




int	main(int c, char **v)
{
	bool			title_checked = false;
	std::ifstream		ifs;
	std::ofstream		ofs;
	std::string		input, data;
	std::string		s, res;
	std::map<std::string, float>	dict;

	// std::string	L, R;

	if (!_check_params_(c, v))
		return (printerr("could not open input."), 1);


	// open data.csv
	data = "data.csv";
	if (ifs.is_open())
		ifs.close();
	ifs.open(data.c_str());
	if (ifs.fail())
		return (printerr(), 1);

	getline(ifs, s); // jettison the headline
	while (!ifs.eof() && getline(ifs, s))
	{
		std::string L = s.substr(0, s.find(","));
		std::string R = s.substr(s.find(",") + 1);

		dict[L] = atof(R.c_str());
	}


	// open input.txt
	input = std::string(v[1]);
	if (ifs.is_open())
		ifs.close();
	ifs.open(input.c_str());
	if (ifs.fail())
		return (printerr(), 1);


	// read input
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
			std::string	key = s.substr(0, s.find(" | "));
			std::string	valstr = s.substr(s.find(" | ") + 3);
			float		val = atof(valstr.c_str());

			if (dict.count(key))
			{
				res = to_string(to_float_round_2(dict[key] * val));
				float R = to_float_round_2(dict[key] * val);
				if (res[res.length() - 1] == '0')
					res = res.substr(0, res.length() - 1);

				std::cout << key << " => " << valstr << " = " YELLOW;
				if (res.find("+") != std::string::npos)
					std::cout << "(1) "<<std::setprecision(2) << R << std::defaultfloat << nlreset;
				else
					std::cout << res << nlreset;
			}
			else
			{
				std::map<std::string, float>::iterator it = dict.upper_bound(key);

				if (it == dict.begin())
				{
					std::cout << key << " => " << valstr << " = 0" nl;
				}
				else
				{
					it--;
					float R = to_float_round_2(it->second * val);
					res = to_string(to_float_round_2(it->second * val));
					if (res[res.length() - 1] == '0')
						res = res.substr(0, res.length() - 1);

					std::cout << key << " => " << valstr << " = " YELLOW;
					if (res.find("+") != std::string::npos)
						std::cout << "(2) "<<std::setprecision(2) << R << std::defaultfloat << nlreset;
					else
						std::cout << res << nlreset;

				}

			}
		}
	}

}

