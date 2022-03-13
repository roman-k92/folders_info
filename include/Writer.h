#include <iostream>
#include <string>
#include <fstream>

class Writer
{
    private:
        std::string m_fileExt, m_fileName;
        std::ofstream m_Outfile;
        

    public:
        Writer(const std::string fileName, const std::string fileExt);
        ~Writer();
        void Write(std::string line);
};