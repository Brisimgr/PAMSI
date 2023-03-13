#ifndef FILEFUNCTIONS_HH
#define FILEFUNCTIONS_HH

#include<fstream>

template<typename T> 
T readFile(std::ifstream* myFile)
{
    T number = 0;
    *myFile >> number;
    return number;
}

void generateFile(std::ofstream* myFile, int howMany)
{
    int random = 0;

    for(int i = 0; i < howMany; ++i)
    {
        random = rand() % 100;
        *myFile << random;
        if(i != (howMany - 1))
            *myFile << "\n";
    }
}


#endif