#ifndef _EXCEPTIONS_
#define _EXCEPTIONS_

#include <exception>

class CONNECTION_FAILED: public std::exception
{
    virtual const char* what() const throw()
    {
        return "Failed to connect to the server";
    }
};

class SENDING_FAILED: public std::exception
{
    virtual const char* what() const throw()    
    {
        return "Failed to send data to the server";
    }
};

class STARTING_FAILED: public std::exception
{
    virtual const char* what() const throw()    
    {
        return "Failed to start the server";
    }
};

class SAVING_FAILED: public std::exception
{
    virtual const char* what() const throw()    
    {
        return "Failed to save file on server";
    }
};
#endif