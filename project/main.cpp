#include "data_receiver.h"
#include "data_sender.h"
#include "file_type.h"
#include "composer.h"
#include "encryption.h"
#include <iostream>
/**
 * TODO:
 * If user entered 0 
 * Go to server mode otherwise goto client mode 
 * Server mode:
 * Download all input datas into /home/sajad_download
 * First decompress data and the decrypte it
 * CLient mode:
 * Get directory and host 
 * then send the directory 
 * First encrypt data and then compress it
 */
int main()
{
    int way ;
    std::cout<<"for server mod enter 0 else 1\n" ;
    std::cin>>way ;
    if(way)
    {
        while(true)
        {
            std::string directory ;
            std::string host ;
            std::cout<<"enter directory like /home/amirreza/Desktop/sajad_project/cplusclass1399/.git/logs/refs \n" ;
            std::cin>>directory ;
            std::cout<<"enter host like 127.0.0.1 \n" ;
            std::cin>>host  ;
            std::string sending=file_type::vector_of_files_to_string(
                file_type::files_of_a_path(
                      boost::filesystem::path(directory)
                    )
                ) ;
            data_sender send_for_now(host.c_str(),9888) ;
            std::string compressed_str=compress::compressor(encryption::encrypt(sending)) ;
            send_for_now.sender(compressed_str) ;
    
        }
    }
    else
    {
        boost::filesystem::path new_pa=("/home/sajad_download") ;
        data_receiver as(9888) ;
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
                

                file_type::output_files(receiving[0].get_path(),new_pa,receiving) ;
                std::cout<<"downloaded in /home/sajad_download\n\n" ;
            }
            data_receiver::get_stack_use_safe().unlock() ;
            
        }
    }
    //data_receiver as(8888) ;
    
}
