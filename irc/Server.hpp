#pragma once
#ifndef __SERVER_HPP__
# define __SERVER_HPP__
# include "Fmt.hpp"

class	IRCServer
{
	const	std::string	m_port;
	const	std::string	m_pass;
	std::string	m_name;

public:
	std::string	get_port() const { return (m_port); }
	std::string	get_name() const { return (m_name); }
	void		set_name(std::string name) { m_name = name; }
	std::string	get_pass_might_delete() const { return (m_pass); }

	IRCServer(std::string port, std::string pass)
		: m_port(port), m_pass(pass)
	{
		set_name("(anonymous server)");
	}

	~IRCServer() {}

};


#endif

