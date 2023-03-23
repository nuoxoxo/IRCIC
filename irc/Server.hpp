#pragma once

#include "Fmt.hpp"

class	IRCServer
{
	const	std::string	m_port;
	const	std::string	m_pass;
	const	std::string	m_name;

public:
	std::string	get_port() const { return (m_port);}

	std::string	get_name() const
	{
		return (m_name);
	}
};



