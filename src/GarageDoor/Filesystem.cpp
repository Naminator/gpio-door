#include "GarageDoor/Filesystem.h"

std::vector<std::string> GarageDoor::Filesystem::ListDirectory(tstring path)
{
    std::vector<std::string> dirlist;

    DIR * dir = opendir(path.c_str());
    struct dirent * entry = readdir(dir);

    while (entry != NULL)
    {
        std::stringstream ss;
        ss << entry->d_name;
        std::string name = ss.str();

        if ( name != "." && name != ".." )
        {
            dirlist.push_back(name);
        }

        entry = readdir(dir);
    }

    closedir(dir);
    return dirlist;
}

tstring GarageDoor::Filesystem::ReadFile(tstring path)
{
    std::ifstream file(path);
    std::stringstream buffer;
    buffer << file.rdbuf();

    return buffer.str();
}

void GarageDoor::Filesystem::WriteFile(tstring path, tstring contents)
{
    std::ofstream file(path);
    if (!file)
    {
        std::cerr << "Cannot open the output file." << std::endl;
        return;
    }

    file << contents;
    file.close();
}
