#include "../include/Writer.h"

Writer::Writer(const std::string fileName, const std::string fileExt):
    m_fileName(fileName),
    m_fileExt(fileExt)
    
{    
    m_fileName += m_fileExt;

    std::cout << "File is " << m_fileName << std::endl;
    
    m_Outfile.open(m_fileName);
}
Writer::~Writer()
{
    m_Outfile.close();
}

void Writer::Write(std::string line)
{
    m_Outfile << line << std::endl;
}