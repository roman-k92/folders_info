#include "../include/ProcessingIni.h"


ProcessingIniFile::ProcessingIniFile():
    m_iniFileName("path_settings.ini")
{
    if (!boost::filesystem::exists(m_iniFileName))
    {
        boost::filesystem::path inPath = boost::filesystem::current_path();

        std::cout << "Can't find " << m_iniFileName << std::endl;
        std::cout << "Set default path " << inPath << std::endl;

        pt.put("root1", inPath);

        boost::property_tree::ini_parser::write_ini(m_iniFileName, pt);
    }        
}

std::vector<std::string> ProcessingIniFile::ReadIniFile()
{    
    std::cout << "Start reading ini" << std::endl;
    
    std::vector<std::string> pathStorage;
    boost::property_tree::ini_parser::read_ini(m_iniFileName, pt);

    for (auto& section : pt)
    {
        std::cout << '[' << section.first << "]\n";
        for (auto& key : section.second)
        {
             pathStorage.push_back(key.second.get_value<std::string>());
        }
    }

    return pathStorage;
}
