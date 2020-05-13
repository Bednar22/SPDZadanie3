#include <iostream>
#include "operation.h"



int main()
{
    const std::string fileNames[6] = {"fsp/data001.txt", "fsp/data002.txt", "fsp/data003.txt", "fsp/data004.txt", "fsp/data005.txt", "fsp/data006.txt" };
    
    Operation data;
    Result result;
    data.getDataFromFile(fileNames[2]);
    data.showOperation();
    result.Cmax(data);
    std::cout << std::endl << result.result << std::endl;
    std::cout << "Bruteforce" << std::endl;
    result.BruteForce(data);
    result.outcome.showOperation();
    std::cout << std::endl << "Bruteforce Cmax:" <<result.result << std::endl;

}
