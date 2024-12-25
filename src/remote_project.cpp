#include <format>

#include "remote_project.hpp"

RemoteProject::RemoteProject(const std::string& serverName, const std::string& path) : Project(
    path.substr(path.find_last_of('/') + 1),
    serverName,
    std::format("vscode-remote://ssh-remote+{}/{}", serverName, path)
) {}
