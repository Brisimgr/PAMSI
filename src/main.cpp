#include "../inc/linkedList.hh"
#include"../inc/fileFunctions.hh"
#include"../inc/stack.hpp"
#include"../inc/table.hh"

#include<fstream>
#include<chrono>

int main()
{
    LinkedList<int>* list = new LinkedList<int>();
    Stack<int>* stos = new Stack<int>(); 
    Table<int>* tablica = new Table<int>();

    std::ifstream myFileRead;
    std::ofstream myFileWrite;
    
    myFileWrite.open("test.txt");
    if(myFileWrite.is_open())
        generateFile(&myFileWrite, 10000);
    
    myFileWrite.close();
    
    myFileRead.open("test.txt");

    int number;

    auto begin = std::chrono::high_resolution_clock::now();

    if(myFileRead.is_open())
    {
        while(myFileRead.good() == true)
        {
            number = readFile<int>(&myFileRead);
            list->addAtHead(number);
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    std::cout << "Time list: " << elapsed.count() << "ns" << std::endl;

    number = 0;

    auto begin2 = std::chrono::high_resolution_clock::now();

    if(myFileRead.is_open())
    {
        while(myFileRead.good() == true)
        {
            number = readFile<int>(&myFileRead);
            stos->push(number);
        }
    }

    auto end2 = std::chrono::high_resolution_clock::now();
    auto elapsed2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);

    std::cout << "Time stos: " << elapsed2.count() << "ns" << std::endl;

    auto begin3 = std::chrono::high_resolution_clock::now();

    if(myFileRead.is_open())
    {
        while(myFileRead.good() == true)
        {
            number = readFile<int>(&myFileRead);
            tablica->push_back(number);
        }
    }

    auto end3 = std::chrono::high_resolution_clock::now();
    auto elapsed3 = std::chrono::duration_cast<std::chrono::nanoseconds>(end3 - begin3);

    std::cout << "Time tablica: " << elapsed3.count() << "ns" << std::endl;

    myFileRead.close();

    delete(list);

    delete(stos);

    delete(tablica);

    return 0;
}