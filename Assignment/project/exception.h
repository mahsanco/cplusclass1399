#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>

class SocketCreationError : public std::exception
{
public:
	const char* what() const noexcept;
};

class InvalidAddress : public std::exception
{
public:
	const char* what() const noexcept;
};

class ConnectionFailed : public std::exception
{
public:
	const char* what() const noexcept;
};

class BindFailed : public std::exception
{
public:
	const char* what() const noexcept;
};

class ListenFailed : public std::exception
{
public:
	const char* what() const noexcept;
};

class AcceptFailed : public std::exception
{
public:
	const char* what() const noexcept;
};

#endif
