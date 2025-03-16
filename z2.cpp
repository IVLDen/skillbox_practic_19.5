#include <iostream>
#include <fstream>
#include <string>


int main ()
{
    std::string file_path;
    std::ifstream text_view;
    bool opened = false;

    while (!opened)
    {
        std::cout << "Input file's path: \n";
        std::getline (std::cin, file_path);

        text_view.open (file_path, std::ios::binary);

        if (text_view.is_open())
            opened = true;
        
        else 
            std::cout <<"Not found \n";
        
    }
        
    int cursor_memory = 0;

    while (cursor_memory != -1)
    {
        int k = 0;
        
        for ( ; text_view.get() != '\n' && text_view.tellg() >= 0 ; )
            k += 1;
    
        
        if (text_view.tellg() < 0)
        {
            text_view.clear();
            char buf [k];
            text_view.seekg(cursor_memory);
            text_view.read(buf, sizeof(buf));
        
            for (int i = 0; i < sizeof(buf); ++i)
                std::cout << buf[i];

            cursor_memory = -1;
        }

        else
        {
            char buf [k + 1];
            text_view.seekg( cursor_memory );
            text_view.read(buf, sizeof(buf));
            
            for (int i = 0; i < sizeof(buf); ++i)
                std::cout << buf[i];
        
            cursor_memory = text_view.tellg();
        }

        
    }

    text_view.close();

}


