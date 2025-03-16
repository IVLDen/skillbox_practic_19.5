#include <iostream>
#include <fstream>


int main () 
{
    std::string file_path;
    std::ifstream png_check;
    bool opened = false;
    bool is_png = false;

    while (!opened)
    {
        std::cout << "Input file's path or enter 'exit': \n";
        std::getline (std::cin, file_path);

        if (file_path == "exit")
            return 0;

        png_check.open (file_path, std::ios::binary);

        if (png_check.is_open())
            opened = true;
        
        else 
            std::cout <<"File not found \n";
        
    }

    if (file_path.substr(file_path.length() - 3, 3) != "png")
        is_png = true;

    char heading [5];
    
    png_check.read (heading, 4);

    if ( (heading[0] < 0 || heading[0] > 255) && (heading[1] == 'P') && (heading[2] == 'N') && (heading[3] == 'G') )
        is_png = true;

    else is_png = false;

    png_check.close();

    if (is_png)
    {
        std::cout << "This is a PNG-file \n";
        return 0;
    }
    
    else
    {
        std::cout << "This is not a PNG-file \n";
        return 0;
    }

    

}