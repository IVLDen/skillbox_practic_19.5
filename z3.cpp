#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>


int extract_sum (std::string buf)
{
    int found = 0;
    std::string tmp  = "";

    std::stringstream ss (buf);

    while (!ss.eof())
    {
        ss >> tmp;

        if (std::stringstream(tmp)  >> found)
            return found;
    }

    return found;
}

int main ()
{
    
    int sum;
    int max_sum = 0;
    int res_sum = 0;
    
    
    std::ifstream table;
    table.open ("D:\\projects\\practic_19.5\\zadanie3.txt");
    std::string buffer;

    while (table.tellg() >= 0)
    {
        
        getline (table, buffer);
        std::cout << buffer << std::endl ;
        
        sum = extract_sum (buffer);
        res_sum += sum;

        if (sum > max_sum)
            max_sum = sum;
        
    }
    
    table.close();

    std::cout << "\n\nSumary result: "<< res_sum << "\n";
    std::cout << "Max sum: "<< max_sum << "\n";
}
