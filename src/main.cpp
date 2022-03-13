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
            ProcessingIniFile *obj = new ProcessingIniFile();
            std::vector<std::string> pathStorage = obj->ReadIniFile();

            std::vector<std::string>::iterator iter = pathStorage.begin();
            while(iter != pathStorage.end()) 
            {
                std::cout << "Returned path " << *iter++ << std::endl;
            }
            
            delete obj;
        }
        else if (inputNum == 2)
        {
            std::cout << "get files info" << std::endl;
            std::cout << "type 'c' and press Enter to skip" << std::endl;
            std::cout << "type 'd' and press Enter to set default path (current folder)" << std::endl;

            boost::filesystem::path inPath;
            std::cin >> inPath;

            FileFinder *obj;

            if (inPath == "c")
            {
                continue;
            }
            else if (inPath == "d")
            {
                obj = new FileFinder();
            }
            else
            {
                obj = new FileFinder(inPath);
            }

            obj->ReadAllFiles();
            delete obj;            
        }
        else
        {
            std::cout << "waiting" << std::endl;
            sleep(1);
        }

        
        
    }

    return 0;
}