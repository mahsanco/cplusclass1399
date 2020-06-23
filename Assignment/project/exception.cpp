#include "exception.h"

const char* SocketCreationError::what() const noexcept
{
	return "Socket creation error\n";
}

const char* InvalidAddress::what() const noexcept
{
	return "Invalid address / Address not supported\n";
}

const char* ConnectionFailed::what() const noexcept
{
	return "Connection Failed\n";
}

const char* BindFailed::what() const noexcept
{
	return "Bind Failed\n";
}

const char* ListenFailed::what() const noexcept
{
	return "Listen Failed\n";
}

const char* AcceptFailed::what() const noexcept
{
	return "Accept Failed\n";
}
