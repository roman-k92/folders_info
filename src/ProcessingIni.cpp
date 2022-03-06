#include "../include/ProcessingIni.h"


ProcessingIniFile::ProcessingIniFile()    
{
    m_iniFileName = "path_settings.ini";
}

void ProcessingIniFile::ReadIniFile()
{
    if (!boost::filesystem::exists(m_iniFileName))
    {
        std::cout << "Can't find " << m_iniFileName << std::endl;
        std::cout << "Set default path C: and D:" << std::endl;
        
        pt.put("root1", "C:\\");        
        pt.put("root2", "D:\\");
        boost::property_tree::ini_parser::write_ini(m_iniFileName, pt);
    }    
    else
    {        
        boost::property_tree::ini_parser::read_ini(m_iniFileName, pt);
        
        //BOOST_FOREACH(pt, pt.get_child(m_iniFileName))
        {
            //std::cout << pt.f << std::endl;
        }        
        
        

    }
}
