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

auto Project::getScore(const std::vector<std::string>& keywords) const -> int {
    auto score = 0;
    for (const auto& keyword : keywords) {
        if (boost::contains(serverName, keyword)) {
            score += 3;
            continue;
        }
        if (boost::contains(path, keyword)) {
            score += 2;
            continue;
        }
        if (boost::contains(projectName, keyword)) {
            score += 1;
            continue;
        }
    }
    return score;
}
