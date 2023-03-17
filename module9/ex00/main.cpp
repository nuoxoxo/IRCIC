#include "iostream"
#include "BitcoinExchange.hpp"




int	main(int c, char **v)
{
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		input, data;
	std::string		s, res;
	bool		title_checked = false;
	std::map<std::string, float>	dict;

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
		dict[s.substr(0, s.find(","))] = atof((s.substr(s.find(",") + 1)).c_str());
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
			float		val = atof(s.substr(s.find(" | ") + 3).c_str());

			if (dict.count(key))
			{
				res = to_string(to_float_round_2(dict[key] * val));
				if (res[res.length() - 1] == '0')
					res = res.substr(0, res.length() - 1);

				std::cout
				<< key << " => "
				<< val << " = "
				<< YELLOW << res << nlreset;
			}
			else
			{
				std::map<std::string, float>::iterator it = dict.upper_bound(key);

				if (it == dict.begin())
				{
					std::cout << key << " => " << val << " = 0" nl;
				}
				else
				{
					it--;
					res = to_string(to_float_round_2(it->second * val));
					if (res[res.length() - 1] == '0')
						res = res.substr(0, res.length() - 1);

					std::cout
					<< key << " => "
					<< val << " = "
					<< YELLOW << res << nlreset;
				}

			}
		}
	}

}

