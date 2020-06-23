#ifndef _FILE_TYPE_H_
#define _FILE_TYPE_H_

#include <string>
#include <boost/filesystem.hpp>
#include <vector>
class file_type
{
	private :
	
        ///Path of file
		boost::filesystem::path path ;

        ///Data of file 
        std::string data ;

        ///Size of file
        int size ;		
         
    public:
	
		/*
		 * @param is path of file
		 */
		file_type(boost::filesystem::path path ) ;
        
        file_type(boost::filesystem::path path,std::string data,int size ):path(path),data(data),size(size){ } 

		/*
		 * @return data of file
		 */
		std::string const& get_data() ;
		
		/*
		 * @return path of file
		 */
		boost::filesystem::path const& get_path() ;
		
		/*
		 * @return size of file
		 */
        int get_size();
        
        /*
         * @param is path of file
         * @return all files in that directory
         */
        static std::vector<file_type> files_of_a_path(boost::filesystem::path path) ;
        
        /*
         * Serialization
         * @param is vector of file_type objects
         * @return a string that represent the parameter
         */
        static std::string vector_of_files_to_string(std::vector<file_type> vector_of_files) ; 

        /*
         * DeSerialization
         * @param a string that is contain data
         * @return a vector of file_type
         */
        static std::vector<file_type> string_to_vector_of_files(std::string data) ;

        
        /*
         * String to int
         * @param string 
         * @param index :from where
         * @return the number
         * index will change to the next place
         * for DeSerialization function
         */
        static int string_to_int(const std::string&  str, int &index) ;
         
        /*
         * output the received files 
         * @ param inner_path is path of original directory
         * @ param out_path is path of new directory
         * @ param vector_of_files 
         */
        static void output_files(boost::filesystem::path inner_path , boost::filesystem::path out_path,std::vector<file_type> vector_of_files) ;

            
};

#endif
