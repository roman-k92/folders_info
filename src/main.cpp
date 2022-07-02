#include <iostream>
#include <unistd.h>
#include <boost/thread.hpp>
#include "../include/ProcessingIni.h"
#include "../include/FileFinder.h"
#include "../include/CommandsAnalyser.h"

int main()
{    
    FileFinder *obj;
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
            std::cout << "type '-s' and press Enter to skip" << std::endl;
            std::cout << "type '-d' and press Enter to set default path (current folder)" << std::endl;
            std::cout << "type '-t' and press Enter to run terminal commads" << std::endl;
            std::cout << "type folder_path and press Enter to set path" << std::endl;

            boost::filesystem::path inPath;
            std::cin >> inPath;

            if (inPath == "-s")
            {
                continue;
            }
            else if (inPath == "-d")
            {
                obj = new FileFinder();
            }
            else if (inPath == "-t")
            {
                std::cout << "type -s to stop" << std::endl;
                
                char * command;
                std::cin >> command;

                if (command == "-s")
                {
                    continue;
                }

                CommandsAnalyser obj;
                obj.Run(command);
                //obj = new FileFinder(inPath);
            }

            /*boost::thread* pThread = new boost::thread(
                &FileFinder::ReadAllFiles,      // pointer to member function to execute in thread
                obj);       */ // pointer to instance of class
        }
        else
        {
            std::cout << "waiting" << std::endl;
            sleep(1);
        }
    }
    delete obj;
    
    std::cout << "finish" << std::endl;
    
    return 0;
}