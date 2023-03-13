#include "../inc/linkedList.hh"
#include"../inc/fileFunctions.hh"

#include<fstream>
#include<chrono>

int main()
{
    LinkedList<int>* list = new LinkedList<int>();

    std::ifstream myFileRead;
    std::ofstream myFileWrite;
    
    myFileWrite.open("../test.txt");
    if(myFileWrite.is_open())
        generateFile(&myFileWrite, 1000);
    
    myFileWrite.close();
    
    myFileRead.open("../test.txt");

    int number;

    auto begin = std::chrono::high_resolution_clock::now();

    if(myFileRead.is_open())
    {
        while(myFileRead.good() == true)
        {
            number = readFile<int>(&myFileRead);
            list->addAtTail(number);
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    std::cout << "Time: " << elapsed.count() << "ms" << std::endl;

    myFileRead.close();

    delete(list);

    //list->display();

    return 0;
}