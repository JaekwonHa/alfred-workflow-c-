#include "local_project.hpp"

LocalProject::LocalProject(const std::string& serverName, const std::string& path) : Project(
    path.substr(path.find_last_of('/') + 1),
    serverName,
    path
) {}
