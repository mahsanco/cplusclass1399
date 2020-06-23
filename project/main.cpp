#include "data_receiver.h"
#include "data_sender.h"
#include "file_type.h"
#include <iostream>
int main()
{
    int way ;
    std::cin>>way ;
    if(way)
    {
        boost::filesystem::path pa=("/home/amirreza/Desktop/sajad_project/cplusclass1399/.git/logs/refs") ;
        std::string sending=file_type::vector_of_files_to_string(
            file_type::files_of_a_path(
                boost::filesystem::path("/home/amirreza/Desktop/sajad_project/cplusclass1399/.git/logs/refs")
                )
            ) ;
        data_sender send_for_now("127.0.0.1",8888) ;
        send_for_now.sender(sending) ;
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
                std::vector<file_type> receiving=file_type::string_to_vector_of_files(last_one.second) ;
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
