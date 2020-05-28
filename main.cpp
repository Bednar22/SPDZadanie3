#include <iostream>
#include "operation.h"
#include <ctime>
#include "time.h"
#include <chrono>




int main()
{
    const std::string fileNames[6] = {"fsp/data001.txt", "fsp/data002.txt", "fsp/data003.txt", "fsp/data004.txt", "fsp/data005.txt", "fsp/data006.txt" };
    
    int minI, minJ;
    Operation data, testop;
    Result result,result1;
    data.getDataFromFile(fileNames[4]);
    data.showOperation();
    
    std::cout << "*************************************************************" << std::endl;
    result.Cmax(data);
    result.timeJohnson(data);
    //result1.timeBruteForce(data);
    std::cout << std::endl << result.result << std::endl;
    // std::cout << "Bruteforce" << std::endl;
    // result.BruteForce(data);
    // result.outcome.showOperation();
    // std::cout << std::endl << "Bruteforce Cmax:" <<result.result << std::endl;


    

}
