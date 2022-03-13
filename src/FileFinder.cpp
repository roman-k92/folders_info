#include "../include/FileFinder.h"

FileFinder::FileFinder(boost::filesystem::path rootFolder):
    m_rootFolder(rootFolder)
{
    std::cout << "Input path is " << m_rootFolder << std::endl;

    const std::string fileName = m_rootFolder.filename().string();
    const std::string fileExt = ".csv";
    objWrite = new Writer(fileName, fileExt);
}

void FileFinder::ReadAllFiles()
{    
    int cnt = 0;
    boost::filesystem::recursive_directory_iterator it{m_rootFolder};
    while (it != boost::filesystem::recursive_directory_iterator{})
    {
        if (cnt % 500 == 0)
        {
            std::cout << cnt << std::endl;
        }

        std::string fileName = it->path().string();
        //std::cout << fileName << "\n";
        objWrite->Write(fileName);
        it++;
        cnt++;
    }

    std::cout << cnt << std::endl;
}