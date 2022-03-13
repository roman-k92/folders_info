#include <iostream>
#include <string>
#include <boost/filesystem.hpp>
#include "../include/Writer.h"

class FileFinder
{
    private:
        boost::filesystem::path m_rootFolder;        
        Writer *objWrite;

    public:
        FileFinder(boost::filesystem::path rootFolder = boost::filesystem::current_path());
        void ReadAllFiles();    
};