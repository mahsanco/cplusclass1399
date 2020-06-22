#include "Exceptions.hpp"

SocketFailed::SocketFailed()
{
	message = SOCKET_CREATION_FAILED;
}

const char *SocketFailed::what() const throw()
{
	return message.c_str();
}


AddressFailed::AddressFailed()
{
	message = ADDRESS_FAILED;
}

const char *AddressFailed::what() const throw()
{
	return message.c_str();
}


ConnectionFailed::ConnectionFailed()
{
	message = CONNECTION_FAILED;
}

const char *ConnectionFailed::what() const throw()
{
	return message.c_str();
}


SetSockOptFailed::SetSockOptFailed()
{
	message = SET_SOCK_OPT;
}

const char *SetSockOptFailed::what() const throw()
{
	return message.c_str();
}


BindFailed::BindFailed()
{
	message = BIND_FAILED;
}

const char *BindFailed::what() const throw()
{
	return message.c_str();
}

ListenFailed::ListenFailed()
{
	message = LISTEN_FAILED;
}

const char *ListenFailed::what() const throw()
{
	return message.c_str();
}