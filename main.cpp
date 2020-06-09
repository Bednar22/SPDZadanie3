#include <iostream>
#include "operation.h"
#include <ctime>
#include "time.h"
#include <chrono>




int main()
{
    const std::string fileNames[6] = {"fsp/data001.txt", "fsp/data002.txt", "fsp/data003.txt", "fsp/data004.txt", "fsp/data005.txt", "fsp/data006.txt" };
    //Removed taxxx from files
    const std::string fileNamestest1[10] = { "fsp/ta001.txt", "fsp/ta002.txt", "fsp/ta003.txt", "fsp/ta004.txt", "fsp/ta005.txt", "fsp/ta006.txt", "fsp/ta007.txt", "fsp/ta008.txt", "fsp/ta009.txt", "fsp/ta010.txt" };
    const std::string fileNamestest2[12] = {"fsp/ta005.txt", "fsp/ta015.txt","fsp/ta025.txt", "fsp/ta035.txt", "fsp/ta045.txt", "fsp/ta055.txt", "fsp/ta065.txt", "fsp/ta075.txt", "fsp/ta085.txt", "fsp/ta095.txt", "fsp/ta105.txt", "fsp/ta115.txt" };
    const std::string fileNamestest3[1] = { "fsp/NEH1.DAT" };
    int minI, minJ;
    //Operation data, testop;
    Result result,result1;
  //  data.getDataFromFile(fileNamestest1[6]);
  //  data.showOperation();
    
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
  //  result.NEH(data);
    //result.indexes();
    //std::cout << std::endl << "NEH Cmax:" <<result.result << std::endl;
    //result.outcome.showOperation();
    
    for (int i = 0; i < 12; i++)
    {
        Operation data;
        data.getDataFromFile(fileNamestest2[i]);
        result.timeNEH(data, "NEH_RESULT_02.txt");
    }
    
    std::cout << std::endl << "done";

}
