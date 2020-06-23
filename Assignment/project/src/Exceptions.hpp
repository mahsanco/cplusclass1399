#ifndef _EXCEPTIONS_
#define _EXCEPTIONS_

#include <string>
#include <exception>

#define SOCKET_CREATION_FAILED "Socket creation failed"
#define ADDRESS_FAILED "Invalid address/ Address not supported"
#define CONNECTION_FAILED "Connection failed"
#define SET_SOCK_OPT "Set sock opt failed"
#define BIND_FAILED "Bind failed"
#define LISTEN_FAILED "Listen failed"


class SocketFailed : public std::exception
{
private:

	std::string message;

public:

	SocketFailed();
	const char *what() const throw();
};

class AddressFailed : public std::exception
{
private:

	std::string message;

public:

	AddressFailed();
	const char *what() const throw();
};

class ConnectionFailed : public std::exception
{
private:

	std::string message;

public:

	ConnectionFailed();
	const char *what() const throw();
};

class SetSockOptFailed : public std::exception
{
private:

	std::string message;

public:

	SetSockOptFailed();
	const char *what() const throw();
};

class BindFailed : public std::exception
{
private:

	std::string message;

public:

	BindFailed();
	const char *what() const throw();
};

class ListenFailed : public std::exception
{
private:

	std::string message;

public:

	ListenFailed();
	const char *what() const throw();
};


#endif