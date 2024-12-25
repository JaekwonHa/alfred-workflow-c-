#include <boost/algorithm/string.hpp>

#include "project.hpp"
#include "local_project.hpp"
#include "remote_project.hpp"

auto Project::create(const std::string& serverName, const std::string& path) -> std::unique_ptr<Project> {
    if (serverName == "local") {
        return std::make_unique<LocalProject>(serverName, path);
    } else {
        return std::make_unique<RemoteProject>(serverName, path);
    }
}

auto Project::isMatched(const std::vector<std::string>& keywords) const -> bool {
    for (const auto& keyword : keywords) {
        if (boost::contains(projectName, keyword)) {
            return true;
        }
        if (boost::contains(serverName, keyword)) {
            return true;
        }
        if (boost::contains(path, keyword)) {
            return true;
        }
    }

    return false;
}
