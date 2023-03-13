#include"../inc/fileFunctions.hh"

template<typename T> 
T readFile(std::ifstream* myFile)
{
    T number = 0;

    *myFile >> number;
}

template readFile<int>;