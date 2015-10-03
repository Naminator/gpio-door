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

        if ( name == "." || name == ".." )
        {
            continue;
        }

        dirlist.push_back(name);
        entry = readdir(dir);
    }

    closedir(dir);
    return dirlist;
}
