#include "FileSender.hpp"

FileSender::FileSender() 
{}


void FileSender::get_file_name_input()
{
	std::cout << "Please enter the file name :" << std::endl;
    std::cin >> file_name;
	send_name_to_server();
}


std::string FileSender::return_file_name()
{
    return file_name;
}


void FileSender::read_file_data() 
{
	std::string buffer;

	std::ifstream infile(file_name, std::ios::binary);

	while (getline(infile, buffer))
	{
		send_data_to_server(buffer);
	}
	send_data_to_server("\0");
}

void FileSender::send_file_name() 
{
	try
	{			
		get_file_name_input();
	}

	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
}

void FileSender::send_file_data() 
{
	try
	{			
		read_file_data();
	}

	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
}