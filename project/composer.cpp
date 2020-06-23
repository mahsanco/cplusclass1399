#include "composer.h"
std::string compress::compressor(std::string input)
{
    std::string return_value="" ;
    char a=input[0] ;
    int t=1 ;
    for(size_t i=1;i<input.size();i++)
        if(a==input[i] && t<200)
            t++ ;
        else
        {
            return_value+=a ;
            return_value+=(char)t ;
            a=input[i] ;
            t=1 ;
        }

    return_value+=a ;
    return_value+=(char)t ;
    if(return_value.size()>input.size()) 
        return input+"0" ;
    return return_value+"1" ;
}

std::string compress::decompress(std::string input) 
{
    if(input[input.size()-1]=='0') ;
    {
        input.pop_back() ;
        return input ;
    }    
    input.pop_back() ;
    std::string return_value="" ;
    for(size_t i=0;i<input.size();i+=2)
    {
        char a=input[i] ;
        int b=(int)input[i+1] ;
        for(int j=0;j<b;j++)
            return_value+=a ;
    }
    return return_value ;
}
