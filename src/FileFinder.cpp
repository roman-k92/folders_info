#include "../include/FileFinder.h"

FileFinder::FileFinder(boost::filesystem::path rootFolder):
    m_rootFolder(rootFolder)
{
    std::cout << "Input path is" << m_rootFolder << std::endl;
}

void FileFinder::ReadAllFiles()
{    
    boost::filesystem::recursive_directory_iterator it{m_rootFolder};
    while (it != boost::filesystem::recursive_directory_iterator{})
    {
        std::cout << *it++ << '\n';    
    }
}