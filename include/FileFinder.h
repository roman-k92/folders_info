#include <iostream>
#include <boost/filesystem.hpp>
#include <string>

class FileFinder
{
    private:
        boost::filesystem::path m_rootFolder;        
        

    public:
        FileFinder(boost::filesystem::path rootFolder = boost::filesystem::current_path());
        void ReadAllFiles();    
};