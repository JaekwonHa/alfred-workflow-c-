#pragma once

#include <string>
#include <vector>
#include <memory>

class Project {
public:
    Project() = delete;
    Project(const std::string& projectName, const std::string& serverName, const std::string& path) : projectName(projectName), serverName(serverName), path(path) {}
    ~Project() = default;

    static auto create(const std::string& serverName, const std::string& path) -> std::unique_ptr<Project>;

    virtual auto isMatched(const std::vector<std::string>& keywords) const -> bool;

    const std::string projectName;
    const std::string serverName;
    const std::string path;
};
