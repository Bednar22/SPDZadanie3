#include <iostream>
#include "operation.h"
#include <ctime>
#include "time.h"
#include <chrono>




int main()
{
    const std::string fileNames[6] = {"fsp/data001.txt", "fsp/data002.txt", "fsp/data003.txt", "fsp/data004.txt", "fsp/data005.txt", "fsp/data006.txt" };
    const std::string fileNamesNEH[6] = { "fsp/ta001.txt", "fsp/ta002.txt", "fsp/ta003.txt", "fsp/ta004.txt", "fsp/ta005.txt", "fsp/ta006.txt" };
    const std::string fileNamestest[1] = { "fsp/NEH1.DAT" };
    int minI, minJ;
    Operation data, testop;
    Result result,result1;
    data.getDataFromFile(fileNamestest[0]);
    data.showOperation();
    
    std::cout << "*************************************************************" << std::endl;
  //  result.Cmax(data);
   // result.timeJohnson(data);
    //result1.timeBruteForce(data);
    //result1.BruteForce(data);
   // std::cout << std::endl << "Bruteforce Cmax:" <<result1.result << std::endl;
        // std::cout << "Bruteforce" << std::endl;
    // result.BruteForce(data);
   // result1.outcome.showOperation();
    // std::cout << std::endl << "Bruteforce Cmax:" <<result.result << std::endl;
    result.NEH(data);

    std::cout << std::endl << "NEH Cmax:" <<result.result << std::endl;
    result.outcome.showOperation();

}
