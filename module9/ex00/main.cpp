#include "iostream"
#include "fstream"
#include "cstdio"
#include "BitcoinExchange.hpp"
#include "map"

bool	_check_params_(int, char **);
void	_usage_(void);

int	main(int c, char **v)
{
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string	file;
	std::string	s;

	if (!_check_params_(c, v))
		return 1;
	file = std::string(v[1]);
	if (ifs.is_open())
		ifs.close();
	ifs.open(file.c_str());
	if (ifs.fail())
		return (_usage_(), 1);
	while (!ifs.eof() && getline(ifs, s))
	{
		// test print
		std::cout << YELLOW << s << nlreset;


	}


}

//	below :: to be put in hpp

bool	_check_params_(int c, char *v[])
{
	std::string	filename;

	if (c ^ 2)
		return (_usage_(), false);
	filename = std::string(v[1]);
	if (filename == "")
		return (_usage_(), false);
	return true;
}

void	_usage_(void)
{
	std::cerr << "Error: could not open file. \n";
}
