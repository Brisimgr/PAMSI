#include "../inc/linkedList.hh"
#include"../inc/fileFunctions.hh"
#include"../inc/stack.hpp"

#include<fstream>
#include<chrono>

int main()
{
    LinkedList<int>* list = new LinkedList<int>();
    Stack<int>* stos = new Stack<int>(); 

    std::ifstream myFileRead;
    std::ofstream myFileWrite;
    
    myFileWrite.open("test.txt");
    if(myFileWrite.is_open())
        generateFile(&myFileWrite, 10);
    
    myFileWrite.close();
    
    myFileRead.open("test.txt");

    int number;

    auto begin = std::chrono::high_resolution_clock::now();

    if(myFileRead.is_open())
    {
        while(myFileRead.good() == true)
        {
            number = readFile<int>(&myFileRead);
            list->addAtTail(number);
            stos->push(number);
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    std::cout << "Time: " << elapsed.count() << "ms" << std::endl;

    myFileRead.close();

    list->display();

    delete(list);
    int cos = stos->top();

    std::cout << cos << std::endl;

    delete(stos);

    return 0;
}