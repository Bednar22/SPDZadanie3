#include <iostream>
#include "operation.h"



int main()
{
    const std::string fileNames[6] = {"fsp/data001.txt", "fsp/data002.txt", "fsp/data003.txt", "fsp/data004.txt", "fsp/data005.txt", "fsp/data006.txt" };
    
    int minI, minJ;
    Operation data, testop;
    Result result,testres;
    data.getDataFromFile(fileNames[0]);
    data.showOperation();
    std::cout << "*************************************************************" << std::endl;
    //result.Cmax(data);
    //NAPRAWIC JHONSONA
    result.Johnson(data);
    //std::cout << std::endl << result.result << std::endl;
    //std::cout << "Bruteforce" << stSd::endl;
    //result.BruteForce(data);
    //result.outcome.showOperation();
    //std::cout << std::endl << "Bruteforce Cmax:" <<result.result << std::endl;


    

}
