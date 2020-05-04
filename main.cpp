#include <iostream>
#include "operation.h"



int main()
{
    const std::string fileNames[6] = {"fsp/data001.txt", "fsp/data002.txt", "fsp/data003.txt", "fsp/data004.txt", "fsp/data005.txt", "fsp/data006.txt" };
    
    Operation data;
    data.getDataFromFile(fileNames[0]);
    data.showOperation();
}
