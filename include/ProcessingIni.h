#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>
#include <string>

class ProcessingIniFile
{
    private:
        boost::property_tree::ptree pt;
        std::string m_iniFileName;
        

    public:
        void ReadIniFile();
        ProcessingIniFile();

    
};