#include <iostream>
#include <unistd.h>
#include "../include/ProcessingIni.h"
#include "../include/FileFinder.h"

int main()
{
    
    while(true)
    {
        int inputNum;
        std::cout << std::endl << "\t1 - get config info" << std::endl;
        std::cout << std::endl << "\t2 - run file reading" << std::endl;
        std::cout << "Input value: ";

        std::cin >> inputNum;

        if (inputNum == 1)
        {
            std::cout << "read ini" << std::endl;

            ProcessingIniFile *obj = new ProcessingIniFile();
            obj->ReadIniFile();
            delete obj;
            //sleep(1);
            break;
        }
        else if (inputNum == 2)
        {
            std::cout << "get files info" << std::endl;
            std::cout << "press Enter to skip" << std::endl;

            boost::filesystem::path inPath;
            std::cin >> inPath;

            FileFinder *obj = new FileFinder(inPath);
            obj->ReadAllFiles();
            delete obj;
            break;
        }
        else
        {
            std::cout << "waiting" << std::endl;
            sleep(1);
        }

        
        
    }

    return 0;
}

/*#include <iostream>
#include <boost/property_tree/ptree.hpp>
//#include <boost/property_tree/ini_parser.hpp>
#include <boost/filesystem.hpp>

using namespace std;
int main()
{
    boost::property_tree::ptree pt;
    //boost::property_tree::ini_parser::read_ini("config.ini", pt);

    if (!boost::filesystem::exists("config.ini"))
    {
        std::cout << "Can't" << std::endl;
    }        
    //std::cout << pt.get<std::string>("Section1.Value1") << std::endl;
    //std::cout << pt.get<std::string>("Section1.Value2") << std::endl;

    return 0;
}*/