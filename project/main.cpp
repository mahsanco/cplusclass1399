#include "data_receiver.h"
#include "data_sender.h"
#include "file_type.h"
#include "composer.h"
#include "encryption.h"
#include <iostream>
int main()
{
    int way ;
    std::cin>>way ;
    if(way)
    {
        std::string sending=file_type::vector_of_files_to_string(
            file_type::files_of_a_path(
                boost::filesystem::path("/home/amirreza/Desktop/sajad_project/cplusclass1399/.git/logs/refs")
                )
            ) ;
        data_sender send_for_now("127.0.0.1",8888) ;
        std::string compressed_str=compress::compressor(encryption::encrypt(sending)) ;
        send_for_now.sender(compressed_str) ;
    }
    else
    {
        boost::filesystem::path new_pa=("/home/amirreza/Desktop/sajad_project/cplusclass1399/project/biggy") ;
        data_receiver as(8888) ;
        while(true)
        {
            data_receiver::get_stack_use_safe().lock() ;
            if(!data_receiver::get_data_received().empty())
            {
                std::pair<std::string,std::string> last_one=data_receiver::get_data_received().top() ;
                data_receiver::get_data_received().pop() ;
                std::cout<<last_one.first<<std::endl ;

                std::string decompressed_str=compress::decompress(last_one.second) ;
                std::string decrypted_str=encryption::decrypt(decompressed_str) ;
                std::vector<file_type> receiving=file_type::string_to_vector_of_files(decrypted_str) ;
                int c=0 ;
                for (file_type f:receiving)
                {
                    std::cout<<c++<<":\n" ;
                    std::cout<<f.get_path().string()<<"\n" ;
                    std::cout<<f.get_data()<<"\n" ;
                    std::cout<<f.get_size()<<"\n" ;
        
                }
                file_type::output_files(receiving[0].get_path(),new_pa,receiving) ;
            }
            data_receiver::get_stack_use_safe().unlock() ;
            
        }
    }
    //data_receiver as(8888) ;
    
}
