#include "../include/FileFinder.h"
#include <boost/thread/thread.hpp>
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
            //std::cout << cnt << std::endl;
        }

        std::string fileInfo = "\"" + it->path().string() + "\"";
        if (boost::filesystem::is_regular_file(it->path()))
        {            
            int size = boost::filesystem::file_size(it->path());
            fileInfo += "," + std::to_string(size);
        }
        
        int sec = 1 + rand() % 7;
        boost::this_thread::sleep( boost::posix_time::seconds(sec) );
        objWrite->Write(fileInfo);
        
        it++;
        cnt++;
    }

    std::cout << cnt << std::endl;
}