#include <iostream>
#include <fstream>
#include <string>

int main ()
{
    std::ifstream word;
    word.open ("D:\\projects\\practic_19.5\\bank.txt");
    

    int count = 0;
    std::string w;
    std::string w1;

    std::cout << "Input word: \n";
    std::cin >> w;

    while (!word.eof())
    {
        word >> w1;
        if (w == w1)
        {
            count += 1;
        }
    }

    word.close();
    std::cout <<"\ncount = "<<count;

    return 0;

}