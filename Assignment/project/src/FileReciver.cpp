#include "FileReciver.hpp"

FileReciver::FileReciver() 
{}

std::string FileReciver::return_file_name()
{
	return "result_" + file_name;
}

void FileReciver::recive_file_name()
{
	try
	{	
		file_name = get_name_from_socket();
	}

	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
}

void FileReciver::recive_file_data()
{
	try
	{	
		file_data = get_data_from_socket();
		save_on_server();
	}

	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
}

void FileReciver::save_on_server()
{
	std::ofstream outfile("result.txt", std::ios::binary);

    for (int i = 0; i < file_data.size(); i++)
    {
        outfile << file_data[i] << std::endl;
    }
}